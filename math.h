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
 * Find the greatest common denominator between a and b
 * Runtime: O(log(a + b))
*/
long long gcd(long long int a, long long int b){
  if (b)
        return gcd(b, a % b);
    else
        return a;
}
 
/**
 * Find the least common multiple between a and b
 * Runtime: O(log(a + b))
*/
long long lcm(long long a, long long b)
{
    return (a / gcd(a,b)) * b;
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


#endif