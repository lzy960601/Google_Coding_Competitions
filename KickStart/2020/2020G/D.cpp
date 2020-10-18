// DATE: 2020-10-18
// FILENAME: d.cpp
// AUTHOR: Yulin Shen
#include <bits/stdc++.h>
using namespace std;
constexpr long long md = 998244353;

int n;
double arr[5050];
double aa[5050];
double dp[5050][5050];
double dpqz[5050];
double dphz[5050];

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    partial_sum(arr, arr + n, aa + 1);
    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) dp[i][j] = 0;
    for(int i = 0; i <= n; i++) dpqz[i] = dphz[i] = 0;
    for(int l = 2; l <= n; l++) {
        for(int i = 0; i + l <= n; i++) {
            int j = i + l;
            dp[i][j] = dpqz[i] + dphz[j];
            dp[i][j] /= (l - 1);
            dp[i][j] += aa[j] - aa[i];
            dpqz[i] += dp[i][j];
            dphz[j] += dp[i][j];
        }
    }
    printf("%.10lf\n", dp[0][n]);
}

int main() {
    int T; cin >> T; for(int ka = 1; ka <= T; ka++) {
        cout << "Case #" << ka << ": ";
        solve();
    }
    return 0;
}
