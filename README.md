### pointer-encryption
Simple pointer encryption to prevent easy-access of pointers for x64 and x86.

### Security measures
- Random keys based on RNG.
- Random keys based on build time.
- Dynamic key based on executable base address.
- Dynamic key based on PEB address.
- Dynamic key based on pointer encryption class instance.
- Inlined functions to prevent calling functions in class.

### Pseudo-code
Below is the produced pseudo-code from encrypting and decrypting a pointer in x64.
```cpp
int __fastcall main(int argc, const char **argv, const char **envp)
{
  unsigned __int64 v3; // r13
  __int64 v4; // rdi
  _DWORD *v5; // r15
  __int64 v6; // rbx
  __int64 v7; // rbx
  __int64 v8; // rbx
  int v9; // esi
  int v10; // ebx
  __int64 v11; // r12
  __int64 *v12; // r14
  int v13; // r11d
  unsigned int *v14; // rdi
  unsigned int i; // ebx
  unsigned int v16; // eax
  unsigned __int64 j; // rdx
  unsigned int v18; // r8d
  unsigned int v19; // edx
  unsigned int v20; // eax
  unsigned int v21; // r9d
  unsigned __int64 v22; // r8
  unsigned __int64 v23; // r13
  __int64 v24; // rdi
  __int64 v25; // rbx
  __int64 v26; // rbx
  __int64 v27; // rbx
  int v28; // esi
  int v29; // r11d
  __int64 v30; // r12
  __int64 *v31; // r14
  int v32; // r13d
  unsigned int v33; // ebx
  unsigned int *v34; // rdi
  unsigned int v35; // eax
  unsigned __int64 k; // rcx
  unsigned int v37; // r8d
  unsigned int v38; // edx
  unsigned int v39; // eax
  unsigned int v40; // r9d
  unsigned __int64 v41; // r8
  const void *v42; // rdx
  __int64 v44[18]; // [rsp+20h] [rbp-E0h] BYREF
  __int64 v45[24]; // [rsp+B0h] [rbp-50h] BYREF
  int v46; // [rsp+180h] [rbp+80h]
  int v47; // [rsp+180h] [rbp+80h]
  int v48; // [rsp+188h] [rbp+88h]
  unsigned __int64 v49; // [rsp+188h] [rbp+88h]
  _DWORD *v50; // [rsp+190h] [rbp+90h]

  v3 = (unsigned __int64)operator new(4ui64);
  *(_DWORD *)v3 = 0;
  v4 = qword_140007B30;
  v44[0] = 3355086582i64;
  v5 = (_DWORD *)(*(_QWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + 4i64);
  v50 = v5;
  if ( dword_140007B28 > *v5 )
  {
    Init_thread_header(&dword_140007B28);
    if ( dword_140007B28 == -1 )
    {
      qword_140006778 = v4;
      Init_thread_footer(&dword_140007B28);
    }
  }
  v44[1] = qword_140006778;
  v44[2] = 2851533045i64;
  if ( dword_140007B38 > *v5 )
  {
    Init_thread_header(&dword_140007B38);
    if ( dword_140007B38 == -1 )
    {
      qword_140007B20 = (__int64)GetModuleHandleA(0i64);
      Init_thread_footer(&dword_140007B38);
    }
  }
  v44[3] = qword_140007B20;
  v44[4] = 1519974081i64;
  if ( dword_140006770 > *v5 )
  {
    Init_thread_header(&dword_140006770);
    if ( dword_140006770 == -1 )
    {
      qword_140006788 = (__int64)NtCurrentPeb();
      Init_thread_footer(&dword_140006770);
    }
  }
  v44[5] = qword_140006788;
  v44[6] = 1822383754i64;
  v44[7] = 4214798493i64;
  if ( dword_140007B38 > *v5 )
  {
    Init_thread_header(&dword_140007B38);
    if ( dword_140007B38 == -1 )
    {
      qword_140007B20 = (__int64)GetModuleHandleA(0i64);
      Init_thread_footer(&dword_140007B38);
    }
  }
  v6 = qword_140007B20;
  if ( dword_140006770 > *v5 )
  {
    Init_thread_header(&dword_140006770);
    if ( dword_140006770 == -1 )
    {
      qword_140006788 = (__int64)NtCurrentPeb();
      Init_thread_footer(&dword_140006770);
    }
  }
  v44[8] = qword_140006788 ^ v6;
  v44[9] = 1377228170i64;
  v44[10] = 3974039857i64;
  v44[11] = 1571159279i64;
  if ( dword_140007B28 > *v5 )
  {
    Init_thread_header(&dword_140007B28);
    if ( dword_140007B28 == -1 )
    {
      qword_140006778 = v4;
      Init_thread_footer(&dword_140007B28);
    }
  }
  v7 = qword_140006778;
  if ( dword_140007B38 > *v5 )
  {
    Init_thread_header(&dword_140007B38);
    if ( dword_140007B38 == -1 )
    {
      qword_140007B20 = (__int64)GetModuleHandleA(0i64);
      Init_thread_footer(&dword_140007B38);
    }
  }
  v44[12] = qword_140007B20 ^ v7;
  v44[13] = 2511139750i64;
  v44[14] = 774692834i64;
  v44[15] = 2186181588i64;
  if ( dword_140007B28 > *v5 )
  {
    Init_thread_header(&dword_140007B28);
    if ( dword_140007B28 == -1 )
    {
      qword_140006778 = v4;
      Init_thread_footer(&dword_140007B28);
    }
  }
  v8 = qword_140006778;
  if ( dword_140006770 > *v5 )
  {
    Init_thread_header(&dword_140006770);
    if ( dword_140006770 == -1 )
    {
      qword_140006788 = (__int64)NtCurrentPeb();
      Init_thread_footer(&dword_140006770);
    }
  }
  v44[16] = qword_140006788 ^ v8;
  v44[17] = 1299201294i64;
  v9 = 0;
  v10 = 0;
  v48 = 0;
  v11 = 0i64;
  v12 = v44;
  v13 = 3178;
  v46 = 3178;
  v14 = (unsigned int *)&unk_140006740;
  do
  {
    if ( v9 < 12 )
    {
      if ( dword_140006738 > *v5 )
      {
        Init_thread_header(&dword_140006738);
        if ( dword_140006738 == -1 )
        {
          if ( !byte_14000672C )
          {
            for ( i = 0; i < 6; ++i )
            {
              if ( dword_140006780 > *v5 )
              {
                Init_thread_header(&dword_140006780);
                if ( dword_140006780 == -1 )
                {
                  v16 = std::_Random_device();
                  dword_140007B14 = -1;
                  dword_140006794 = v16;
                  for ( j = 1i64; j < 0x270; ++j )
                  {
                    v16 = j + 1812433253 * (v16 ^ (v16 >> 30));
                    dword_140006790[j + 1] = v16;
                  }
                  dword_140006790[0] = 624;
                  Init_thread_footer(&dword_140006780);
                }
              }
              do
                v18 = sub_140001CC0(dword_140006790);
              while ( v18 / 0xFFF001 >= 0x100 );
              v19 = v18 % 0xFFF001 - 2147479553;
              v20 = v19 + 0x80000000;
              if ( v19 >= 0x80000000 )
                v20 = v19 + 0x80000000;
              *v14++ = v20;
              v5 = v50;
            }
            byte_14000672C = 1;
            v10 = v48;
            v14 = (unsigned int *)&unk_140006740;
          }
          qword_140006730 = (__int64)&unk_140006740;
          Init_thread_footer(&dword_140006738);
        }
        v13 = v46;
      }
      if ( qword_140006730 )
        *v12 = *(int *)(v11 + qword_140006730) ^ (unsigned __int64)*v12;
    }
    v21 = v9 + 1;
    v22 = ((2 * v9 * v9 + 207)
         * (((int)(~(v9 % 3) * (v21 + 3)) ^ 0xC63E2i64 | 0xC) ^ ((~(v9 % 4) ^ (unsigned __int64)((__int64)(int)((v21 + 9) * (v21 + 11)) >> 31) | 0xA)
                                                               * (((((2 * v9 * v9 + 1898)
                                                                   * ((((v13 ^ 0xCF6A9Fi64)
                                                                      + (*v12 ^ (~(v9 % 2) ^ (unsigned __int64)((__int64)(int)(v21 * v21) >> 12) | 0xF))) << 12)
                                                                    - ((int)(v21 * ~(v9 % 2)) ^ 0x7F90i64 | 0xA))) ^ 0xA1E6A000) >> 2) & 0x3FFFFFFFFFFFFC00i64)
                                                               - ((v10 ^ 0xA5E89Fi64) << 10)))
         + 3244202607u) >> 15;
    *v12 = v22;
    if ( (v3 & 0x80000000000i64) != 0 )
      v23 = v3 & 0xFFFFF7FFFFFFFFFFui64;
    else
      v23 = v3 | 0x80000000000i64;
    v3 = v22 ^ v23;
    ++v9;
    v13 += 3178;
    v46 = v13;
    v10 += 92728;
    v48 = v10;
    v11 += 4i64;
    ++v12;
  }
  while ( v21 < 0x12 );
  v49 = v3;
  v24 = qword_140007B30;
  v45[0] = 3355086582i64;
  if ( dword_140007B28 > *v5 )
  {
    Init_thread_header(&dword_140007B28);
    if ( dword_140007B28 == -1 )
    {
      qword_140006778 = v24;
      Init_thread_footer(&dword_140007B28);
    }
  }
  v45[1] = qword_140006778;
  v45[2] = 2851533045i64;
  if ( dword_140007B38 > *v5 )
  {
    Init_thread_header(&dword_140007B38);
    if ( dword_140007B38 == -1 )
    {
      qword_140007B20 = (__int64)GetModuleHandleA(0i64);
      Init_thread_footer(&dword_140007B38);
    }
  }
  v45[3] = qword_140007B20;
  v45[4] = 1519974081i64;
  if ( dword_140006770 > *v5 )
  {
    Init_thread_header(&dword_140006770);
    if ( dword_140006770 == -1 )
    {
      qword_140006788 = (__int64)NtCurrentPeb();
      Init_thread_footer(&dword_140006770);
    }
  }
  v45[5] = qword_140006788;
  v45[6] = 1822383754i64;
  v45[7] = 4214798493i64;
  if ( dword_140007B38 > *v5 )
  {
    Init_thread_header(&dword_140007B38);
    if ( dword_140007B38 == -1 )
    {
      qword_140007B20 = (__int64)GetModuleHandleA(0i64);
      Init_thread_footer(&dword_140007B38);
    }
  }
  v25 = qword_140007B20;
  if ( dword_140006770 > *v5 )
  {
    Init_thread_header(&dword_140006770);
    if ( dword_140006770 == -1 )
    {
      qword_140006788 = (__int64)NtCurrentPeb();
      Init_thread_footer(&dword_140006770);
    }
  }
  v45[8] = qword_140006788 ^ v25;
  v45[9] = 1377228170i64;
  v45[10] = 3974039857i64;
  v45[11] = 1571159279i64;
  if ( dword_140007B28 > *v5 )
  {
    Init_thread_header(&dword_140007B28);
    if ( dword_140007B28 == -1 )
    {
      qword_140006778 = v24;
      Init_thread_footer(&dword_140007B28);
    }
  }
  v26 = qword_140006778;
  if ( dword_140007B38 > *v5 )
  {
    Init_thread_header(&dword_140007B38);
    if ( dword_140007B38 == -1 )
    {
      qword_140007B20 = (__int64)GetModuleHandleA(0i64);
      Init_thread_footer(&dword_140007B38);
    }
  }
  v45[12] = qword_140007B20 ^ v26;
  v45[13] = 2511139750i64;
  v45[14] = 774692834i64;
  v45[15] = 2186181588i64;
  if ( dword_140007B28 > *v5 )
  {
    Init_thread_header(&dword_140007B28);
    if ( dword_140007B28 == -1 )
    {
      qword_140006778 = v24;
      Init_thread_footer(&dword_140007B28);
    }
  }
  v27 = qword_140006778;
  if ( dword_140006770 > *v5 )
  {
    Init_thread_header(&dword_140006770);
    if ( dword_140006770 == -1 )
    {
      qword_140006788 = (__int64)NtCurrentPeb();
      Init_thread_footer(&dword_140006770);
    }
  }
  v45[16] = qword_140006788 ^ v27;
  v45[17] = 1299201294i64;
  v28 = 0;
  v29 = 0;
  v47 = 0;
  v30 = 0i64;
  v31 = v45;
  v32 = 3178;
  do
  {
    if ( v28 < 12 )
    {
      if ( dword_140006738 > *v5 )
      {
        Init_thread_header(&dword_140006738);
        if ( dword_140006738 == -1 )
        {
          if ( !byte_14000672C )
          {
            v33 = 0;
            v34 = (unsigned int *)&unk_140006740;
            do
            {
              if ( dword_140006780 > *v5 )
              {
                Init_thread_header(&dword_140006780);
                if ( dword_140006780 == -1 )
                {
                  v35 = std::_Random_device();
                  dword_140007B14 = -1;
                  dword_140006794 = v35;
                  for ( k = 1i64; k < 0x270; ++k )
                  {
                    v35 = k + 1812433253 * (v35 ^ (v35 >> 30));
                    dword_140006790[k + 1] = v35;
                  }
                  dword_140006790[0] = 624;
                  Init_thread_footer(&dword_140006780);
                }
              }
              do
                v37 = sub_140001CC0(dword_140006790);
              while ( v37 / 0xFFF001 >= 0x100 );
              v38 = v37 % 0xFFF001 - 2147479553;
              v39 = v38 + 0x80000000;
              if ( v38 >= 0x80000000 )
                v39 = v38 + 0x80000000;
              *v34 = v39;
              ++v33;
              ++v34;
              v5 = v50;
            }
            while ( v33 < 6 );
            byte_14000672C = 1;
          }
          qword_140006730 = (__int64)&unk_140006740;
          Init_thread_footer(&dword_140006738);
        }
        v29 = v47;
      }
      if ( qword_140006730 )
        *v31 = *(int *)(v30 + qword_140006730) ^ (unsigned __int64)*v31;
    }
    v40 = v28 + 1;
    v41 = ((2 * v28 * v28 + 207)
         * (((int)(~(v28 % 3) * (v40 + 3)) ^ 0xC63E2i64 | 0xC) ^ ((~(v28 % 4) ^ (unsigned __int64)((__int64)(int)((v40 + 9) * (v40 + 11)) >> 31) | 0xA)
                                                                * (((((2 * v28 * v28 + 1898)
                                                                    * ((((v32 ^ 0xCF6A9Fi64)
                                                                       + (*v31 ^ (~(v28 % 2) ^ (unsigned __int64)((__int64)(int)(v40 * v40) >> 12) | 0xF))) << 12)
                                                                     - ((int)(v40 * ~(v28 % 2)) ^ 0x7F90i64 | 0xA))) ^ 0xA1E6A000) >> 2) & 0x3FFFFFFFFFFFFC00i64)
                                                                - ((v29 ^ 0xA5E89Fi64) << 10)))
         + 3244202607u) >> 15;
    *v31 = v41;
    v42 = (const void *)(v41 ^ (v49 | 0x80000000000i64));
    if ( (v49 & 0x80000000000i64) != 0 )
      v42 = (const void *)(v41 ^ v49 & 0xFFFFF7FFFFFFFFFFui64);
    v49 = (unsigned __int64)v42;
    ++v28;
    v32 += 3178;
    v29 += 92728;
    v47 = v29;
    v30 += 4i64;
    ++v31;
  }
  while ( v40 < 0x12 );
  sub_140001030("Decrypted: 0x%p\n", v42);
  std::istream::get(std::cin);
  return 0;
}
  ```
