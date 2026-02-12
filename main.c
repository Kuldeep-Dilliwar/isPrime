/*
 * Optimized Prime Number Checker
 * Author: Kuldeep Dilliwar
 * License: MIT
 * * Logic:
 * 1. Handles small edge cases (<=1, 2, 3) immediately.
 * 2. Eliminates multiples of 2 and 3.
 * 3. Uses the 6k +/- 1 optimization to skip 2/3rds of numbers.
 * 4. Loops only up to sqrt(n) to achieve O(sqrt(N)) time complexity.
 */

#include <stdio.h>
#include <stdbool.h>

// unsigned long long goes up to 18,446,744,073,709,551,615
bool isPrime(unsigned long long n);

int main() {
    unsigned long long n = 0;

    printf("Enter a number to check primality: ");
    // Validate input is an integer
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    // Ternary operator for clean output
    printf("%d is %s\n", n, isPrime(n) ? "Prime" : "Not Prime");

    return 0;
}

bool isPrime(unsigned long long n) {
    // 1. Handle small numbers and edge cases
    if (n <= 1) return false; // 0 and 1 are not prime
    if (n == 2 || n == 3) return true; // 2 and 3 are prime

    // 2. Eliminate multiples of 2 and 3
    if (n % 2 == 0 || n % 3 == 0) return false;

    // 3. Check for factors in the form of 6k +/- 1
    // Loop runs while i*i <= n (written as i <= n/i to prevent integer overflow)
    for (int i = 5; i <= n / i; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}
