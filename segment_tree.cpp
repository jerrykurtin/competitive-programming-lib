#include <iostream>
#include <cassert>
#include <stdexcept>
#include "segment_tree.h"

using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    seg_tree<int> st(arr);

    assert(st.sum(0, 8) == 45);
    assert(st.sum(2, 2) == 3);
    
    st.update(2, 99);
    assert(st.sum(2, 4) == 108);
    assert(st.sum(0, 8) == 141);
    try {
        st.sum(-1, 7);
        cout << "failed to catch range error" << endl;
        exit(-1);
    } catch (runtime_error e) {}

    try {
        st.sum(0, 9);
        cout << "failed to catch range error" << endl;
        exit(-1);
    } catch (runtime_error e) {}

    vector<int> arr2 = {11, 6, 1, 12};
    seg_tree<int, bit_xor<int>> st2(arr2);
    for (auto val : st2.getTree()) {
        cout << val << ", ";
    }
    cout << endl;

}
