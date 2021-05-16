/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-16
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

const int maxn = 45;
const int inf = 1e9 + 7;

int n, m, a[maxn][maxn];
LL v[maxn], mi[maxn][maxn][maxn][maxn], dp[maxn][maxn][maxn][maxn];

inline void updmi(LL &x, LL y) { x = min(x, y); }
inline void updma(LL &x, LL y) { x = max(x, y); }

LL solve()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            scd(a[i][j]);
    for(int i1 = 1; i1 <= n; ++ i1)
        for(int i2 = i1; i2 <= n; ++ i2)
        {
            for(int j = 1; j <= m; ++ j)
            {
                v[j] = inf;
                for(int k = i1; k <= i2; ++ k)
                    v[j] = min(v[j], (LL)a[k][j]);
            }
            for(int j1 = 1; j1 <= m; ++ j1)
            {
                mi[i1][j1][i2][j1] = v[j1];
                for(int j2 = j1 + 1; j2 <= m; ++ j2)
                    mi[i1][j1][i2][j2] = min(v[j2], mi[i1][j1][i2][j2 - 1]);
            }
        }
    for(int li = 1; li <= n; ++ li)
        for(int lj = 1; lj <= m; ++ lj)
            for(int xi = 1; xi + li - 1 <= n; ++ xi)
                for(int xj = 1; xj + lj - 1 <= m; ++ xj)
                {
                    int yi = li + xi - 1, yj = lj + xj - 1;
                    dp[xi][xj][yi][yj] = 0;
                    if(li == 1 && lj == 1) continue;
                    for(int k = xi; k < yi; ++ k)
                        updma(dp[xi][xj][yi][yj], dp[xi][xj][k][yj] + dp[k + 1][xj][yi][yj]);
                    for(int k = xj; k < yj; ++ k)
                        updma(dp[xi][xj][yi][yj], dp[xi][xj][yi][k] + dp[xi][k + 1][yi][yj]);
                    dp[xi][xj][yi][yj] += mi[xi][xj][yi][yj];
                }
    return dp[1][1][n][m];
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