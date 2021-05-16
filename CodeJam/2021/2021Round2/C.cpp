/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-15
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

const int mod = 1e9 + 7;
const int maxn = 100005;
int jc[maxn], iv[maxn];

int mi(int x, int y)
{
    int ret = 1;
    while(y > 0)
    {
        if(y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ret;
}

inline int C(int x, int y) // x >= y 
{ return 1ll * jc[x] * (1ll * iv[y] * iv[x - y] % mod) % mod; }

int n, a[maxn], st[maxn][20], lo[maxn];

int find(int l, int r)
{
    int t = lo[r - l + 1];
    return min(st[l][t], st[r - (1 << t) + 1][t]);
}

int DFS(int l, int r, int u)
{
    if(r < l) return 1;
    int v = find(l, r);
    if(v != u) return 0;
    if(l == r) return 1;
    int lg = l, rg = r;
    while(rg - lg > 1)
    {
        int mid = (lg + rg) >> 1;
        if(find(mid, r) > v) rg = mid; else lg = mid;
    }
    while(find(rg, r) > v) -- rg;
    int s = 1ll * DFS(l, rg - 1, u) * DFS(rg + 1, r, u + 1) % mod;
    return 1ll * C(r - l, rg - l) * s % mod;
}

int solve()
{
    scd(n);
    for(int i = 1; i <= n; ++ i) scd(st[i][0]);
    for(int k = 1; (1 << k) <= n; ++ k)
        for(int i = 1; i + (1 << k) - 1 <= n; ++ i)
            st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
    return DFS(1, n, 1);
}

int main()
{
    lo[1] = 0; for(int i = 2; i <= 100000; ++ i) lo[i] = lo[i >> 1] + 1;
    jc[0] = 1; for(int i = 1; i <= 100000; ++ i) jc[i] = 1ll * jc[i - 1] * i % mod;
    iv[100000] = mi(jc[100000], mod - 2);
    for(int i = 99999; i >= 0; -- i) iv[i] = 1ll * iv[i + 1] * (i + 1) % mod;
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; printf("%d\n", ans);
    }
    return 0;
}