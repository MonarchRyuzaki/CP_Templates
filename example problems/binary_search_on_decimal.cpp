#include <bits/stdc++.h>
using namespace std;

double dist(double x, double y) {
    return x * x + y * y;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> c(n);
    vector<double> k(n);
    int sum = m;
    int total = 1e6;
    for (int i = 0; i < n; i++) {
        cin >> c[i].first >> c[i].second >> k[i];
        sum += k[i];
    }
    if (sum < total) {
        cout << -1 << endl;
        return;
    }
    double low = 0, high = 1e10, p = 1e-8, ans = -1;
    for (int i = 1; i <= 200; i++) {
        double mid = (low + high) / 2;
        int sum = m;
        for (int j = 0; j < n; j++){
            double d = dist(c[j].first, c[j].second);
            if (mid * mid >= d) {
                sum += k[j];
            }
        }
        if (sum >= total) {
            ans = mid;
            high = mid - p;
        }
        else {
            low = mid + p;
        }
    }
    cout << setprecision(8) << fixed << ans << endl;
}