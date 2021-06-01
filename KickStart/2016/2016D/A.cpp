/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-06-02
File: A.cpp
*****************************************/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
const double eln = 2.718281828459045235360287471352;

#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", \
    __func__, ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif

#define IN freopen("A.in", "r", stdin)
#define OUT freopen("A.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define rng(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-(x)))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

double dp[2005][2005];

double solve()
{
    int n, m; scanf("%d%d", &n, &m);
    dp[1][0] = (double)n / (n + m);
    for(int sum = 2; sum <= n + m; ++ sum)
        for(int i = 1; i <= min(sum, n); ++ i)
        {
            int j = sum - i;
            if(i <= j) { dp[i][j] = 0; continue; }
            dp[i][j] = 0;
            dp[i][j] += dp[i - 1][j] * ((double)(n - i + 1) / (n - i + 1 + m - j));
            if(j > 0) dp[i][j] += dp[i][j - 1] * ((double)(m - j + 1) / (n - i + 1 + m - j));
        }
    return dp[n][m];
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        double ans = solve();
        prcas; printf("%.12f\n", ans);
    }
    return 0;
}