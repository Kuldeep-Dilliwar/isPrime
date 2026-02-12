# Optimized Prime Checker in C

A high-performance C implementation for determining primality using the **6k ± 1 optimization strategy**.

## 🚀 Features
- **Efficiency:** Significantly faster than standard `i+=2` iteration.
- **Complexity:** Time O(√N) | Space O(1).
- **Safety:** Includes integer overflow protection logic.
- **Portability:** Compilation instructions for both Windows and Linux/Termux.

## 🛠️ Build & Run

### 1. Compile
```bash
gcc main.c -o isPrime
```

### 2. Run

**For Windows (Command Prompt/PowerShell):**
```cmd
isPrime
```

**For Linux/Termux/macOS:**
```bash
./isPrime
```

## 🧠 Algorithm Details
Instead of naively checking every odd number, this implementation observes that all primes greater than 3 are of the form `6k ± 1`.
1.  **Fast Fail:** Instantly returns for small numbers (`n <= 1`) and simple factors (2, 3).
2.  **Optimized Loop:** Iterates with a step of 6, checking only valid candidates (`i` and `i+2`).
3.  **Boundary Check:** Uses `i <= n/i` instead of `i*i <= n` to prevent integer overflow during square verification.

## 📄 License
MIT License
