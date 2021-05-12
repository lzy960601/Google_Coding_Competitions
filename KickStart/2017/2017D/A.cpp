/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-09
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

const int maxn = 2005;
const LL inf = 1e18L;
int n;
LL ts, tf;
struct city
{
    LL s, f, d;
    void read() { scanf("%lld%lld%lld", &s, &f, &d); }
}c[maxn];
LL dp[maxn][maxn];

LL nxt(int id, LL t)
{
    LL base = max(t - c[id].s, 0ll);
    LL bg = c[id].s + ((base + c[id].f - 1) / c[id].f) * c[id].f;
    return bg + c[id].d;
}

int solve()
{
    scanf("%d%lld%lld", &n, &ts, &tf);
    for(int i = 1; i < n; ++ i) c[i].read();
    dp[1][0] = 0;
    for(int i = 1; i < n; ++ i)
    {
        dp[i][i] = inf;
        for(int j = 0; j <= i; ++ j) dp[i + 1][j] = inf;
        dp[i + 1][0] = nxt(i, dp[i][0]);
        for(int j = 1; j <= i; ++ j)
            dp[i + 1][j] = min(nxt(i, dp[i][j]), nxt(i, dp[i][j - 1] + ts));
    }
    int id = n - 1;
    while(id >= 0 && dp[n][id] > tf) -- id;
    return id;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; if(ans >= 0) printf("%d\n", ans); else puts("IMPOSSIBLE");
    }
    return 0;
}