#ifndef MOD_MATH_H
#define MOD_MATH_H
#include <bits/stdc++.h>

/**
 * Code credit: https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/math/math.cpp
*/

/**
 * Use binary exponentiation to calculate large powers.
 *  (base = 0, exp = 0 returns 1)
 * 
 * Idea: exp can be reduced to binary form. ex: 2^10 = 2{1010_2} = 2^8 * 2^2
 * We only need to calculate powers of 2 of base (base^0, base^1, base^2, base^4, ...), which is log(exp) powers
 * 
 * Complexity: O(log(exp))
 * 
 * @param base the base number
 * @param exp the exponent
 * @param mod the modulus
 * 
 * @return (base^exp) % mod
*/
T power(T base, T exp, T mod) {
    T ans = 1;
    base %= mod;

    while (exp > 0) {
        // Multiply ans by current power of base if bit is present
        if (exp & 1) ans = (ans * base) % mod;
        exp >>= 1;
        base = (base * base) % mod; 
    }

    return ans;
}


/**
 * Compute the modular inverse of a modulo m.
 * (a * modInerse(a)) = 1 % m
 * 
 * Only works if m is a prime number
 * Complexity: O(log(m))
 * 
 * @param a the number whose modular inverse we want
 * @param m the modulus. Must be prime
 * 
 * @return the modular inverse of a mod m
*/
template <typename T>
T modInverse(T a, T m) {
    return power(a, m - 2, m);
}

#endif