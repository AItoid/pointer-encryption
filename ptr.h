#pragma once

#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <random>
#include "ptr.h"

class pointer_encryption
{
private:
    __forceinline int gen_random_int(int min, int max)
    {
        static std::mt19937 engine(std::random_device{}());
        std::uniform_int_distribution<int> dist(min, max);
        return dist(engine);
    }

    __forceinline int* get_random_array()
    {
        static int random[12];
        static bool init = false;

        if (!init)
        {
            for (int i = 0; i < sizeof(random) / sizeof(std::uintptr_t); i++)
            {
                random[i] = gen_random_int(0xFFF, 0xFFFFFF);
            }

            init = true;
        }

        return random;
    }

    __forceinline void* get_base()
    {
        static void* base = (void*)GetModuleHandleA(nullptr);
        return base;
    }

    __forceinline void* get_peb()
    {
#ifdef _WIN64
        static void* peb = (void*)__readgsqword(0x60);
#else
        static void* peb = (void*)__readfsdword(0x30);
#endif
        return peb;
    }

    __forceinline void* get_instance()
    {
        static void* instance = this;
        return instance;
    }

public:
    template <typename t>
    __forceinline t process(void* in_ptr)
    {
        std::uintptr_t ptr_address = (std::uintptr_t)in_ptr;

        std::uintptr_t key_array[18];
        key_array[0] = 0xC7FA8EF6;
        key_array[1] = (std::uintptr_t)get_instance();
        key_array[2] = 0xA9F6EFC2 + static_cast<int>(__DATE__[0]) + static_cast<int>(__DATE__[1]) + static_cast<int>(__DATE__[2]);
        key_array[3] = (std::uintptr_t)get_base();
        key_array[4] = 0x5A98F6C1;
        key_array[5] = (std::uintptr_t)get_peb();
        key_array[6] = 0x6C9F5E8A;
        key_array[7] = 0xFB38B773 + static_cast<int>(__TIMESTAMP__[0]) + static_cast<int>(__TIMESTAMP__[1]) + static_cast<int>(__TIMESTAMP__[2]);
        key_array[8] = (std::uintptr_t)get_base() ^ (std::uintptr_t)get_peb();
        key_array[9] = 0x5216D58A;
        key_array[10] = 0xECDF0931;
        key_array[11] = 0x5DA5FCEF;
        key_array[12] = (std::uintptr_t)get_instance() ^ (std::uintptr_t)get_base();
        key_array[13] = 0x95ACF30D + static_cast<int>(__TIMESTAMP__[11]) + static_cast<int>(__TIMESTAMP__[12]) + static_cast<int>(__TIMESTAMP__[14]);
        key_array[14] = 0x2E2CDFE2;
        key_array[15] = 0x824E7BD4;
        key_array[16] = (std::uintptr_t)get_instance() ^ (std::uintptr_t)get_peb();
        key_array[17] = 0x4D703C6C + static_cast<int>(__TIMESTAMP__[15]) + static_cast<int>(__TIMESTAMP__[17]) + static_cast<int>(__TIMESTAMP__[18]);

        for (int i = 0; i < sizeof(key_array) / sizeof(std::uintptr_t); i++)
        {
            if (i < 12)
            {
                static int* random = get_random_array();
                if (random)
                    key_array[i] ^= random[i];
            }

            key_array[i] ^= (~(i % 2) ^ (i + 1) * (i + 1) >> 0xC) | 0xF;
            key_array[i] += ((i + 1) * 0xC6A) ^ 0xCF6A9F;
            key_array[i] <<= 0xC;
            key_array[i] -= 0x7F9A ^ (~(i % 2) * (i + 1)) | 0xA;
            key_array[i] *= ((i + i) * i) + 0x76A;
            key_array[i] ^= _byteswap_ulong(0xC5A9E6A1);
            key_array[i] >>= 0xC;

            key_array[i] *= (~(i % 4) ^ (i + 0xC) * (i + 0xA) >> 0xFF) | 0xA;
            key_array[i] -= ((i * 4) * 0x5A8E) ^ 0xA5E89F;
            key_array[i] <<= 0xA;
            key_array[i] ^= 0xC63EA ^ (~(i % 3) * (i + 4)) | 0xC;
            key_array[i] *= ((i + i) * i) + 0xCF;
            key_array[i] += _byteswap_ulong(0x6F9A5EC1);
            key_array[i] >>= 0xF;

            bool should_decrypt = ptr_address & 0x80000000000;

            // Decrypt only when we should.
            if (should_decrypt)
            {
                ptr_address &= ~(0x80000000000);
                ptr_address ^= key_array[i];
            }
            else
            {
                ptr_address |= 0x80000000000;
                ptr_address ^= key_array[i];
            }
        }

        return (t)ptr_address;
    }
};

inline pointer_encryption* g_ptr = new pointer_encryption();
#define PROCESS_PTR(type, ptr, decrypt) g_ptr->process<type>(ptr, decrypt)
#define PROCESS_PTR_AUTO(ptr, decrypt) g_ptr->process<decltype(ptr)>(ptr, decrypt)
