// DATE: 2020-10-18
// FILENAME: b.cpp
// AUTHOR: Yulin Shen
#include <bits/stdc++.h>
using namespace std;
constexpr long long md = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int ka = 1; ka <= T; ka++) {
        int n; cin >> n;
        cout << "Case #" << ka << ": ";
        map<int, long long> mp;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            int x; cin >> x; mp[i - j] += x;
        }
        long long mx = 0;
        for(auto &p: mp) {
            mx = max(mx, p.second);
        }
        cout << mx << '\n';
    }
    return 0;
}