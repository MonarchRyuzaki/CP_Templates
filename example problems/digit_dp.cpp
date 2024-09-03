#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define vi vector<int>;
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define sz(a) (int)a.size()

int countNumbers(string &n, int index, bool isPrefixSame, int sum, int d, vvvi &dp) {
    if (index == sz(n)) {
        if (sum % d == 0) return 1;
        return 0;
    }
    if (dp[index][isPrefixSame][sum] != -1) return dp[index][isPrefixSame][sum];
    int ans = 0;
    for (char digit = '0'; digit <= (isPrefixSame ? n[index] : '9'); digit++) {
        ans += countNumbers(n, index + 1, isPrefixSame && n[index] == digit, (sum % d + (digit - '0') % d) % d, d, dp);
        ans %= MOD;
    }
    return dp[index][isPrefixSame][sum] = ans;
}

void solve() {
    string n; cin >> n;
    int d; cin >> d;
    vvvi dp(n.size(), vvi (2, vi (d, -1)));
    cout << (countNumbers(n, 0, true, 0, d, dp) - 1 + MOD) % MOD << endl;
}
