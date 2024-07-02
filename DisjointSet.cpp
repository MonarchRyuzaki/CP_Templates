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
    int getLeader(int node) {
        if (node == parent[node]) return node;
        return parent[node] = getLeader(parent[node]);
    }
    void merge(int u, int v) {
        int ult_u = getLeader(u), ult_v = getLeader(v);
        if (ult_u == ult_v) return;
        if (size[ult_v] < size[ult_u]) {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        } else {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];            
        }
    }
};