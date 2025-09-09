#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool p = 0;
        for(int i = 1; i <= n; i++){
            long long x;
            cin >> x;
            if(!p && x <= i)p = 1;
        }
        cout << (p ? "YES\n" : "NO\n");
    }
    return 0;
}