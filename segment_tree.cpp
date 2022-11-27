#include <iostream>
#include "segment_tree.h"

using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    seg_tree<int> st(arr);

    cout << "from 0 to 8 is " << st.sum(0, 8) << endl;
    cout << "from 2 to 2 is " << st.sum(2, 2) << endl;
    
    st.update(2, 99);
    for (auto val : st.getTree()){
        cout << val << " ";
    }
    cout << endl;
    cout << "new from 2 to 4 is " << st.sum(2, 4) << endl;
}