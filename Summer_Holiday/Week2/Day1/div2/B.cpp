#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n % 2 == 0) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> rev_ops;
        while (n > 1) {
            long long down = (n - 1) / 2;
            long long up   = (n + 1) / 2;
            if (down % 2 == 1) {
                rev_ops.push_back(2);
                n = down;
            } else {
                rev_ops.push_back(1);
                n = up;
            }
        }
        reverse(rev_ops.begin(), rev_ops.end());
        cout << rev_ops.size() << '\n';
        for (int op : rev_ops) cout << op << ' ';
        cout << '\n';
    }
    return 0;
}