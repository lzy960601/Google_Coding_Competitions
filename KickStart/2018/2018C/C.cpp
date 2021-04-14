/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-15
File: C.cpp
*****************************************/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")  
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
const int maxn = 1000005;
int T, n, m, a[maxn];

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

void gen()
{
    int x, y, c, d, e1, e2, f;
    scanf("%d%d%d%d%d%d%d", &x, &y, &c, &d, &e1, &e2, &f);
    a[1] = (x + y) % f;
    for(int i = 2; i <= n; ++ i)
    {   
        int nx = ((1ll * x * c % f) + (1ll * y * d % f) + e1) % f;
        int ny = ((1ll * x * d % f) + (1ll * y * c % f) + e2) % f;
        a[i] = (nx + ny) % f;
        x = nx; y = ny;
    }
}

int solve()
{
    scanf("%d%d", &n, &m); gen();
    int ans = 0;

    // a[k] * v[i] for (n - k + 1) times
    // k \in [1, n], i \in [1, k]
    int sumv = 0;
    for(int k = 1; k <= n; ++ k)
    {
        int v = 0;
        if(k == 1) v = m; else v = 1ll * ((LL)k * (mi(k, m) - 1) % mod) * mi(k - 1, mod - 2) % mod;
        (sumv += v) %= mod;

        int s = 1ll * (n - k + 1) * sumv % mod;
        (ans += 1ll * a[k] * s % mod) %= mod;
    }
    return ans;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; printf("%d\n", ans);
    }
    return 0;
}
