#include <bits/stdc++.h>
using namespace std;

// WORKS FOR UNDIRECTED AS WELL AS DIRECTED GRAPHS
// WORKS WITH NEGATIVE EDGES
// DOES NOT WORK WITH NEGATIVE CYCLE
void floydWarshall() {
    int n = 100;
    vector<vector<int>> adj(n, vector<int> (n));
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}