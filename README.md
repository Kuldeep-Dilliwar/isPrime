
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

### High-Level Logic

1. **Fast Fail:** Instantly returns for small numbers (`n <= 1`) and simple factors (2, 3).
2. **Optimized Loop:** Iterates with a step of 6, checking only valid candidates (`i` and `i+2`).
3. **Boundary Check:** Uses `i <= n/i` instead of `i*i <= n` to prevent integer overflow.

### 🔍 Visual Trace (The "Pen" Analogy)

Here is exactly how the loop skips unnecessary checks:

**1. Start:**
You point your "pen" to **5** (`i = 5`).

* **Check 1:** `n % 5` (This is `6(1) - 1`)
* **Check 2:** `n % (5 + 2)` aka `n % 7` (This is `6(1) + 1`)
* *Note: We implicitly skipped 6 because it is divisible by 6.*

**2. The Jump (`i += 6`):**
Your pen flies from **5 → 11**.

* **What you skipped:** You flew right over **8, 9, and 10**.
* **8:** Even (Divisible by 2)
* **9:** Divisible by 3
* **10:** Even (Divisible by 2)


* **The Logic:** We already checked divisibility by 2 and 3 at the start, so we know these cannot be prime. We don't even look at them.

**3. Next Stop:**
Now your pen is at **11** (`i = 11`).

* **Check 1:** `n % 11` (This is `6(2) - 1`)
* **Check 2:** `n % (11 + 2)` aka `n % 13` (This is `6(2) + 1`)

## 📄 License

MIT License
