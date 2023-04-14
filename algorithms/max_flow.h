#pragma once
#include <bits/stdc++.h>
using namespace std;
int flowBFS(int src, int sink, const vector<set<int>>& residuals, vector<vector<int>>& weight, vector<int>& parent);

/**
 * Finds the maximum flow for a graph using the Edmonds-Karp BFS method
 * @arg graph: adj list of weighted graph
 * @arg weight: adj matrix storing weights of graph
 * @arg src: the index of the source node
 * @arg sink: the index of the sink node
 * @returns integer of the max flow, or 0 if there is no flow between src and sink
*/
int EdKarpFlow(const vector<vector<int>>& graph, vector<vector<int>> weight, int src, int sink){    
    int flow = 0;
    vector<int> parent(graph.size());
    int newFlow;

    vector<set<int>> residuals(graph.size());
    for (int src = 0; src < graph.size(); ++src){
        for (int nbr : graph[src]){
            residuals[src].insert(nbr);
            residuals[nbr].insert(src);
        }
    }

    newFlow = flowBFS(src, sink, residuals, weight, parent);
    while (newFlow){
        flow += newFlow;
        int curr = sink;
        while (curr != src){
            int prev = parent[curr];
            // cout << "flow " << newFlow << " from " << prev << " to " << curr << endl;
            weight[prev][curr] -= newFlow;
            weight[curr][prev] += newFlow;
            curr = prev;
        }

        newFlow = flowBFS(src, sink, residuals, weight, parent);
    }

    return flow;
}

int flowBFS(int src, int sink, const vector<set<int>>& residuals, vector<vector<int>>& weight, vector<int>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[src] = -2; // otherwise we'll go back to src
    queue<pair<int, int>> q;
    q.push({src, INT32_MAX});

    while (!q.empty()){
        int curr = q.front().first;
        int prevFlow = q.front().second;
        q.pop();
        // cout << "visiting node " << curr << " with flow " << prevFlow <<  endl;

        for (int nbr : residuals[curr]){
            // if we haven't seen it yet and there is capacity left
            if (parent[nbr] == -1 && weight[curr][nbr]){
                parent[nbr] = curr;
                int newFlow = min(prevFlow, weight[curr][nbr]);

                if (nbr == sink){
                    // cout << "reached the sink with flow " << newFlow << endl;
                    return newFlow;
                }

                q.push({nbr, newFlow});
            }
        }
    }
    
    return 0;
}