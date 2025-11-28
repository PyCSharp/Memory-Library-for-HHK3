# MemLib – Low‑Level Memory Library for the Casio FX‑CP 400 (ClassPad 2)

A small, lightweight C++ library for messing directly with the memory of the **Casio FX‑CP 400 / ClassPad 2**.  
Play with it, break stuff, learn things. Your device, your responsibility.

---

## Features

- **Sleep(sec)**  
  Busy‑waits on the hardware BCD second timer.  
  No OS calls, no abstraction — pure hardware polling.

- **ReadMemory(addr, size)**  
  Dumps raw bytes from any memory address into a `std::vector<char>`.

- **WriteMemory(addr, data, size)**  
  Writes raw bytes directly into memory.
  Ideal for patching, modifying values, or runtime hacks.

- **ExecuteFromAddr(addr)**  
  Jumps to an address and treats it as a function.  
  If you know what's there, you can execute it.

- **ExecuteShellcode(ptr)**  
  Executes raw shellcode via a function pointer.  

More features coming once I win my fight against motivation.

---

## Warning

This library gives you **raw access** to the ClassPad’s memory.  
If you write to the wrong address, you *will* soft‑brick or hard‑brick the device.  
Use responsibly — or irresponsibly, but knowingly.

---

## Installation (Windows)

1. Clone the repository
```
git clone https://github.com/PyCSharp/Memory-Library-for-HHK3
cd MemLib
``

3. Install WSL (Windows Subsystem for Linux)
   Open PowerShell as Administrator and run:
   
   `wsl --install`
   
   Then restart your computer.

4. Install Docker
   Download and install Docker Desktop:
   https://www.docker.com/products/docker-desktop/

5. Adjust project paths
   Edit startDocker.bat and set the path to your project.

6. Start Docker and build
   In your project directory:
   
   Open CMD:
   
   `startDocker`
   
   Once the Docker terminal starts:
   
   ```
   cd /memlib
   make compile_commands.json
   make -j
   ```

8. Done

   Your compiled .hh3 file will appear in the /dist folder.

---

## Support

If this project helped you, or you want to fuel more cursed TI/Casio dev projects:

- **Bitcoin:** bc1q4gcyfvfljka2r8t5lylalghlqw6n27thy32qad  
- **Tron:** TYeRaTK7X39TjppFoiAsZr8G8XHXkCAxzY  
- **Litecoin:** LeYvzSFdT2vfKu2h6nJafn9C5DZVkbnCWE  
- **Ethereum:** 0xBF39E238D04AA6633612B9D8b1142579d8Ea091F  
- **Solana:** EPhmze7oafdysvbBYZsjwarMwosmj9zcY8YCNMy5nJqL  
- **XRP:** r34jZwea1GkYeCSRTz4B2BFVnLgZJ1o1Zg  
- **Dogecoin:** DDou3qK8PQyfnvd6e4Af132h8cHZUDgops  
- **Monero:** 41qk5qcQcBHfQGN7FN7Bzj4rKa4LyLPZ2LVhRBnyQyj9F4oH7YsXZ5dRom1Hp6AUR4EXV6AQXj58Agfa2vnRGGbT7X3D5TE

---

## Contact

- **Discord:** https://discord.gg/DScqwRvn5  
