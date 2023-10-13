#pragma once

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
int binary_search(std::vector<T>& arr, T val, int lo = 0, int hi = -1){
    /* Finds the index of val in a sorted arr
    Args:
    - arr: the array to search
    - val: the target
    - lo: the starting index (inclusive), default is 0
    - hi: the ending index (inclusive), default is last value (-1)
    Returns: index if found, -1 if not found
    note: searches only for exact values */

    int mid;
    if (hi == -1) hi = arr.size() - 1;    // convert -1 to last index
    if (lo > hi) return -1;

    while (lo < hi){
        mid = lo + (hi - lo) / 2;

        if (arr[mid] == val) 
            return mid;
        else if (arr[mid] < val) 
            lo = mid + 1;
        else 
            hi = mid - 1;
    }

    if (arr[lo] == val)
        return lo;

    return -1;
}

template <typename T>
int bisect_left(std::vector<T>& arr, T val, int lo = 0, int hi = -1){
    /* Finds the leftmost valid insertion index of val in a sorted array (emulates python's bisect function)
    Args:
    - arr: the array to search
    - val: the target
    - lo: the starting index (inclusive), default is 0
    - hi: the ending index (inclusive), default is last value (-1)
    Returns: insertion idx, -1 if invalid */

    int mid;

    // edge cases
    if (hi == -1) hi = arr.size() - 1;    // convert -1 to last index
    if (lo > hi) return -1;


    while (lo < hi){
        mid = lo + (hi - lo) / 2;
        if (arr[mid] < val) 
            lo = mid + 1;
        else 
            hi = mid;
    }

    // edge case: larger than all values in the array
    if (arr[lo] < val)
        return lo + 1;

    return lo;
}

template <typename T>
int bisect_right(std::vector<T>& arr, T val, int lo = 0, int hi = -1){
    /* Finds the rightmost valid insertion index of val in a sorted array (emulates python's bisect function)
    Args:
    - arr: the array to search
    - val: the target
    - lo: the starting index (inclusive), default is 0
    - hi: the ending index (inclusive), default is last value (-1)
    Returns: insertion idx, -1 if invalid */

    int mid;

    // edge cases
    if (hi == -1) hi = arr.size() - 1;    // convert -1 to last index
    if (lo > hi) return -1;


    while (lo < hi){
        mid = lo + (hi - lo) / 2;
        if (arr[mid] > val) 
            hi = mid;
        else 
            lo = mid + 1;
    }

    // edge case: <= all values in the array
    if (arr[lo] <= val)
        return lo + 1;

    return lo;
}
