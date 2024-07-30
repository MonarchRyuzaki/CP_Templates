#include <bits/stdc++.h>
using namespace std;

class BinaryLifting {
private:
    int n;
    int maxPower;
    vector<vector<int>> adj;
    vector<vector<int>> parent; // O (n log n)
    vector<int> level; 

    void populateParents(int node, int par, int currLevel) {
        level[node] = currLevel;
        parent[0][node] = par;
        for (auto it : adj[node]) {
            if (it != par) { 
                populateParents(it, node, currLevel + 1);
            }
        }
    }

    // O(n log n)
    void initializeParents() {
        populateParents(0, -1, 0);
        for (int i = 1; i < maxPower; i++) {
            for (int node = 0; node < n; node++) {
                if (parent[i - 1][node] != -1) {
                    parent[i][node] = parent[i - 1][parent[i - 1][node]];
                }
            }
        }
    }

    // Gives in O(log n * log n)
    int lcaBin(int a, int b) {
        if (level[a] > level[b]) {
            a = kthParent(level[a] - level[b], a);
        } else if (level[a] < level[b]) {
            b = kthParent(level[b] - level[a], b);
        }
        if (a == b) return a;
        int low = 1, high = level.size(), ans = -1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            int kthA = kthParent(mid, a);
            int kthB = kthParent(mid, b);
            if (kthA == kthB) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return kthParent(ans, a); 
    }

public:
    BinaryLifting(int n, const vector<vector<int>>& adj)
        : n(n), adj(adj) {
        maxPower = log2(n) + 7;
        level.resize(n);
        parent.assign(maxPower, vector<int>(n, -1));
        initializeParents();
    }

    // O (log n)
    int kthParent(int k, int node) {
        int par = node;
        for (int i = 0; i < maxPower; i++) {
            if (k & (1 << i)) {
                par = parent[i][par];
                if (par == -1) return -1;
            }
        }
        return par;
    }

    // O (log n) 
    int lca(int a, int b) {
        if (level[a] > level[b]) {
            a = kthParent(level[a] - level[b], a);
        } else if (level[a] < level[b]) {
            b = kthParent(level[b] - level[a], b);
        }
        if (a == b) return a;
        for (int i = maxPower - 1; i >= 0; i--) { 
            if (parent[i][a] != parent[i][b]) {
                a = parent[i][a];
                b = parent[i][b];
            }
        }
        return parent[0][a];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {  
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BinaryLifting bl(n, adj);

    cout << bl.kthParent(5, 4) << endl;
    cout << bl.lca(3, 7) << endl;
}

int main() {
    solve();
    return 0;
}
