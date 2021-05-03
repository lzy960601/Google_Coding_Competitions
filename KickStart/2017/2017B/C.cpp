/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-02
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

const int maxn = 105;
int lo[105], dp[maxn][maxn][maxn], tri[maxn][maxn];
char s[maxn][maxn];

struct ST
{
    int v[maxn][10];

    void init(int a[], int len)
    {
        for(int i = 1; i <= len; ++ i) v[i][0] = a[i];
        for(int k = 1; (1 << k) <= len; ++ k)
            for(int i = 1; i + (1 << k) - 1 <= len; ++ i)
                v[i][k] = max(v[i][k - 1], v[i + (1 << (k - 1))][k - 1]);
    }

    int find(int l, int r)
    {
        int t = lo[r - l + 1];
        return max(v[l][t], v[r - (1 << t) + 1][t]);
    }
}st[maxn];

int solve()
{
    int n, m, K; 
    scanf("%d%d%d", &n, &m, &K);
    for(int i = 1; i <= n; ++ i) scs(s[i] + 1);
    for(int i = 1; i <= m; ++ i) tri[n + 1][i] = 0;
    st[n + 1].init(tri[n + 1], m);
    for(int i = n; i >= 1; -- i)
        for(int j = 1; j <= m; ++ j)
        {
            if(s[i][j] == '.') { tri[i][j] = 0; continue; }
            if(j <= 1 || j >= m) { tri[i][j] = 1; continue; }
            tri[i][j] = min(min(tri[i + 1][j - 1], tri[i + 1][j + 1]), tri[i + 1][j]) + 1;
        }
    for(int k = 1; k <= K; ++ k)
    {
        for(int i = n; i >= 1; -- i)
            for(int j = 1; j <= m; ++ j)
            {
                dp[k][i][j] = 0;
                if(k == 1)
                {
                    dp[k][i][j] = sqr(tri[i][j]);
                    continue; 
                }
                int maxv = tri[i][j];
                for(int v = 1; v <= maxv; ++ v)
                {
                    int tv = st[i + v].find(j - v + 1, j + v - 1);
                    if(tv > 0) dp[k][i][j] = max(dp[k][i][j], tv + sqr(v));
                }
            }
        for(int i = 1; i <= n; ++ i) st[i].init(dp[k][i], m);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            ans = max(ans, dp[K][i][j]);
    return ans;
}

int main()
{
    lo[1] = 0; for(int i = 2; i < maxn; ++ i) lo[i] = lo[i >> 1] + 1;
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; printf("%d\n", ans);
    }
    return 0;
}