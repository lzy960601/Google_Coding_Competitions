/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-06-01
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

const int maxn = 10005;
const LL inf = 1e18l;

struct Rope
{
    int A, B;
    LL P;
    void read() { scanf("%d%d%lld", &A, &B, &P); }
}a[maxn];
LL dp[maxn], st[maxn][15];
int lo[maxn], n, L; LL m;

void gen_st(int l, int r)
{
    for(int i = l; i <= r; ++ i)
        st[i][0] = dp[i];
    for(int k = 1; (1 << k) <= r - l + 1; ++ k)
        for(int i = l; i + (1 << k) - 1 <= r; ++ i)
            st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
}

LL find(int l, int r)
{
    int t = lo[r - l + 1];
    return min(st[l][t], st[r - (1 << t) + 1][t]);
}

LL solve()
{
    scanf("%d%lld%d", &n, &m, &L);
    for(int i = 0; i <= L; ++ i) dp[i] = inf;
    for(int i = 1; i <= n; ++ i) a[i].read();
    dp[0] = 0;
    for(int i = 1; i <= n; ++ i)
    {
        gen_st(0, L);
        for(int k = L; k >= 0; -- k)
        {
            if(k < a[i].A) break;
            int l = max(0, k - a[i].B), r = k - a[i].A;
            dp[k] = min(dp[k], find(l, r) + a[i].P);
        }
    }
    return dp[L] <= m ? dp[L] : inf;
}

int main()
{
    lo[1] = 0; for(int i = 2; i < maxn; ++ i) lo[i] = lo[i >> 1] + 1;
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        LL ans = solve();
        prcas; 
        if(ans == inf) puts("IMPOSSIBLE"); else printf("%lld\n", ans);
    }
    return 0;
}