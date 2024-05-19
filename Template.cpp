#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> oset;
// *find_by_order(k) -> kth element
// order_of_key(x) -> number of element less than x
#define MOD 1000000007
#define INF 1e18
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf push_front
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define sz(a) (int)a.size()
#define vvi vector<vector<int>>
#define set_bits __builtin_popcountll
#define vpii vector<pii>
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
vi sieve(int n) {int*arr = new int[n + 1](); for(int i=0; i<=n; i++) arr[i] = i;  vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == i) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = i;} return vect;}
vi phi_1_to_n(int n) {vi phi(n+1); for(int i=0; i<=n; i++) phi[i] = i; for (int i = 2; i <= n; i++) if (phi[i] == i) {for (int j = i; j <= n; j += i) phi[j] -= phi[j]/i;} return phi;}

/* OM NAMAH SHIVAY */
void solve() {
    
}

signed main() {
#ifdef ONLINEJUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); x
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t; while (t--) { solve(); }
#ifdef ONLINEJUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
}