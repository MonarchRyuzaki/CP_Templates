#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n+1); size.resize(n+1);
        for (int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUltParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUltParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ult_u = findUltParent(u), ult_v = findUltParent(v);
        if (ult_u == ult_v) return;
        if (size[ult_v] < size[ult_u]) {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        } else {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];            
        }
    }
}