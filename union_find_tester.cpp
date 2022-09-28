#include "union_find.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;
    UF graph(n);

    graph.merge(0, 1);
    graph.merge(1,2);
    graph.merge(3,4);
    graph.merge(4,5);
    assert(graph.find(0) != graph.find(3));
    
    graph.merge(1,4);
    assert(graph.find(2) == graph.find(5));
    cout << "tests successful" << endl;
}