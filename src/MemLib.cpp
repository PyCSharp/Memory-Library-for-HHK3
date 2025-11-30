#include "MemLib.h"


/* This is a small memory library I wrote to make it easier for 
   beginners to mess around with the memory of the Casio FX-CP 400
   (ClassPad 2). Have fun, try not to brick anything.

   My GitHub:  https://github.com/PyCSharp/
   My Discord: https://discord.gg/DScqwRvn5

   The library is still tiny, but more features are coming 
   as soon as I win the fight against my motivation.

   Btw, if you donate to me you're cute :3

   Bitcoin:   bc1q4gcyfvfljka2r8t5lylalghlqw6n27thy32qad
   Tron:      TYeRaTK7X39TjppFoiAsZr8G8XHXkCAxzY
   Litecoin:  LeYvzSFdT2vfKu2h6nJafn9C5DZVkbnCWE
   Ethereum:  0xBF39E238D04AA6633612B9D8b1142579d8Ea091F
   Solana:    EPhmze7oafdysvbBYZsjwarMwosmj9zcY8YCNMy5nJqL
   XRP:       r34jZwea1GkYeCSRTz4B2BFVnLgZJ1o1Zg
   Dogecoin:  DDou3qK8PQyfnvd6e4Af132h8cHZUDgops
   Monero:    41qk5qcQcBHfQGN7FN7Bzj4rKa4LyLPZ2LVhRBnyQyj9F4oH7YsXZ5dRom1Hp6AUR4EXV6AQXj58Agfa2vnRGGbT7X3D5TE
*/

// A function to stop the program for a few seconds
void Sleep(int sec) {
    // Dereferencing a uint8_t pointer that points to a BCD second timer
    uint8_t startTime = *reinterpret_cast<uint8_t*>(0xA413FEC2);

    // Checking if the timer is BCD. But its not necessary
    assert(((startTime & 0xF0) >> 4) < 6);
    assert((startTime & 0x0F) < 10);

    // Converting the BCD to decimal
    int lastTimeDec = ((startTime & 0xF0) >> 4) * 10 + (startTime & 0x0F);
    int elapsed = 0;

    // Will be executed as long as the elapsed time is shorter than the waiting time in seconds
    while (elapsed < sec) {
        // Dereferencing a uint8_t pointer that points to a BCD second timer
        uint8_t currentTime = *reinterpret_cast<uint8_t*>(0xA413FEC2);

        // Checking if the timer is BCD. But its not necessary
        assert(((currentTime & 0xF0) >> 4) < 6);
        assert((currentTime & 0x0F) < 10);

        // Converting the BCD to decimal
        int currentTimeDec = ((currentTime & 0xF0) >> 4) * 10 + (currentTime & 0x0F);

        // If this loop did not exist, the while loop would exit immediately
        for (int i = 0; i < 50000; i++) {
            asm volatile("nop");
        }

        // Checking if the time has changed
        if (currentTimeDec != lastTimeDec) {
            int delta = (currentTimeDec - lastTimeDec + 60) % 60;
            elapsed += delta;
            lastTimeDec = currentTimeDec;
        }
    }
}

// Reads `size` bytes from a raw memory address and returns them as a byte vector
std::vector<char> ReadMemory(uintptr_t addr, size_t size) {
    // Allocate a buffer with `size` bytes
    std::vector<char> data(size);

    // Copy `size` bytes from the target address into the buffer
    std::memcpy(data.data(), reinterpret_cast<void*>(addr), size);

    // Return the copied memory contents
    return data;
}

// Writes `size` bytes to a memory address
void WriteMemory(uintptr_t addr, const void* data, size_t size) {

    // Copy `size` bytes to `addr`
    std::memcpy(reinterpret_cast<void*>(addr), data, size);
}

// Execute from an address
void ExecuteFromAddr(uintptr_t addr) {
    // Defines a function type that returns an int and takes no parameters
    typedef int func(void);

    // A function pointer to the address to be executed
    func* f = reinterpret_cast<func*>(addr);

    // Calling the function
    f();
}

// Executes shellcode
void ExecuteShellcode(unsigned char* code) {
    // Create a type alias named fn_t, which is a function pointer to a function that takes no arguments and returns nothing
    using fn_t = void (*)();

    // Declare a function pointer called f that points to `code`
    fn_t f = reinterpret_cast<fn_t>(code);

    // Call the function
    f();
}