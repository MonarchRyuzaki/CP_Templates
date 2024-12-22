#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> oset;
// *find_by_order(k) -> kth element
// order_of_key(x) -> number of element less than x
#define MOD 1000000007
// #define MOD 998244353
#define INF 1e18
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define mii map<int, int>
#define vi vector<int>
#define vs vector<string>
#define sz(a) (int)a.size()
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vvpii vector<vector<pii>>
#define set_bits __builtin_popcountll
#define vpii vector<pii>
#define vd vector<double>
#define vvd vector<vector<double>>
#define ff first
#define ss second
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int expo(int a, int b, int mod = INF) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
int mulinv(int a, int b) {return expo(a, b - 2, b);}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mulinv(b, m), m) + m) % m;}
int phin(int n) {int number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
vi sieve(int n) {static vi arr(n + 1); for (int i = 0; i <= n; i++) arr[i] = i;  vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == i) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = i;} return arr;}
vi phi_1_to_n(int n) {vi phi(n + 1); for (int i = 0; i <= n; i++) phi[i] = i; for (int i = 2; i <= n; i++) if (phi[i] == i) {for (int j = i; j <= n; j += i) phi[j] -= phi[j] / i;} return phi;}
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
// struct Comp {
//     bool operator()(const int &a, const int &b) const {
//         return a > b;
//     }
// };
int u, v, w, n, m, q, k, r, x, l, h, y, ans = 0, N = 3e5 + 1;
string s, t, p;
vi a(N), b(N);
//        N   E  S  W
vi dx = { -1, 0, 1, 0};
vi dy = { 0, 1, 0, -1};
int lim = 2e5;
int dp[210][210][210];
int ex[210][210];
void solve() {
    cin >> s;
    m = sz(s);
    if (m > 1) {
        n = (s[m - 2] - '0') * 10 + (s[m - 1] - '0');
    } else {
        n = s[m - 1] - '0';
    }
    vi a = {1, 2, 3, 4};
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        ans = mod_add(ans, expo(a[i], n % 4, 5), 5);
    }
    cout << ans << endl;
}

signed main() {
#ifdef ONLINEJUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(15);
    // pre();
    // int t; cin >> t; while (t--) { solve(); }
    int t = 1; while (t--) { solve();    }
#ifdef ONLINEJUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
}