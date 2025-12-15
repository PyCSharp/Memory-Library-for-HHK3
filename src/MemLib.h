#pragma once
#include <cstdint>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string>

// This is just the header file, look into MemLib.cpp for the code

enum class ControlRegister {
    VBR,
    SSR,
    SPC,
    SGR,
    DBR,
    GBR,
    SR,
};

std::vector<char> ReadMemory(uintptr_t addr, size_t size);
void WriteMemory(uintptr_t addr, const void* data, size_t size);
void ExecuteFromAddr(uintptr_t addr);
void ExecuteShellcode(unsigned char* code);
void Sleep(int sec);
uint32_t ReadControlRegister(ControlRegister controlRegister);
void WriteControlRegister(ControlRegister controlRegister, uint32_t value);
