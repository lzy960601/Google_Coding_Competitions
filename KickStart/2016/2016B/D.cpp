/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-19
File: D.cpp
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

#define IN freopen("D.in", "r", stdin)
#define OUT freopen("D.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
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

int n, M, dp[5005][3], jc[5005], cut[5005];

int solve()
{
    scanf("%d%d", &n, &M);
    jc[0] = 1;
    for(int i = 1; i <= n; ++ i) jc[i] = 1ll * jc[i - 1] * i % M;
    
    // cannot cut
    cut[1] = 1;
    for(int i = 2; i <= n; ++ i)
    {
        int sum = 0;
        for(int k = 1; k < i; ++ k)
            (sum += 1ll * cut[k] * jc[i - k] % M) %= M;
        cut[i] = (jc[i] + M - sum) % M;
    }

    dp[0][0] = 1; dp[0][1] = dp[0][2] = 0;
    for(int i = 1; i <= n; ++ i)
    {
        dp[i][0] = dp[i][1] = dp[i][2] = 0;
        for(int k = 1; k <= i; ++ k)
        {
            int f = cut[k], p = i - k;
            int v0 = dp
            (dp[i][0] += 1ll * dp[p][0] * f % mod) %= mod;

        }
    }
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; printf("%d\n", ans);
    }
    return 0;
}