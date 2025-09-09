#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        ll c, d;
        cin >> n >> c >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<ll> v;
        v.reserve(n);
        for (int x : a)
            if (v.empty() || v.back() != x)
                v.push_back(x);
        ll ans = (ll)n * c + d;
        int U = v.size();
        for (int k = 1; k <= U; k++) {
            ll m = v[k - 1];
            ll cost = (ll)(n - k) * c + (m - k) * d;
            ans = min(ans, cost);
        }
        cout << ans << "\n";
    }
    return 0;
}
