/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-04
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
const int maxn = 10005;
int er[maxn], a[maxn], n;

int solve()
{
    scd(n); int ans = 0;
    for(int i = 1; i <= n; ++ i) scd(a[i]);
    for(int i = 1; i < n; ++ i)
        for(int j = i + 1; j <= n; ++ j)
            (ans += 1ll * (a[j] - a[i]) * er[j - i - 1] % mod) %= mod;
    return ans;
}

int main()
{
    er[0] = 1; for(int i = 1; i < maxn; ++ i) er[i] = 2ll * er[i - 1] % mod;
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; printf("%d\n", ans);
    }
    return 0;
}