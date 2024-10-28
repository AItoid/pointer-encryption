### pointer-encryption
Simple pointer-protection to prevent easy-access of pointers for x64 and x86.

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
  __int64 v3; // rdi
  _DWORD *v4; // r15
  __int64 v5; // rbx
  __int64 v6; // rbx
  __int64 v7; // rbx
  int v8; // esi
  int v9; // r11d
  __int64 v10; // r12
  __int64 *v11; // r14
  int v12; // r13d
  unsigned int *v13; // rdi
  unsigned int i; // ebx
  unsigned int v15; // eax
  unsigned __int64 j; // rdx
  unsigned int v17; // r8d
  unsigned int v18; // edx
  unsigned int v19; // eax
  unsigned int v20; // r9d
  unsigned __int64 v21; // r8
  const void *v22; // rax
  __int64 v23; // rdi
  __int64 v24; // rbx
  __int64 v25; // rbx
  __int64 v26; // rbx
  int v27; // esi
  int v28; // r11d
  __int64 v29; // r12
  __int64 *v30; // r14
  int v31; // r13d
  unsigned int v32; // ebx
  unsigned int *v33; // rdi
  unsigned int v34; // eax
  unsigned __int64 k; // rcx
  unsigned int v36; // r8d
  unsigned int v37; // edx
  unsigned int v38; // eax
  unsigned int v39; // r9d
  unsigned __int64 v40; // r8
  const void *v41; // rax
  __int64 v43[18]; // [rsp+20h] [rbp-E0h] BYREF
  __int64 v44[24]; // [rsp+B0h] [rbp-50h] BYREF
  int v45; // [rsp+180h] [rbp+80h]
  int v46; // [rsp+180h] [rbp+80h]
  unsigned __int64 v47; // [rsp+188h] [rbp+88h]
  _DWORD *v48; // [rsp+190h] [rbp+90h]

  v47 = (unsigned __int64)operator new(0x10ui64);
  *(_OWORD *)v47 = 0i64;
  v3 = qword_140007B48;
  v43[0] = 3355086582i64;
  v4 = (_DWORD *)(*(_QWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + 4i64);
  v48 = v4;
  if ( dword_140007B28 > *v4 )
  {
    Init_thread_header(&dword_140007B28);
    if ( dword_140007B28 == -1 )
    {
      qword_140006738 = v3;
      Init_thread_footer(&dword_140007B28);
    }
  }
  v43[1] = qword_140006738;
  v43[2] = 2851533032i64;
  if ( dword_140006730 > *v4 )
  {
    Init_thread_header(&dword_140006730);
    if ( dword_140006730 == -1 )
    {
      qword_140007B30 = (__int64)GetModuleHandleA(0i64);
      Init_thread_footer(&dword_140006730);
    }
  }
  v43[3] = qword_140007B30;
  v43[4] = 1519974081i64;
  if ( dword_140007B18 > *v4 )
  {
    Init_thread_header(&dword_140007B18);
    if ( dword_140007B18 == -1 )
    {
      qword_140006778 = (__int64)NtCurrentPeb();
      Init_thread_footer(&dword_140007B18);
    }
  }
  v43[5] = qword_140006778;
  v43[6] = 1822383754i64;
  v43[7] = 4214798505i64;
  if ( dword_140006730 > *v4 )
  {
    Init_thread_header(&dword_140006730);
    if ( dword_140006730 == -1 )
    {
      qword_140007B30 = (__int64)GetModuleHandleA(0i64);
      Init_thread_footer(&dword_140006730);
    }
  }
  v5 = qword_140007B30;
  if ( dword_140007B18 > *v4 )
  {
    Init_thread_header(&dword_140007B18);
    if ( dword_140007B18 == -1 )
    {
      qword_140006778 = (__int64)NtCurrentPeb();
      Init_thread_footer(&dword_140007B18);
    }
  }
  v43[8] = qword_140006778 ^ v5;
  v43[9] = 1377228170i64;
  v43[10] = 3974039857i64;
  v43[11] = 1571159279i64;
  if ( dword_140007B28 > *v4 )
  {
    Init_thread_header(&dword_140007B28);
    if ( dword_140007B28 == -1 )
    {
      qword_140006738 = v3;
      Init_thread_footer(&dword_140007B28);
    }
  }
  v6 = qword_140006738;
  if ( dword_140006730 > *v4 )
  {
    Init_thread_header(&dword_140006730);
    if ( dword_140006730 == -1 )
    {
      qword_140007B30 = (__int64)GetModuleHandleA(0i64);
      Init_thread_footer(&dword_140006730);
    }
  }
  v43[12] = qword_140007B30 ^ v6;
  v43[13] = 2511139753i64;
  v43[14] = 774692834i64;
  v43[15] = 2186181588i64;
  if ( dword_140007B28 > *v4 )
  {
    Init_thread_header(&dword_140007B28);
    if ( dword_140007B28 == -1 )
    {
      qword_140006738 = v3;
      Init_thread_footer(&dword_140007B28);
    }
  }
  v7 = qword_140006738;
  if ( dword_140007B18 > *v4 )
  {
    Init_thread_header(&dword_140007B18);
    if ( dword_140007B18 == -1 )
    {
      qword_140006778 = (__int64)NtCurrentPeb();
      Init_thread_footer(&dword_140007B18);
    }
  }
  v43[16] = qword_140006778 ^ v7;
  v43[17] = 1299201289i64;
  v8 = 0;
  v9 = 0;
  v45 = 0;
  v10 = 0i64;
  v11 = v43;
  v12 = 3178;
  v13 = (unsigned int *)&unk_140006740;
  do
  {
    if ( v8 < 12 )
    {
      if ( dword_140007B38 > *v4 )
      {
        Init_thread_header(&dword_140007B38);
        if ( dword_140007B38 == -1 )
        {
          if ( !byte_14000672C )
          {
            for ( i = 0; i < 6; ++i )
            {
              if ( dword_140006780 > *v4 )
              {
                Init_thread_header(&dword_140006780);
                if ( dword_140006780 == -1 )
                {
                  v15 = std::_Random_device();
                  dword_140007B14 = -1;
                  dword_140006794 = v15;
                  for ( j = 1i64; j < 0x270; ++j )
                  {
                    v15 = j + 1812433253 * (v15 ^ (v15 >> 30));
                    dword_140006790[j + 1] = v15;
                  }
                  dword_140006790[0] = 624;
                  Init_thread_footer(&dword_140006780);
                }
              }
              do
                v17 = sub_140001CA0(dword_140006790);
              while ( v17 / 0xFFF001 >= 0x100 );
              v18 = v17 % 0xFFF001 - 2147479553;
              v19 = v18 + 0x80000000;
              if ( v18 >= 0x80000000 )
                v19 = v18 + 0x80000000;
              *v13++ = v19;
              v4 = v48;
            }
            byte_14000672C = 1;
            v13 = (unsigned int *)&unk_140006740;
          }
          qword_140006770 = (__int64)&unk_140006740;
          Init_thread_footer(&dword_140007B38);
        }
        v9 = v45;
      }
      if ( qword_140006770 )
        *v11 = *(int *)(v10 + qword_140006770) ^ (unsigned __int64)*v11;
    }
    v20 = v8 + 1;
    v21 = ((2 * v8 * v8 + 207)
         * (((int)(~(v8 % 3) * (v20 + 3)) ^ 0xC63E2i64 | 0xC) ^ ((~(v8 % 4) ^ (unsigned __int64)((__int64)(int)((v20 + 9) * (v20 + 11)) >> 31) | 0xA)
                                                               * (((((2 * v8 * v8 + 1898)
                                                                   * ((((v12 ^ 0xCF6A9Fi64)
                                                                      + (*v11 ^ (~(v8 % 2) ^ (unsigned __int64)((__int64)(int)(v20 * v20) >> 12) | 0xF))) << 12)
                                                                    - ((int)(v20 * ~(v8 % 2)) ^ 0x7F90i64 | 0xA))) ^ 0xA1E6A000) >> 2) & 0x3FFFFFFFFFFFFC00i64)
                                                               - ((v9 ^ 0xA5E89Fi64) << 10)))
         + 3244202607u) >> 15;
    *v11 = v21;
    v22 = (const void *)(v21 ^ v47);
    v47 ^= v21;
    ++v8;
    v12 += 3178;
    v9 += 92728;
    v45 = v9;
    v10 += 4i64;
    ++v11;
  }
  while ( v20 < 0x12 );
  sub_140001030("Encrypted: 0x%p\n", v22);
  v23 = qword_140007B48;
  v44[0] = 3355086582i64;
  if ( dword_140007B28 > *v4 )
  {
    Init_thread_header(&dword_140007B28);
    if ( dword_140007B28 == -1 )
    {
      qword_140006738 = v23;
      Init_thread_footer(&dword_140007B28);
    }
  }
  v44[1] = qword_140006738;
  v44[2] = 2851533032i64;
  if ( dword_140006730 > *v4 )
  {
    Init_thread_header(&dword_140006730);
    if ( dword_140006730 == -1 )
    {
      qword_140007B30 = (__int64)GetModuleHandleA(0i64);
      Init_thread_footer(&dword_140006730);
    }
  }
  v44[3] = qword_140007B30;
  v44[4] = 1519974081i64;
  if ( dword_140007B18 > *v4 )
  {
    Init_thread_header(&dword_140007B18);
    if ( dword_140007B18 == -1 )
    {
      qword_140006778 = (__int64)NtCurrentPeb();
      Init_thread_footer(&dword_140007B18);
    }
  }
  v44[5] = qword_140006778;
  v44[6] = 1822383754i64;
  v44[7] = 4214798505i64;
  if ( dword_140006730 > *v4 )
  {
    Init_thread_header(&dword_140006730);
    if ( dword_140006730 == -1 )
    {
      qword_140007B30 = (__int64)GetModuleHandleA(0i64);
      Init_thread_footer(&dword_140006730);
    }
  }
  v24 = qword_140007B30;
  if ( dword_140007B18 > *v4 )
  {
    Init_thread_header(&dword_140007B18);
    if ( dword_140007B18 == -1 )
    {
      qword_140006778 = (__int64)NtCurrentPeb();
      Init_thread_footer(&dword_140007B18);
    }
  }
  v44[8] = qword_140006778 ^ v24;
  v44[9] = 1377228170i64;
  v44[10] = 3974039857i64;
  v44[11] = 1571159279i64;
  if ( dword_140007B28 > *v4 )
  {
    Init_thread_header(&dword_140007B28);
    if ( dword_140007B28 == -1 )
    {
      qword_140006738 = v23;
      Init_thread_footer(&dword_140007B28);
    }
  }
  v25 = qword_140006738;
  if ( dword_140006730 > *v4 )
  {
    Init_thread_header(&dword_140006730);
    if ( dword_140006730 == -1 )
    {
      qword_140007B30 = (__int64)GetModuleHandleA(0i64);
      Init_thread_footer(&dword_140006730);
    }
  }
  v44[12] = qword_140007B30 ^ v25;
  v44[13] = 2511139753i64;
  v44[14] = 774692834i64;
  v44[15] = 2186181588i64;
  if ( dword_140007B28 > *v4 )
  {
    Init_thread_header(&dword_140007B28);
    if ( dword_140007B28 == -1 )
    {
      qword_140006738 = v23;
      Init_thread_footer(&dword_140007B28);
    }
  }
  v26 = qword_140006738;
  if ( dword_140007B18 > *v4 )
  {
    Init_thread_header(&dword_140007B18);
    if ( dword_140007B18 == -1 )
    {
      qword_140006778 = (__int64)NtCurrentPeb();
      Init_thread_footer(&dword_140007B18);
    }
  }
  v44[16] = qword_140006778 ^ v26;
  v44[17] = 1299201289i64;
  v27 = 0;
  v28 = 0;
  v46 = 0;
  v29 = 0i64;
  v30 = v44;
  v31 = 3178;
  do
  {
    if ( v27 < 12 )
    {
      if ( dword_140007B50 > *v4 )
      {
        Init_thread_header(&dword_140007B50);
        if ( dword_140007B50 == -1 )
        {
          if ( !byte_14000672C )
          {
            v32 = 0;
            v33 = (unsigned int *)&unk_140006740;
            do
            {
              if ( dword_140006780 > *v4 )
              {
                Init_thread_header(&dword_140006780);
                if ( dword_140006780 == -1 )
                {
                  v34 = std::_Random_device();
                  dword_140007B14 = -1;
                  dword_140006794 = v34;
                  for ( k = 1i64; k < 0x270; ++k )
                  {
                    v34 = k + 1812433253 * (v34 ^ (v34 >> 30));
                    dword_140006790[k + 1] = v34;
                  }
                  dword_140006790[0] = 624;
                  Init_thread_footer(&dword_140006780);
                }
              }
              do
                v36 = sub_140001CA0(dword_140006790);
              while ( v36 / 0xFFF001 >= 0x100 );
              v37 = v36 % 0xFFF001 - 2147479553;
              v38 = v37 + 0x80000000;
              if ( v37 >= 0x80000000 )
                v38 = v37 + 0x80000000;
              *v33 = v38;
              ++v32;
              ++v33;
              v4 = v48;
            }
            while ( v32 < 6 );
            byte_14000672C = 1;
          }
          qword_140007B40 = (__int64)&unk_140006740;
          Init_thread_footer(&dword_140007B50);
        }
        v28 = v46;
      }
      if ( qword_140007B40 )
        *v30 = *(int *)(v29 + qword_140007B40) ^ (unsigned __int64)*v30;
    }
    v39 = v27 + 1;
    v40 = ((2 * v27 * v27 + 207)
         * (((int)(~(v27 % 3) * (v39 + 3)) ^ 0xC63E2i64 | 0xC) ^ ((~(v27 % 4) ^ (unsigned __int64)((__int64)(int)((v39 + 9) * (v39 + 11)) >> 31) | 0xA)
                                                                * (((((2 * v27 * v27 + 1898)
                                                                    * ((((v31 ^ 0xCF6A9Fi64)
                                                                       + (*v30 ^ (~(v27 % 2) ^ (unsigned __int64)((__int64)(int)(v39 * v39) >> 12) | 0xF))) << 12)
                                                                     - ((int)(v39 * ~(v27 % 2)) ^ 0x7F90i64 | 0xA))) ^ 0xA1E6A000) >> 2) & 0x3FFFFFFFFFFFFC00i64)
                                                                - ((v28 ^ 0xA5E89Fi64) << 10)))
         + 3244202607u) >> 15;
    *v30 = v40;
    v41 = (const void *)(v40 ^ v47);
    v47 ^= v40;
    ++v27;
    v31 += 3178;
    v28 += 92728;
    v46 = v28;
    v29 += 4i64;
    ++v30;
  }
  while ( v39 < 0x12 );
  sub_140001030("Decrypted: 0x%p\n", v41);
  std::istream::get(std::cin);
  return 0;
}
  ```
