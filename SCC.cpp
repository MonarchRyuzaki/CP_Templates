#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;

void fillOrder(int v, const vvi &adj, vector<bool> &visited, stack<int> &Stack) {
    visited[v] = true;
    for (int i : adj[v])
        if (!visited[i])
            fillOrder(i, adj, visited, Stack);
    Stack.push(v);
}

void DFSUtil(int v, const vvi &transpose, vector<bool> &visited, vector<int> &scc) {
    visited[v] = true;
    scc.push_back(v);
    for (int i : transpose[v])
        if (!visited[i])
            DFSUtil(i, transpose, visited, scc);
}

vvi getTranspose(const vvi &adj) {
    int V = adj.size();
    vvi transpose(V);
    for (int v = 0; v < V; v++) {
        for (int i : adj[v]) {
            transpose[i].push_back(v);
        }
    }
    return transpose;
}

vvi findSCCs(const vvi &adj) {
    int V = adj.size();
    stack<int> Stack;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
        if (!visited[i])
            fillOrder(i, adj, visited, Stack);

    vvi transpose = getTranspose(adj);

    fill(visited.begin(), visited.end(), false);

    vvi sccs;

    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();

        if (!visited[v]) {
            vector<int> scc;
            DFSUtil(v, transpose, visited, scc);
            sccs.push_back(scc);
        }
    }

    return sccs;
}