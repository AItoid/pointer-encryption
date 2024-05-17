### PointerEncryption
Simple pointer-protection to prevent easy-access of pointers.

```
v215 = v3;
  v216 = retaddr;
  v187 = v5;
  v186 = v4;
  v6 = operator new(8u);
  ThreadLocalStoragePointer = (int *)NtCurrentTeb()->ThreadLocalStoragePointer;
  v214 = (int)v6;
  v188 = -939880714;
  *v6 = 0i64;
  v8 = *ThreadLocalStoragePointer;
  v9 = dword_40749C;
  v209 = dword_40749C;
  v213 = v8;
  if ( dword_407490 > *(_DWORD *)(v8 + 4) )
  {
    sub_40359A(&dword_407490);
    if ( dword_407490 == -1 )
    {
      dword_407484 = v9;
      _Init_thread_footer(&dword_407490);
    }
  }
  v189 = dword_407484;
  v190 = -1443434558;
  if ( dword_40747C > *(_DWORD *)(v8 + 4) )
  {
    sub_40359A(&dword_40747C);
    if ( dword_40747C == -1 )
    {
      dword_407494 = (int)GetModuleHandleA(0);
      _Init_thread_footer(&dword_40747C);
    }
  }
  v191 = dword_407494;
  v192 = 1519974081;
  if ( dword_407498 > *(_DWORD *)(v8 + 4) )
  {
    sub_40359A(&dword_407498);
    if ( dword_407498 == -1 )
    {
      dword_407480 = (int)NtCurrentPeb();
      _Init_thread_footer(&dword_407498);
    }
  }
  v193 = dword_407480;
  v194 = 1822383754;
  v195 = -80169101;
  if ( dword_40747C > *(_DWORD *)(v8 + 4) )
  {
    sub_40359A(&dword_40747C);
    if ( dword_40747C == -1 )
    {
      dword_407494 = (int)GetModuleHandleA(0);
      _Init_thread_footer(&dword_40747C);
    }
  }
  v210 = dword_407494;
  if ( dword_407498 > *(_DWORD *)(v8 + 4) )
  {
    sub_40359A(&dword_407498);
    if ( dword_407498 == -1 )
    {
      dword_407480 = (int)NtCurrentPeb();
      _Init_thread_footer(&dword_407498);
    }
  }
  v196 = dword_407480 ^ v210;
  v197 = 1377228170;
  v198 = -320927439;
  v199 = 1571159279;
  if ( dword_407490 > *(_DWORD *)(v8 + 4) )
  {
    sub_40359A(&dword_407490);
    if ( dword_407490 == -1 )
    {
      dword_407484 = v209;
      _Init_thread_footer(&dword_407490);
    }
  }
  v210 = dword_407484;
  if ( dword_40747C > *(_DWORD *)(v8 + 4) )
  {
    sub_40359A(&dword_40747C);
    if ( dword_40747C == -1 )
    {
      dword_407494 = (int)GetModuleHandleA(0);
      _Init_thread_footer(&dword_40747C);
    }
  }
  v200 = dword_407494 ^ v210;
  v201 = -1783827699;
  v202 = 774692834;
  v203 = -2108785708;
  if ( dword_407490 > *(_DWORD *)(v8 + 4) )
  {
    sub_40359A(&dword_407490);
    if ( dword_407490 == -1 )
    {
      dword_407484 = v209;
      _Init_thread_footer(&dword_407490);
    }
  }
  v10 = dword_407484;
  if ( dword_407498 > *(_DWORD *)(v8 + 4) )
  {
    sub_40359A(&dword_407498);
    if ( dword_407498 == -1 )
    {
      dword_407480 = (int)NtCurrentPeb();
      _Init_thread_footer(&dword_407498);
    }
  }
  v204 = dword_407480 ^ v10;
  v11 = 0;
  v205 = 1299201132;
  v212 = 0;
  if ( dword_407474 < 2 )
    goto LABEL_32;
  v12 = (__m128i)xmmword_405290;
  v13 = (__m128i)xmmword_405200;
  v206 = 0i64;
  do
  {
    v14 = (__m128)v13;
    v15 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(v11), 0), (__m128i)xmmword_405210);
    v16 = _mm_add_epi32(v13, v15);
    v17 = (__m128)_mm_cmpgt_epi32((__m128i)0i64, v15);
    v18 = _mm_srai_epi32(_mm_add_epi32((__m128i)_mm_and_ps(v14, v17), v15), 1u);
    v19 = _mm_andnot_ps((__m128)_mm_sub_epi32(v15, _mm_add_epi32(v18, v18)), (__m128)xmmword_405320);
    v20 = _mm_add_epi32(
            (__m128i)_mm_xor_ps(
                       _mm_or_ps(
                         _mm_xor_ps((__m128)_mm_srai_epi32(_mm_mullo_epi32(v16, v16), 0xCu), v19),
                         (__m128)xmmword_405260),
                       *(__m128 *)(&v188 + v11)),
            (__m128i)_mm_xor_ps((__m128)_mm_add_epi32(_mm_mullo_epi32(v15, v12), v12), (__m128)xmmword_4052E0));
    v21 = (__m128i)_mm_shuffle_ps(
                     (__m128)_mm_mul_epi32(_mm_unpacklo_epi32(v15, v15), (__m128i)xmmword_4052F0),
                     (__m128)_mm_mul_epi32(_mm_unpackhi_epi32(v15, v15), (__m128i)xmmword_4052F0),
                     221);
    v22 = _mm_mullo_epi32(v15, v15);
    v23 = _mm_mullo_epi32(
            _mm_add_epi32((__m128i)xmmword_405280, v22),
            _mm_sub_epi32(
              _mm_slli_epi32(v20, 0xCu),
              (__m128i)_mm_or_ps(
                         _mm_xor_ps((__m128)_mm_mullo_epi32((__m128i)v19, v16), (__m128)xmmword_4052A0),
                         (__m128)xmmword_405240)));
    v24 = (__m128)_mm_slli_epi32(
                    _mm_sub_epi32(
                      _mm_mullo_epi32(
                        (__m128i)_mm_or_ps(
                                   _mm_xor_ps(
                                     _mm_andnot_ps(
                                       (__m128)_mm_sub_epi32(
                                                 v15,
                                                 _mm_slli_epi32(
                                                   _mm_srai_epi32(
                                                     _mm_add_epi32(
                                                       (__m128i)_mm_and_ps((__m128)xmmword_405220, v17),
                                                       v15),
                                                     2u),
                                                   2u)),
                                       (__m128)xmmword_405320),
                                     (__m128)_mm_srai_epi32(
                                               _mm_mullo_epi32(
                                                 _mm_add_epi32((__m128i)xmmword_405250, v15),
                                                 _mm_add_epi32((__m128i)xmmword_405240, v15)),
                                               0x1Fu)),
                                   (__m128)xmmword_405240),
                        _mm_srli_epi32(
                          (__m128i)_mm_xor_ps((__m128)_mm_add_epi32(v23, v23), (__m128)xmmword_405300),
                          0xCu)),
                      (__m128i)_mm_xor_ps((__m128)_mm_mullo_epi32(v15, (__m128i)xmmword_4052B0), (__m128)xmmword_4052D0)),
                    0xAu);
    v25 = _mm_or_ps(
            _mm_xor_ps(
              (__m128)_mm_mullo_epi32(
                        (__m128i)_mm_andnot_ps(
                                   (__m128)_mm_sub_epi32(
                                             v15,
                                             _mm_mullo_epi32(
                                               _mm_add_epi32(_mm_srli_epi32(v21, 0x1Fu), v21),
                                               (__m128i)xmmword_405220)),
                                   (__m128)xmmword_405320),
                        _mm_add_epi32((__m128i)xmmword_405230, v15)),
              (__m128)xmmword_4052C0),
            (__m128)xmmword_405250);
    v12 = (__m128i)xmmword_405290;
    v26 = _mm_add_epi32(
            _mm_mullo_epi32(
              _mm_add_epi32(_mm_add_epi32(v22, v22), (__m128i)xmmword_405270),
              (__m128i)_mm_xor_ps(v24, v25)),
            (__m128i)xmmword_405310);
    v13 = (__m128i)xmmword_405200;
    v27 = (__m128)_mm_srli_epi32(v26, 0xFu);
    *(__m128 *)(&v188 + v11) = v27;
    v11 += 4;
    v28 = _mm_xor_ps(v27, v206);
    v206 = v28;
  }
  while ( v11 < 0x10 );
  v212 = v11;
  v29 = _mm_xor_ps(v28, (__m128)_mm_srli_si128((__m128i)v28, 8));
  v30 = v214 ^ _mm_cvtsi128_si32((__m128i)_mm_xor_ps(v29, (__m128)_mm_srli_si128((__m128i)v29, 4)));
  v214 = v30;
  if ( v11 < 0x12 )
  {
LABEL_32:
    v210 = 92728 * v11;
    v211 = 3178 * (v11 + 1);
    do
    {
      v31 = v11 + 1;
      v209 = v11 + 1;
      v32 = v11 * v11;
      v208 = (int)(&v188 + v11);
      v33 = (((2
             * (v11 * v11 + 949)
             * ((((v211 ^ 0xFFFF6A9F) + (*(_DWORD *)v208 ^ (~((int)v11 % 2) ^ ((int)(v31 * v31) >> 12) | 0xF))) << 12)
              - ((v31 * ~((int)v11 % 2)) ^ 0x7F90 | 0xA))) >> 2) ^ 0xE879ABFF) & 0x3FFFFC00;
      v34 = v210 ^ 0xA5E89F;
      v210 += 92728;
      v35 = v209;
      v36 = ((2 * v32 + 207)
           * ((((v209 + 3) * ~(v212 % 3)) ^ 0xC63E2 | 0xC) ^ ((~(v212 % 4) ^ ((int)((v31 + 9) * (v31 + 11)) >> 31) | 0xA)
                                                            * v33
                                                            - (v34 << 10)))
           - 1050764689) >> 15;
      *(_DWORD *)v208 = v36;
      v30 = v36 ^ v214;
      v11 = v35;
      v214 = v30;
      v212 = v35;
      v211 += 3178;
    }
    while ( v211 < 0xEBDE );
    v8 = v213;
  }
  ```
