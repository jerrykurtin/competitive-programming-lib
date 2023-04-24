#pragma once
#include <bits/stdc++.h>

/**
 * Get the state of the ith bit in a mask
*/
bool getState(unsigned mask, unsigned i){
    return (mask >> i) & 1;
}

/**
 * Check if x is a subset of y
*/
bool isSubset(unsigned x, unsigned y){
    return (x & y) == x;
}

/**
 * count number of bits set in a mask
*/
int countBits(unsigned mask){
    return __builtin_popcount(mask);
}