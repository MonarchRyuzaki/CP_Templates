#include <bits/stdc++.h>
using namespace std;

// TESTED ON STRING MATCHING CSES
// QUERY (N + Q)
// int x = h.ff * (1e9 + 21) + h.ss;
// Use above Logic in case of TLE
class Hash {
private:
    using ll = long long;
    vector<pair<ll, ll>> hash, power;
    const ll BASE1 = 5689;
    const ll BASE2 = 8861;
    const ll M = 1e9 + 7;

public:
    Hash(const string& s) {
        ll n = s.size();
        hash.assign(n + 1, {0, 0});
        power.assign(n + 1, {1, 1});
        for (ll i = 1; i <= n; i++) { // O(n)
            hash[i] = {(hash[i - 1].first * BASE1 + (s[i - 1] - 'a' + 1)) % M,
                       (hash[i - 1].second * BASE2 + (s[i - 1] - 'a' + 1)) % M
                      };
            power[i] = {(power[i - 1].first * BASE1) % M,
                        (power[i - 1].second * BASE2) % M
                       };
        }
    }
    
    // For Palindrome reverse (l, r) -> normal & (n - 1 - r, n - 1 - l) -> in reversed string
    // Example lelo easy hai
    pair<ll, ll> get(ll l, ll r) { // O(1)
        l++; r++;
        ll hash1 = (hash[r].first - (hash[l - 1].first * power[r - l + 1].first) % M + M) % M;
        ll hash2 = (hash[r].second - (hash[l - 1].second * power[r - l + 1].second) % M + M) % M;
        return {hash1, hash2};
    }
};