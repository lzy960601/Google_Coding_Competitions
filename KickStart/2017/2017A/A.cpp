/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-01
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

const int mod = 1e9 + 7;

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

int cal3(int n)
{
    int s = 1ll * n * (n + 1) % mod;
    s = 1ll * s * s % mod;
    return 1ll * s * mi(4, mod - 2) % mod;
}

int cal2(int n)
{
    int s = 1ll * n * (n + 1) % mod;
    s = 1ll * s * (n * 2 + 1) % mod;
    return 1ll * s * mi(6, mod - 2) % mod;
}

int cal1(int n)
{
    int s = 1ll * n * (n + 1) % mod;
    return 1ll * s * mi(2, mod - 2) % mod;
}

int solve()
{
    int n, m; scanf("%d%d", &n, &m); -- n; -- m;
    if(n > m) swap(n, m);
    int s1 = cal1(n), s2 = cal2(n), s3 = cal3(n);
    int ans = s3;
    (ans += mod - (1ll * s2 * (n + m + 2) % mod)) %= mod;
    (ans += 1ll * (1ll * (n + 1) * (m + 1) % mod) * s1 % mod ) %= mod;
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
