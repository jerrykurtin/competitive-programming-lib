#include <bits/stdc++.h>
using namespace std;
#include "max_flow.h"

int main(){

    vector<vector<int>> edges = {
        {0, 1, 7},
        {0, 5, 4},
        {1, 2, 5},
        {1, 4, 3},
        {2, 3, 8},
        {4, 2, 3},
        {4, 3, 5},
        {5, 1, 3},
        {5, 4, 2}
    };

    int n = 6;
    vector<vector<int>> graph(n);
    vector<vector<int>> weights(n, vector<int>(n));
    
    for (auto edge: edges){
        graph[edge[0]].push_back(edge[1]);
        weights[edge[0]][edge[1]] = edge[2];
    }

    assert(EdKarpFlow(graph, weights, 0, 3) == 10);
}