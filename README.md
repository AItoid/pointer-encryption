### pointer-encryption
Simple pointer-protection to prevent easy-access of pointers.

### Pseudo-code
Below is the produced pseudo-code from trying to access a pointer once in IDA.
```cpp
*(_OWORD *)operator new(0x10ui64) = 0i64;
  v3 = qword_140006B30;
  v4 = (_DWORD *)(*(_QWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + 4i64);
  if ( dword_140006B1C > *v4 )
  {
    Init_thread_header(&dword_140006B1C);
    if ( dword_140006B1C == -1 )
    {
      qword_140005740 = v3;
      Init_thread_footer(&dword_140006B1C);
    }
  }
  if ( dword_140005738 > *v4 )
  {
    Init_thread_header(&dword_140005738);
    if ( dword_140005738 == -1 )
    {
      qword_140006B20 = (__int64)GetModuleHandleA(0i64);
      Init_thread_footer(&dword_140005738);
    }
  }
  if ( dword_140006B18 > *v4 )
  {
    Init_thread_header(&dword_140006B18);
    if ( dword_140006B18 == -1 )
    {
      qword_140005780 = (__int64)NtCurrentPeb();
      Init_thread_footer(&dword_140006B18);
    }
  }
  if ( dword_140005738 > *v4 )
  {
    Init_thread_header(&dword_140005738);
    if ( dword_140005738 == -1 )
    {
      qword_140006B20 = (__int64)GetModuleHandleA(0i64);
      Init_thread_footer(&dword_140005738);
    }
  }
  if ( dword_140006B18 > *v4 )
  {
    Init_thread_header(&dword_140006B18);
    if ( dword_140006B18 == -1 )
    {
      qword_140005780 = (__int64)NtCurrentPeb();
      Init_thread_footer(&dword_140006B18);
    }
  }
  if ( dword_140006B1C > *v4 )
  {
    Init_thread_header(&dword_140006B1C);
    if ( dword_140006B1C == -1 )
    {
      qword_140005740 = v3;
      Init_thread_footer(&dword_140006B1C);
    }
  }
  if ( dword_140005738 > *v4 )
  {
    Init_thread_header(&dword_140005738);
    if ( dword_140005738 == -1 )
    {
      qword_140006B20 = (__int64)GetModuleHandleA(0i64);
      Init_thread_footer(&dword_140005738);
    }
  }
  if ( dword_140006B1C > *v4 )
  {
    Init_thread_header(&dword_140006B1C);
    if ( dword_140006B1C == -1 )
    {
      qword_140005740 = v3;
      Init_thread_footer(&dword_140006B1C);
    }
  }
  if ( dword_140006B18 > *v4 )
  {
    Init_thread_header(&dword_140006B18);
    if ( dword_140006B18 == -1 )
    {
      qword_140005780 = (__int64)NtCurrentPeb();
      Init_thread_footer(&dword_140006B18);
    }
  }
  for ( i = 0; (unsigned int)i < 0x12; ++i )
  {
    if ( i < 12 && dword_140006B28 > *v4 )
    {
      Init_thread_header(&dword_140006B28);
      if ( dword_140006B28 == -1 )
      {
        if ( !byte_140005734 )
        {
          v6 = 0;
          v7 = (unsigned int *)&unk_140005748;
          do
          {
            if ( dword_140005788 > *v4 )
            {
              Init_thread_header(&dword_140005788);
              if ( dword_140005788 == -1 )
              {
                v8 = std::_Random_device();
                dword_140006B14 = -1;
                dword_140005794 = v8;
                for ( j = 1i64; j < 0x270; ++j )
                {
                  v8 = j + 1812433253 * (v8 ^ (v8 >> 30));
                  dword_140005790[j + 1] = v8;
                }
                dword_140005790[0] = 624;
                Init_thread_footer(&dword_140005788);
              }
            }
            do
              v10 = sub_1400013D0(dword_140005790);
            while ( v10 / 0xFFF001 >= 0x100 );
            v11 = v10 % 0xFFF001 - 2147479553;
            v12 = v11 + 0x80000000;
            if ( v11 >= 0x80000000 )
              v12 = v11 + 0x80000000;
            *v7 = v12;
            ++v6;
            ++v7;
          }
          while ( v6 < 6 );
          byte_140005734 = 1;
        }
        qword_140005778 = (__int64)&unk_140005748;
        Init_thread_footer(&dword_140006B28);
      }
    }
  }
  ```
