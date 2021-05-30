/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-30
File: B.cpp
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

#define IN freopen("B.in", "r", stdin)
#define OUT freopen("B.out", "w", stdout)
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

const int maxn = 3005;
int a[maxn][maxn], n, m, K;

LL solve()
{
    scanf("%d%d%d", &n, &m, &K);
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            a[i][j] = 1;
    while(K --)
    {
        int x, y; scanf("%d%d", &x, &y);
        ++ x; ++ y;
        a[x][y] = 0;
    }
    LL ans = 0;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
        {
            if(a[i][j] == 0) continue;
            int v = min(a[i - 1][j], a[i][j - 1]);
            if(a[i - v][j - v] > 0) a[i][j] = v + 1; else a[i][j] = v;
            ans += a[i][j];
        }
    return ans;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        LL ans = solve();
        prcas; printf("%lld\n", ans);
    }
    return 0;
}