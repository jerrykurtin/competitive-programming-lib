#include <iostream>
#include <cassert>
#include "circular_queue.h"

using namespace std;

int main(){
    circular_queue<int> q;

    // push 10 vals
    for (int idx = 0; idx < 10; ++idx){
        q.push(idx);
    }

    // pop 5 vals
    for (int idx = 0; idx < 5; ++idx){
        // cout << "Popping val at idx " << idx << ": " << q.pop() << endl;
        assert(q.pop() == idx);
    }

    // push 10 more
    for (int idx = 10; idx < 20; ++idx){
        q.push(idx);
    }

    // pop 15
    for (int idx = 0; idx < 15; ++idx){
        assert(q.pop() == 5 + idx);
    }
    assert(q.empty());

    try {
        q.pop();
        throw runtime_error("did not have trouble popping from empty queue");
    }
    catch (runtime_error err){
    }

    cout << "circular_queue tests successful!" << endl;

}