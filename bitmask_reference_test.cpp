#include <bits/stdc++.h>
#include "bitmask_reference.h"
using namespace std;

int main(){
    string mask1String = "10101001";
    string mask2String = "00100001";
    unsigned mask1 = stoi(mask1String, 0, 2);
    unsigned mask2 = stoi(mask2String, 0, 2);

    assert(getState(mask1, 0) == 1);
    assert(getState(mask1, 1) == 0);
    assert(getState(mask1, 2) == 0);
    assert(getState(mask1, 3) == 1);
    assert(getState(mask1, 4) == 0);
    assert(getState(mask1, 5) == 1);
    assert(getState(mask1, 6) == 0);
    assert(getState(mask1, 7) == 1);
    assert(getState(mask1, 8) == 0);
    assert(getState(mask1, 31) == 0);

    assert(isSubset(mask2, mask1) == 1);
    assert(isSubset(mask1, mask2) == 0);

    assert(countBits(mask1) == 4);
    assert(countBits(mask2) == 2);
    assert(countBits(UINT32_MAX) == 32);
    assert(countBits(0) == 0);
}