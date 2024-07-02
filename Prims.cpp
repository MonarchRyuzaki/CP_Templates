#include <bits/stdc++.h>
using namespace std;

void prims(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // O(E log V)
    vector<int> vis(n + 1, 0), minCostToSelect(n + 1, 1e8);
    set<pair<int, int>> st;
    st.insert({0, 1});
    int ans = 0;
    while (!st.empty()) {
        auto [cost, node] = *st.begin(); st.erase(*st.begin());
        minCostToSelect[node] = cost;
        vis[node] = 1;
        ans += cost;
        for (auto [v, w] : adj[node]) {
            if (!vis[v] && minCostToSelect[v] > w) {
                st.erase({minCostToSelect[v], v});
                minCostToSelect[v] = w;
                st.insert({minCostToSelect[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (minCostToSelect[i] == 1e8) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    cout << ans << endl;
}