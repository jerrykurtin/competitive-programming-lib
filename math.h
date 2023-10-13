#ifndef MATH_H
#define MATH_H
#include <bits/stdc++.h>

// O(sqrt(n))
/**
 * Find the lowest factor (not including 1) of n
 * Runtime: O(sqrt(n))
*/
long long findLowestFactor(long long n) {
    for (int x = 2; x < sqrt(n) + 1; ++x) {
        if (n % x == 0) {
            return x;
        }
    }
    return n;
}

/**
 * Calculate the greatest common divisor (GCD) of 2 numbers.
 * 
 * Complexity: O(log(max(a, b))) 
 * - worst case: 2 consecutive Fibonacci numbers
 * 
 * @return the GCD of a and b
*/
template <typename T>
T gcd(T a, T b) {
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

/**
 * Calculate the least common multiple (LCM) of 2 numbers.
 * 
 * Complexity: O(log(max(a, b)))
 * 
 * @return the LCM of a and b
*/
template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}
/**
 * find summation of linear series from l to r inclusive
 * runtime: O(1)
*/
long long rangeSum(long long l, long long r) {
    if (l > r) {
        return 0;
    }
    return (l + r) * (r - l + 1) / 2;
}


/**
 * Checks whether an integer is prime or not.
 *
 * Complexity: O(sqrt(n))
 *
 * @param n a positive integer to check its integer primality.
 *
 * @return {@code true} if "n" is prime; {@code false} otherwise.
 */
template<typename T>
bool isPrime(T n) {
    if (n < 2)
        return 0;
    if (n % 2 == 0)
        return (n == 2);
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

/**
 * Generates all the prime numbers of the integers from 1 to "n"
 * using Sieve of Eratosthenes' algorithm.
 * After calling this function, "prime[i]" will be equal true if "i" is prime; false otherwise.
 *
 * Complexity: O(n.log(log(n)))
 */
bool* generatePrimes(int n) {
    bool* prime = (bool*) malloc(n + 1 * sizeof(bool));
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (!prime[i]) continue;

        for (int j = i * i; j <= n; j += i) {
            prime[j] = false;
        }
    }
    return prime;
}

#endif