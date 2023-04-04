#include <bits/stdc++.h>
using namespace std;

int findComponentsHelper(int curr, int& time, int& uniqueID, vector<vector<int>>& graph, vector<int>& status, vector<int>& visit, vector<int>& low, stack<int>& component);

/**
 * Finds and labels all strongly-connected components in a graph
 * Returns: a vector with these labels, of size graph.size()
 *  - these labels >= 1
*/
vector<int> findComponents(vector<vector<int>>& graph){
    vector<int> status(graph.size());
    vector<int> visit(graph.size());
    vector<int> low(graph.size());
    stack<int> component;

    int time = 0, uniqueID = 1;

    for (int curr = 0; curr < graph.size(); ++curr){
        if (status[curr] == 0){
            findComponentsHelper(curr, time, uniqueID, graph, status, visit, low, component);
        }
    }

    return status;
}


int findComponentsHelper(int curr, int& time, int& uniqueID, vector<vector<int>>& graph, vector<int>& status, vector<int>& visit, vector<int>& low, stack<int>& component){
    // status is also used to store node visiting status
    // use a counter from the caller to store a unique id
    status[curr] = -1;
    component.push(curr);
    visit[curr] = time;
    low[curr] = time;
    time++;
    // cout << "visiting " << curr << endl;

    for (int nbr: graph[curr]){
        if (status[nbr] == -1){
            low[curr] = min(low[curr], low[nbr]);
            // cout << "nbr " << nbr << " in progress" << endl;
        }
        else if (status[nbr] == 0){
            // cout << "nbr " << nbr << " unvisited" << endl;
            low[curr] = min(low[curr], findComponentsHelper(nbr, time, uniqueID, graph, status, visit, low, component));
        }
    }

    // cout << "[" << curr << "] visit: " << visit[curr] << ", low: " << low[curr] << endl;
    // find a connected component
    if (low[curr] == visit[curr]){
        while (curr != component.top()){
            status[component.top()] = uniqueID;
            component.pop();
        }
        status[curr] = uniqueID;
        component.pop();
        uniqueID++;
    }

    return low[curr];
}
