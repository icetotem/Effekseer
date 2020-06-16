#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /Zpc /Tps_4_0 /EPS /D __EFFEKSEER_BUILD_VERSION16__=1 /Fh
//    Shader/EffekseerRenderer.Standard_PS.h Shader/standard_renderer_PS.fx
//
//
// Buffer Definitions: 
//
// cbuffer PS_ConstanBuffer
// {
//
//   float4 flipbookParameter;          // Offset:    0 Size:    16
//   float4 uvDistortionParameter;      // Offset:   16 Size:    16
//   float4 blendTextureParameter;      // Offset:   32 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// g_sampler                         sampler      NA          NA    0        1
// g_alphaSampler                    sampler      NA          NA    1        1
// g_uvDistortionSampler             sampler      NA          NA    2        1
// g_blendSampler                    sampler      NA          NA    3        1
// g_texture                         texture  float4          2d    0        1
// g_alphaTexture                    texture  float4          2d    1        1
// g_uvDistortionTexture             texture  float4          2d    2        1
// g_blendTexture                    texture  float4          2d    3        1
// PS_ConstanBuffer                  cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float       
// COLOR                    0   xyzw        1     NONE  float   xyzw
// TEXCOORD                 0   xy          2     NONE  float   xy  
// TEXCOORD                 4     zw        2     NONE  float     zw
// TEXCOORD                 1   xyzw        3     NONE  float       
// TEXCOORD                 2   xyzw        4     NONE  float       
// TEXCOORD                 3   xyzw        5     NONE  float       
// TEXCOORD                 5   xy          6     NONE  float   xy  
// TEXCOORD                 6     zw        6     NONE  float     zw
// TEXCOORD                 7   x           7     NONE  float   x   
// TEXCOORD                 8    yz         7     NONE  float    yz 
// TEXCOORD                 9      w        7     NONE  float      w
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Target                0   xyzw        0   TARGET  float   xyzw
//
ps_4_0
dcl_constantbuffer cb0[3], immediateIndexed
dcl_sampler s0, mode_default
dcl_sampler s1, mode_default
dcl_sampler s2, mode_default
dcl_sampler s3, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t1
dcl_resource_texture2d (float,float,float,float) t2
dcl_resource_texture2d (float,float,float,float) t3
dcl_input_ps linear v1.xyzw
dcl_input_ps linear v2.xy
dcl_input_ps linear v2.zw
dcl_input_ps linear v6.xy
dcl_input_ps linear v6.zw
dcl_input_ps linear v7.x
dcl_input_ps linear v7.yz
dcl_input_ps linear v7.w
dcl_output o0.xyzw
dcl_temps 6
sample r0.xyzw, v6.xyxx, t2.xyzw, s2
mad r0.xy, r0.xyxx, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
mad r1.xyzw, r0.xyxy, cb0[1].xxxx, v2.xyzw
sample r2.xyzw, r1.xyxx, t0.xyzw, s0
mul r2.xyzw, r2.xyzw, v1.xyzw
lt r0.z, l(0.000000), cb0[0].x
if_nz r0.z
  mad r0.xy, r0.xyxx, cb0[1].xxxx, v7.yzyy
  sample r0.xyzw, r0.xyxx, t0.xyzw, s0
  eq r1.x, cb0[0].y, l(1.000000)
  mad r0.xyzw, r0.xyzw, v1.xyzw, -r2.xyzw
  mad r0.xyzw, v7.xxxx, r0.xyzw, r2.xyzw
  movc r2.xyzw, r1.xxxx, r0.xyzw, r2.xyzw
endif 
sample r0.xyzw, r1.zwzz, t1.xyzw, s1
mul r0.x, r0.w, r2.w
ge r0.y, v7.w, r0.x
discard r0.y
eq r0.y, r0.x, l(0.000000)
discard r0.y
sample r1.xyzw, v6.zwzz, t3.xyzw, s3
mul r0.yzw, r1.xxyz, r1.wwww
add r2.w, -r1.w, l(1.000000)
mad r3.xyz, r2.wwww, r2.xyzx, r0.yzwy
mad r4.xyz, r1.wwww, r1.xyzx, r2.xyzx
mad r1.xyz, -r1.wwww, r1.xyzx, r2.xyzx
eq r5.xyzw, cb0[2].xxxx, l(0.000000, 1.000000, 2.000000, 3.000000)
mul r0.yzw, r0.yyzw, r2.xxyz
movc r0.yzw, r5.wwww, r0.yyzw, r2.xxyz
movc r0.yzw, r5.zzzz, r1.xxyz, r0.yyzw
movc r0.yzw, r5.yyyy, r4.xxyz, r0.yyzw
movc o0.xyz, r5.xxxx, r3.xyzx, r0.yzwy
mov o0.w, r0.x
ret 
// Approximately 34 instruction slots used
#endif

const BYTE g_PS[] =
{
     68,  88,  66,  67,  61, 192, 
    217, 150, 228, 195, 196, 157, 
    194,  97, 138,  77,  13, 201, 
     68, 213,   1,   0,   0,   0, 
     16,  10,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    236,   2,   0,   0,  56,   4, 
      0,   0, 108,   4,   0,   0, 
    148,   9,   0,   0,  82,  68, 
     69,  70, 176,   2,   0,   0, 
      1,   0,   0,   0, 204,   1, 
      0,   0,   9,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    255, 255,  16,   1,   0,   0, 
    124,   2,   0,   0,  60,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     70,   1,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  85,   1,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 107,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    122,   1,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0, 132,   1,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0, 147,   1, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      2,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
    169,   1,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   3,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0, 184,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 103,  95, 
    115,  97, 109, 112, 108, 101, 
    114,   0, 103,  95,  97, 108, 
    112, 104,  97,  83,  97, 109, 
    112, 108, 101, 114,   0, 103, 
     95, 117, 118,  68, 105, 115, 
    116, 111, 114, 116, 105, 111, 
    110,  83,  97, 109, 112, 108, 
    101, 114,   0, 103,  95,  98, 
    108, 101, 110, 100,  83,  97, 
    109, 112, 108, 101, 114,   0, 
    103,  95, 116, 101, 120, 116, 
    117, 114, 101,   0, 103,  95, 
     97, 108, 112, 104,  97,  84, 
    101, 120, 116, 117, 114, 101, 
      0, 103,  95, 117, 118,  68, 
    105, 115, 116, 111, 114, 116, 
    105, 111, 110,  84, 101, 120, 
    116, 117, 114, 101,   0, 103, 
     95,  98, 108, 101, 110, 100, 
     84, 101, 120, 116, 117, 114, 
    101,   0,  80,  83,  95,  67, 
    111, 110, 115, 116,  97, 110, 
     66, 117, 102, 102, 101, 114, 
      0, 171, 171, 171, 184,   1, 
      0,   0,   3,   0,   0,   0, 
    228,   1,   0,   0,  48,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  44,   2, 
      0,   0,   0,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0,  64,   2,   0,   0, 
      0,   0,   0,   0,  80,   2, 
      0,   0,  16,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0,  64,   2,   0,   0, 
      0,   0,   0,   0, 102,   2, 
      0,   0,  32,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0,  64,   2,   0,   0, 
      0,   0,   0,   0, 102, 108, 
    105, 112,  98, 111, 111, 107, 
     80,  97, 114,  97, 109, 101, 
    116, 101, 114,   0, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 117, 118, 
     68, 105, 115, 116, 111, 114, 
    116, 105, 111, 110,  80,  97, 
    114,  97, 109, 101, 116, 101, 
    114,   0,  98, 108, 101, 110, 
    100,  84, 101, 120, 116, 117, 
    114, 101,  80,  97, 114,  97, 
    109, 101, 116, 101, 114,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  57, 
     46,  50,  57,  46,  57,  53, 
     50,  46,  51,  49,  49,  49, 
      0, 171, 171, 171,  73,  83, 
     71,  78,  68,   1,   0,   0, 
     12,   0,   0,   0,   8,   0, 
      0,   0,  40,   1,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,  52,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  15,  15, 
      0,   0,  58,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   3,   3, 
      0,   0,  58,   1,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,  12,  12, 
      0,   0,  58,   1,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      3,   0,   0,   0,  15,   0, 
      0,   0,  58,   1,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      4,   0,   0,   0,  15,   0, 
      0,   0,  58,   1,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      5,   0,   0,   0,  15,   0, 
      0,   0,  58,   1,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      6,   0,   0,   0,   3,   3, 
      0,   0,  58,   1,   0,   0, 
      6,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      6,   0,   0,   0,  12,  12, 
      0,   0,  58,   1,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      7,   0,   0,   0,   1,   1, 
      0,   0,  58,   1,   0,   0, 
      8,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      7,   0,   0,   0,   6,   6, 
      0,   0,  58,   1,   0,   0, 
      9,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      7,   0,   0,   0,   8,   8, 
      0,   0,  83,  86,  95,  80, 
     79,  83,  73,  84,  73,  79, 
     78,   0,  67,  79,  76,  79, 
     82,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0, 171, 
     79,  83,  71,  78,  44,   0, 
      0,   0,   1,   0,   0,   0, 
      8,   0,   0,   0,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,  83,  86, 
     95,  84,  97, 114, 103, 101, 
    116,   0, 171, 171,  83,  72, 
     68,  82,  32,   5,   0,   0, 
     64,   0,   0,   0,  72,   1, 
      0,   0,  89,   0,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   1,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   2,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   3,   0,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   0,   0,   0,   0, 
     85,  85,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      1,   0,   0,   0,  85,  85, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   2,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   3,   0,   0,   0, 
     85,  85,   0,   0,  98,  16, 
      0,   3, 242,  16,  16,   0, 
      1,   0,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      2,   0,   0,   0,  98,  16, 
      0,   3, 194,  16,  16,   0, 
      2,   0,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      6,   0,   0,   0,  98,  16, 
      0,   3, 194,  16,  16,   0, 
      6,   0,   0,   0,  98,  16, 
      0,   3,  18,  16,  16,   0, 
      7,   0,   0,   0,  98,  16, 
      0,   3,  98,  16,  16,   0, 
      7,   0,   0,   0,  98,  16, 
      0,   3, 130,  16,  16,   0, 
      7,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      0,   0,   0,   0, 104,   0, 
      0,   2,   6,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  16,  16,   0,   6,   0, 
      0,   0,  70, 126,  16,   0, 
      2,   0,   0,   0,   0,  96, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,  15,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,  64,   0,   0, 
      0,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128, 191, 
      0,   0, 128, 191,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   4,  16,   0,   0,   0, 
      0,   0,   6, 128,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  70,  30,  16,   0, 
      2,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 126,  16,   0,   0,   0, 
      0,   0,   0,  96,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     70,  30,  16,   0,   1,   0, 
      0,   0,  49,   0,   0,   8, 
     66,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  31,   0, 
      4,   3,  42,   0,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  10,  50,   0,  16,   0, 
      0,   0,   0,   0,  70,   0, 
     16,   0,   0,   0,   0,   0, 
      6, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
    150,  21,  16,   0,   7,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  24,   0,   0,   8, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70,  30,  16,   0,   1,   0, 
      0,   0,  70,  14,  16, 128, 
     65,   0,   0,   0,   2,   0, 
      0,   0,  50,   0,   0,   9, 
    242,   0,  16,   0,   0,   0, 
      0,   0,   6,  16,  16,   0, 
      7,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  55,   0,   0,   9, 
    242,   0,  16,   0,   2,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  21,   0,   0,   1, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   0,   0,   0,   0, 
    230,  10,  16,   0,   1,   0, 
      0,   0,  70, 126,  16,   0, 
      1,   0,   0,   0,   0,  96, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      2,   0,   0,   0,  29,   0, 
      0,   7,  34,   0,  16,   0, 
      0,   0,   0,   0,  58,  16, 
     16,   0,   7,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  13,   0,   4,   3, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  24,   0,   0,   7, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     13,   0,   4,   3,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   1,   0,   0,   0, 
    230,  26,  16,   0,   6,   0, 
      0,   0,  70, 126,  16,   0, 
      3,   0,   0,   0,   0,  96, 
     16,   0,   3,   0,   0,   0, 
     56,   0,   0,   7, 226,   0, 
     16,   0,   0,   0,   0,   0, 
      6,   9,  16,   0,   1,   0, 
      0,   0, 246,  15,  16,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   8, 130,   0,  16,   0, 
      2,   0,   0,   0,  58,   0, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     50,   0,   0,   9, 114,   0, 
     16,   0,   3,   0,   0,   0, 
    246,  15,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0, 150,   7, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,   9, 114,   0, 
     16,   0,   4,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,  10, 114,   0, 
     16,   0,   1,   0,   0,   0, 
    246,  15,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  24,   0, 
      0,  11, 242,   0,  16,   0, 
      5,   0,   0,   0,   6, 128, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 128,  63,   0,   0, 
      0,  64,   0,   0,  64,  64, 
     56,   0,   0,   7, 226,   0, 
     16,   0,   0,   0,   0,   0, 
     86,  14,  16,   0,   0,   0, 
      0,   0,   6,   9,  16,   0, 
      2,   0,   0,   0,  55,   0, 
      0,   9, 226,   0,  16,   0, 
      0,   0,   0,   0, 246,  15, 
     16,   0,   5,   0,   0,   0, 
     86,  14,  16,   0,   0,   0, 
      0,   0,   6,   9,  16,   0, 
      2,   0,   0,   0,  55,   0, 
      0,   9, 226,   0,  16,   0, 
      0,   0,   0,   0, 166,  10, 
     16,   0,   5,   0,   0,   0, 
      6,   9,  16,   0,   1,   0, 
      0,   0,  86,  14,  16,   0, 
      0,   0,   0,   0,  55,   0, 
      0,   9, 226,   0,  16,   0, 
      0,   0,   0,   0,  86,   5, 
     16,   0,   5,   0,   0,   0, 
      6,   9,  16,   0,   4,   0, 
      0,   0,  86,  14,  16,   0, 
      0,   0,   0,   0,  55,   0, 
      0,   9, 114,  32,  16,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   5,   0,   0,   0, 
     70,   2,  16,   0,   3,   0, 
      0,   0, 150,   7,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5, 130,  32,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 116,   0,   0,   0, 
     34,   0,   0,   0,   6,   0, 
      0,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,  10,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0
};
