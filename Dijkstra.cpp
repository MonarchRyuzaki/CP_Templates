#include <bits/stdc++.h>
using namespace std;

// ALYWAS WORKS EXCEPT WHEN -ve Wt and -ve Cycle

// TC: O((V+E) log V)
void dijkstra() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist(n + 1, 1e7); dist[1] = 0;
    vector<int> backtrack(n + 1, -1);
    set<pair<int,int>> st; st.insert({0, 1});
    while (!st.empty()) {
        auto [d, c] = *st.begin(); st.erase(st.begin());
        if (c == n) break;
        for (auto [v, wt] : adj[c]) {
            if (d + wt < dist[v]) {
                st.erase({dist[v], v});
                backtrack[v] = c;
                dist[v] = d + wt;
                st.insert({dist[v], v});
            }
        }
    }
    if (dist[n] == 1e7) {cout << -1 << endl; return;}
    vector<int> ans;
    int node = n;
    while (backtrack[node] != -1) {
        ans.push_back(node);
        node = backtrack[node];
    }
    ans.push_back(node);
    reverse(ans.begin(), ans.end());
    for (auto &x : ans) cout << x << " ";
    cout << endl;
}