// DATE: 2020-10-18
// FILENAME: c.cpp
// AUTHOR: Yulin Shen
#include <bits/stdc++.h>
using namespace std;
constexpr long long md = 998244353;

int w, n;
long long arr[500010];
long long qzh[500010];

void solve() {
    cin >> w >> n;
    for(int i = 0; i < w; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + w);
    for(int i = 0; i < w; i++) {
        arr[i + w] = arr[i] + n;
        arr[i + w + w] = arr[i] + n + n;
    }
    partial_sum(arr, arr + w * 3, qzh + 1);
    long long fv = LLONG_MAX;
    for(int i = w; i < 2 * w; i++) {
        // bkwd: j - i
        // fwd: i + n - j
        // bkwd <= fwd => j - i <= i + n - j => j <= i + n / 2 
        // 0 1 2 3 4
        long long cur = arr[i];
        long long nxt = n % 2 ? (arr[i] + n / 2 + 1) : (arr[i] + n / 2);
        long long prv = arr[i] - n / 2;
        long long nxtp = lower_bound(arr, arr + w * 3, nxt) - arr;
        long long prvp = lower_bound(arr, arr + w * 3, prv) - arr;
        // bkwd
        long long vb = (qzh[nxtp] - qzh[i]) - 1ll * cur * (nxtp - i);
        // fwd
        long long vf = 1ll * (cur) * (i - prvp) - (qzh[i] - qzh[prvp]);
        fv = min(fv, vb + vf);
    }
    cout << fv << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for(int ka = 1; ka <= T; ka++) {
        cout << "Case #" << ka << ": ";
        solve();
    }
    return 0;
}