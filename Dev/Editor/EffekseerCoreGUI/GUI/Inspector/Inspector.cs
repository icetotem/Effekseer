using System;
using System.Collections;
using System.Collections.Generic;
using System.Reflection;
using System.IO;
using System.Linq;
using Effekseer.GUI.BindableComponent;

namespace Effekseer.GUI.Inspector
{
	public class InspectorPanel : Dock.DockPanel
	{
		InspectorEditable target;

		EditorState editorState;
		NodeTreeGroupContext context;

		public InspectorPanel()
		{
			Label = "Inspector###Inspector";

			editorState = new EditorState();

			editorState.Env = new Environment();
			editorState.PartsList = new PartsList();
			editorState.PartsList.Renew();

			context = new NodeTreeGroupContext();
			context.New(typeof(InspectorEditable), editorState);

			// Force select
			editorState.SelectedNode = context.NodeTree.Root as InspectorEditable;
			target = editorState.SelectedNode as InspectorEditable;
		}

		protected override void UpdateInternal()
		{
			context.CommandManager.StartEditFields(context.NodeTreeGroup, context.NodeTree, editorState.SelectedNode, editorState.Env);

			Inspector.Update(context, editorState, target);

			context.CommandManager.EndEditFields(editorState.SelectedNode, editorState.Env);

			// Fix edited results when values are not edited
			if (!Manager.NativeManager.IsAnyItemActive())
			{
				context.CommandManager.SetFlagToBlockMergeCommands();
			}
		}
	}


	class InspectorGuiInfo
	{
		public InspectorGuiInfo()
		{
			Id = new string("###" + Manager.GetUniqueID().ToString());
		}

		public string Id { get; private set; } = "";

		// フィールドが配列などであったとき、その各要素について格納する
		public List<InspectorGuiInfo> subElement = new List<InspectorGuiInfo>();
	}

	class Inspector
	{
		// Gui表示を登録する
		private static readonly InspectorGuiDictionary GuiDictionary = new InspectorGuiDictionary();
		
		private static List<InspectorGuiInfo> FieldGuiInfoList = new List<InspectorGuiInfo>();

		private static InspectorEditable LastTarget = null;

		private static void GenerateFieldGuiIds(InspectorEditable target)
		{
			if (FieldGuiInfoList == null)
			{
				FieldGuiInfoList = new List<InspectorGuiInfo>();
			}
			FieldGuiInfoList.Clear();

			var fields = target.GetType().GetFields();
			foreach (var field in fields)
			{
				FieldGuiInfoList.Add(new InspectorGuiInfo());
			}
		}

		public static void Update(NodeTreeGroupContext context, EditorState editorState, InspectorEditable target)
		{
			var commandManager = context.CommandManager;
			var nodeTreeGroup = context.NodeTreeGroup;
			var nodeTree = context.NodeTree;
			var partsList = editorState.PartsList;
			var env = editorState.Env;
			var nodeTreeGroupEditorProperty = context.EditorProperty;

			var getterSetters = new FieldGetterSetter[1];
			getterSetters[0] = new FieldGetterSetter();

			// エディタに表示する変数群
			var fields = target.GetType().GetFields();

			// Generate field GUI IDs when target is selected or changed.
			// TODO : 複数ターゲットに対応できていない
			if ((LastTarget == null && target != null) || (target.InstanceID != LastTarget.InstanceID))
			{
				GenerateFieldGuiIds(target);
			}
			LastTarget = target;


			for (int i = 0; i < fields.Length; ++i)
			{
				var field = fields[i];

				getterSetters[0].Reset(target, field);
				var prop = context.EditorProperty.Properties.FirstOrDefault(_ => _.InstanceID == target.InstanceID);
				bool isValueChanged = false;
				if (prop != null)
				{
					// 配列の変更が取れないのは別インスタンスに上書きされてるから？
					// 配列のコピーではなく、配列の要素のコピーにすべき
					isValueChanged = prop.IsValueEdited(getterSetters.Select(_ => _.GetName()).ToArray());
				}

				var getterSetter = getterSetters.Last();
				var value = getterSetter.GetValue();
				var name = getterSetter.GetName();

				if (value == null)
				{
					// TODO : nullどうする？
					Manager.NativeManager.Text("null : " + field.GetType().ToString());
					continue;
				}

				if (isValueChanged)
				{
					name = "*" + name;
				}
				else
				{
					name = " " + name;
				}

				// 配列かリストの時、エレメントの型を取得する
				var valueType = value.GetType();
				bool isArray = valueType.IsArray;
				if (isArray)
				{
					valueType = valueType.GetElementType();
				}
				else if (valueType.IsGenericType && valueType.GetGenericTypeDefinition() == typeof(List<>))
				{
					valueType = valueType.GetGenericArguments()[0];
				}

				// TODO : 基底クラスNodeのpublic List<Node> Children = new List<Node>();が反応してる
				if (GuiDictionary.HasFunction(valueType))
				{
					var func = GuiDictionary.GetFunction(valueType);

					if (isArray)
					{
						Array arrayValue = (Array)value;

						// GuiIdが足りなければ、すべて再生成
						// GenerateFieldGuiIdsの中でやりたいが、型情報からは要素数が分からないのでここで生成。
						if (arrayValue.GetLength(0) > FieldGuiInfoList[i].subElement.Count())
						{
							FieldGuiInfoList[i].subElement.Clear();

							foreach (var v in arrayValue)
							{
								FieldGuiInfoList[i].subElement.Add(new InspectorGuiInfo());
							}
						}

						int j = 0;
						bool isEdited = false;
						foreach (var v in arrayValue)
						{
							name += FieldGuiInfoList[i].subElement[j].Id;
							var result = func(v, name);
							if (result.isEdited)
							{
								if (valueType.IsValueType)
								{
									arrayValue.SetValue(result.value, j);
								}
								isEdited = true;
							}
							++j;
						}
						if (isEdited)
						{
							field.SetValue(target, arrayValue);
							context.CommandManager.NotifyEditFields(target);
						}
					}
					else
					{
						name += FieldGuiInfoList[i].Id;
						var result = func(value, name);
						if (result.isEdited)
						{
							field.SetValue(target, result.value);
							context.CommandManager.NotifyEditFields(target);
						}
					}
				}
				else
				{
					Manager.NativeManager.Text("No Regist : " + value.GetType().ToString() + " " + name);
				}
			}
		}
	}

	class InspectorEditable : Node
	{
		public int Int1 = 0;
		public float Float1 = 0.0f;
		public string String1 = "text";

		// 配列
		// 配列を関数側で対応するのか、呼び出し側でどうにかするのか
		// 試した感じ呼び出し側で制御した方が楽そう
		public int[] IntArray = new int[2];
		public float[] FloatArray = new float[2];
		public string[] StringArray = new string[2] { "hoge", "fuga" };

		// 全てのコレクションに対しプログラムをする方法なかったっけ
		// TODO : List
		public List<int> ListInt1 = new List<int>{ 2, 3 };

		// TODO : Vector
		public Vector2D vector2 = new Vector2D();
		public Vector3D vector3 = new Vector3D();
		public Vector3D[] vector3Array = new Vector3D[2] { new Vector3D(), new Vector3D() };

		// TODO : string等、nullをどう扱うか
		public string String2;

		// TODO : 特殊な型
		Gradient Gradient1 = new Gradient();
		Dock.FCurves FCurves = new Dock.FCurves();

	}
}
