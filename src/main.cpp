#include "MemLib.h"

int main() {
    char data[] = "Hello, World!";

    // Must be static and 4-byte aligned for safe execution :3
    // Code for restarting the calculator
    alignas(4) static uint8_t code[] = {
    0xD2, 0x3B, 0x42, 0x0B,
    0x00, 0x09, 0xD2, 0x3A,
    0x42, 0x0B, 0x00, 0x09,
    0x00, 0x0B, 0x00, 0x09
    };

    // DONT JUST WRITE AT RANDOM ADDRESSES! Your calculator will not like it >.<
    WriteMemory(0x8C4D77EC, data, sizeof(data));

    // Read memory and save it in a variable
    auto bytes = ReadMemory(0x8C4D77EC, 14);

    // Print out as text
    for (char c : bytes)
        printf("%c", c);

    // This launches the Hollyhock Launcher, idk why. lol
    ExecuteFromAddr(0x00128FF4);

    // Wait for 5 seconds
    Sleep(5);

    // This restarts the calculator
    ExecuteShellcode(code);

    return 0;
}