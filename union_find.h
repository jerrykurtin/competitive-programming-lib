#pragma once
#include <vector>

class UF {
    public:
        std::vector<int> parent;
        std::vector<int> rank;
        int size;
        
        UF(int size): parent(size), rank(size), size(size){
            for (int idx = 0; idx < size; ++idx){
                parent[idx] = idx;
            }
        }

        // find returns the parent of node x
        int find(int x){
            if (x > size) return false;
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
    
        // merge connects the set containing node x with the set containing node y
        // rank is used to gurantee optimal merges
        int merge(int x, int y){
            if (x > size || y > size) 
                return -1;
            
            int parentx = find(x), parenty = find(y);
            if (rank[parentx] == rank[parenty]){
                parent[parenty] = parentx;
                rank[parentx]++;
            }
            
            else if (rank[parentx] > rank[parenty])
                parent[parenty] = parentx;
            else
                parent[parentx] = parenty;
            
            return find(parentx);
        }
};
