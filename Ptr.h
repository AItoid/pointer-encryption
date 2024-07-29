#pragma once
#include "Includes.h"

class Pointer
{
public:
    __forceinline void* GetBase()
    {
        static void* moduleBase = (void*)GetModuleHandleA(nullptr);
        return moduleBase;
    }

    __forceinline void* GetPeb()
    {
#ifdef _WIN64
        static void* pebBase = (void*)__readgsqword(0x60);
#else
        static void* pebBase = (void*)__readfsdword(0x30);
#endif
        return pebBase;
    }

    __forceinline void* GetInstance()
    {
        static void* instance = this;
        return instance;
    }

    __forceinline void* Encrypt(void* inPtr)
    {
        std::uintptr_t ptrAddress = (std::uintptr_t)inPtr;

        std::uintptr_t keyArray[18];
        keyArray[0] = 0xC7FA8EF6;
        keyArray[1] = (std::uintptr_t)GetInstance();
        keyArray[2] = 0xA9F6EFC2;
        keyArray[3] = (std::uintptr_t)GetBase();
        keyArray[4] = 0x5A98F6C1;
        keyArray[5] = (std::uintptr_t)GetPeb();
        keyArray[6] = 0x6C9F5E8A;
        keyArray[7] = 0xFB38B773;
        keyArray[8] = (std::uintptr_t)GetBase() ^ (std::uintptr_t)GetPeb();
        keyArray[9] = 0x5216D58A;
        keyArray[10] = 0xECDF0931;
        keyArray[11] = 0x5DA5FCEF;
        keyArray[12] = (std::uintptr_t)GetInstance() ^ (std::uintptr_t)GetBase();
        keyArray[13] = 0x95ACF30D;
        keyArray[14] = 0x2E2CDFE2;
        keyArray[15] = 0x824E7BD4;
        keyArray[16] = (std::uintptr_t)GetInstance() ^ (std::uintptr_t)GetPeb();
        keyArray[17] = 0x4D703C6C;

        for (int i = 0; i < sizeof(keyArray) / sizeof(std::uintptr_t); i++)
        {
            keyArray[i] ^= (~(i % 2) ^ (i + 1) * (i + 1) >> 0xC) | 0xF;
            keyArray[i] += ((i + 1) * 0xC6A) ^ 0xCF6A9F;
            keyArray[i] <<= 0xC;
            keyArray[i] -= 0x7F9A ^ (~(i % 2) * (i + 1)) | 0xA;
            keyArray[i] *= ((i + i) * i) + 0x76A;
            keyArray[i] ^= _byteswap_ulong(0xC5A9E6A1);
            keyArray[i] >>= 0xC;

            keyArray[i] *= (~(i % 4) ^ (i + 0xC) * (i + 0xA) >> 0xFF) | 0xA;
            keyArray[i] -= ((i * 4) * 0x5A8E) ^ 0xA5E89F;
            keyArray[i] <<= 0xA;
            keyArray[i] ^= 0xC63EA ^ (~(i % 3) * (i + 4)) | 0xC;
            keyArray[i] *= ((i + i) * i) + 0xCF;
            keyArray[i] += _byteswap_ulong(0x6F9A5EC1);
            keyArray[i] >>= 0xF;
        }

        // NOTE: Move into previous loop?
        for (int i = 0; i < sizeof(keyArray) / sizeof(std::uintptr_t); i++)
        {
            ptrAddress ^= keyArray[i];
        }

        return (void*)ptrAddress;
    }

    __forceinline void* Decrypt(void* inPtr)
    {
        std::uintptr_t ptrAddress = (std::uintptr_t)inPtr;

        std::uintptr_t keyArray[18];
        keyArray[0] = 0xC7FA8EF6;
        keyArray[1] = (std::uintptr_t)GetInstance();
        keyArray[2] = 0xA9F6EFC2;
        keyArray[3] = (std::uintptr_t)GetBase();
        keyArray[4] = 0x5A98F6C1;
        keyArray[5] = (std::uintptr_t)GetPeb();
        keyArray[6] = 0x6C9F5E8A;
        keyArray[7] = 0xFB38B773;
        keyArray[8] = (std::uintptr_t)GetBase() ^ (std::uintptr_t)GetPeb();
        keyArray[9] = 0x5216D58A;
        keyArray[10] = 0xECDF0931;
        keyArray[11] = 0x5DA5FCEF;
        keyArray[12] = (std::uintptr_t)GetInstance() ^ (std::uintptr_t)GetBase();
        keyArray[13] = 0x95ACF30D;
        keyArray[14] = 0x2E2CDFE2;
        keyArray[15] = 0x824E7BD4;
        keyArray[16] = (std::uintptr_t)GetInstance() ^ (std::uintptr_t)GetPeb();
        keyArray[17] = 0x4D703C6C;

        for (int i = 0; i < sizeof(keyArray) / sizeof(std::uintptr_t); i++)
        {
            keyArray[i] ^= (~(i % 2) ^ (i + 1) * (i + 1) >> 0xC) | 0xF;
            keyArray[i] += ((i + 1) * 0xC6A) ^ 0xCF6A9F;
            keyArray[i] <<= 0xC;
            keyArray[i] -= 0x7F9A ^ (~(i % 2) * (i + 1)) | 0xA;
            keyArray[i] *= ((i + i) * i) + 0x76A;
            keyArray[i] ^= _byteswap_ulong(0xC5A9E6A1);
            keyArray[i] >>= 0xC;

            keyArray[i] *= (~(i % 4) ^ (i + 0xC) * (i + 0xA) >> 0xFF) | 0xA;
            keyArray[i] -= ((i * 4) * 0x5A8E) ^ 0xA5E89F;
            keyArray[i] <<= 0xA;
            keyArray[i] ^= 0xC63EA ^ (~(i % 3) * (i + 4)) | 0xC;
            keyArray[i] *= ((i + i) * i) + 0xCF;
            keyArray[i] += _byteswap_ulong(0x6F9A5EC1);
            keyArray[i] >>= 0xF;
        }

        // NOTE: Move into previous loop?
        for (int i = 0; i < sizeof(keyArray) / sizeof(std::uintptr_t); i++)
        {
            ptrAddress ^= keyArray[i];
        }

        return (void*)ptrAddress;
    }
};

inline Pointer* g_ptr = new Pointer();
