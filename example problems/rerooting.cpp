#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &dp, vector<int> &sub) {
    for (auto child: adj[node]) {
        if (child != parent) {
            dfs(child, node, adj, dp, sub);
            dp[node] += dp[child] + sub[child];
            sub[node] += sub[child];
        }
    }
}

// Rerooting can be done only if we can reverse the operation. If we cant reverse, like dp[cur] = max(dp[child]) + 1, we need to store dp[child] for every node, O(n) in that case
void changeRoot(int newRoot, int oldRoot, vector<int> &dp, vector<int> &sub) {
    dp[oldRoot] -= dp[newRoot] + sub[newRoot];
    sub[oldRoot] -= sub[newRoot];

    dp[newRoot] += dp[oldRoot] + sub[oldRoot];
    sub[newRoot] += sub[oldRoot];
}

void dfsToReroot(int node, int parent, vector<vector<int>> &adj, vector<int> &ans, vector<int> &dp, vector<int> &sub) {
    ans[node] = dp[node];
    for (auto child: adj[node]) {
        if (child != parent) {
            changeRoot(child, node, dp, sub);
            dfsToReroot(child, node, adj, ans, dp, sub);
            changeRoot(node, child, dp, sub);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    int n;
    cin >> n;
 
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vector<int> ans(n), dp(n, 0), sub(n, 1);
    dfs(0, -1, adj, dp, sub);
    dfsToReroot(0, -1, adj, ans, dp, sub);
 
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
 
    return 0;
}