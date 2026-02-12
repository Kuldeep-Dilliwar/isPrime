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

bool isPrime(unsigned long long n);

int main() {
	unsigned long long n = 0;
	if (scanf("%llu", &n) != 1) return 1;
	printf(isPrime(n)?"\n Yup Prime \n":"\n Nope Not Prime \n");
	return 0;	
}

bool isPrime(unsigned long long n) {
	if(n<=1) return false;
	if(n == 2 || n == 3) return true;
	if(n%2 == 0 || n%3 == 0) return false;
	for(unsigned long long i = 5; i <= n/i; i += 6) if(n%i == 0 || n%(i+2) == 0) return false;
	return true;
}
