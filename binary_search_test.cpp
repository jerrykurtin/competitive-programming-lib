#include "binary_search.hpp"
#include <bits/stdc++.h>

using namespace std;

const int LOAD = 500;

int main(){
    cout << "testing binary_search..." << endl;
    vector<int> test_arr;

    // bad test: empty
    assert(binary_search(test_arr, 2) == -1);

    // good tests
    for (int addedVal = 0; addedVal < LOAD; ++addedVal){
        test_arr.push_back(addedVal);

        for (int searchedVal = 0; searchedVal <= addedVal; searchedVal++){
            if (binary_search(test_arr, searchedVal) != searchedVal){
                cout << "error: index of searchedVal " << searchedVal << " is " << binary_search(test_arr, searchedVal) << ", should be " << searchedVal << endl;
            }
            assert(binary_search(test_arr, searchedVal) == searchedVal);
        }
    }

    // bad tests: not found
    assert(binary_search(test_arr, -1) == -1);
    assert(binary_search(test_arr, LOAD + 1) == -1);

    cout << "binary_search testing completed." << endl;


    cout << "testing bisect_left..." << endl;
    test_arr.clear();

    // bad test: empty
    assert(bisect_left(test_arr, 2) == -1);

    // good tests
    for (int idx = 0; idx < LOAD; ++idx){
        test_arr.push_back(idx);

        for (int search_idx = 0; search_idx <= idx; search_idx++){
            assert(bisect_left(test_arr, search_idx) == search_idx);
        }
    }
    test_arr.clear();

    // unique tests
    test_arr = {2,3,3,3,6,8,12,14};
    assert(bisect_left(test_arr, 3) == 1);
    assert(bisect_left(test_arr, 4) == 4);
    assert(bisect_left(test_arr, 2) == 0);
    assert(bisect_left(test_arr, 0) == 0);
    assert(bisect_left(test_arr, 15) == test_arr.size());

    // insertion at ends
    test_arr = {1,2};
    assert(bisect_left(test_arr, 0) == 0);
    assert(bisect_left(test_arr, 3) == 2);

    cout << "bisect_left testing completed." << endl;


    cout << "testing bisect_right..." << endl;
    test_arr.clear();

    // bad test: empty
    assert(bisect_right(test_arr, 2) == -1);

    // good tests
    for (int idx = 0; idx < LOAD; ++idx){
        test_arr.push_back(idx);

        for (int search_idx = 0; search_idx <= idx; search_idx++){
            int target = search_idx + 1;
            if (bisect_right(test_arr, search_idx) != target){
                cout << "bisect_right failed to find " << search_idx << ", in array. Given response: " << bisect_right(test_arr, search_idx) << ", expected " << target << endl;
                cout << "array looks like: ";
                for (auto val : test_arr) cout << val << " ";
                cout << endl;
            }
            assert(bisect_right(test_arr, search_idx) == target);
        }
    }
    test_arr.clear();

    cout << "moving onto unique tests" << endl;
    // unique tests
    test_arr = {2,3,3,3,6,8,12,14};
    assert(bisect_right(test_arr, 3) == 4);
    assert(bisect_right(test_arr, 4) == 4);
    assert(bisect_right(test_arr, 2) == 1);
    assert(bisect_right(test_arr, 0) == 0);
    assert(bisect_right(test_arr, 15) == test_arr.size());

    // insertion at ends
    test_arr = {1,2};
    assert(bisect_right(test_arr, 0) == 0);
    assert(bisect_right(test_arr, 3) == 2);

    cout << "bisect_right testing completed." << endl;
    
}