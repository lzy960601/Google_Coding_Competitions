/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2022-07-10
File: C.cpp
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

#define IN freopen("C.in", "r", stdin)
#define OUT freopen("C.out", "w", stdout)
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

const int maxn = 2505;
const int inf = 1e9 + 7;
int dp[maxn][maxn], n, m, a[maxn], b[maxn];

int solve()
{
    int tn = 0, last = 0; n = 0;
    scanf("%d", &tn);
    while(tn --)
    {
        int x; scd(x);
        if(x != last) 
        {
            a[++ n] = x;
            last = x;
        }
    }
    scd(m);
    for(int i = 1; i <= m; ++ i) scd(b[i]);
    for(int i = 1; i <= m; ++ i) dp[0][i] = 0;
    for(int step = 1; step <= n; ++ step)
    {
        int mi = inf;
        for(int i = 1; i <= m; ++ i) dp[step][i] = inf + m;
        for(int i = 1; i <= m; ++ i)
        {
            mi = min(dp[step - 1][i] - i, mi);
            if(b[i] == a[step]) dp[step][i] = min(dp[step][i], mi + i);
        }
        mi = inf;
        for(int i = m; i >= 1; -- i)
        {
            mi = min(dp[step - 1][i] + i, mi);
            if(b[i] == a[step]) dp[step][i] = min(dp[step][i], mi - i);
        }
    }
    int ans = inf;
    for(int i = 1; i <= m; ++ i) ans = min(ans, dp[n][i]);
    return ans;
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