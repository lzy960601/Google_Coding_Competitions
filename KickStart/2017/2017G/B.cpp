/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-16
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
const int inf = (1 << 30) + 10;

int a[maxn][2], n, val[maxn];

LL solve()
{
    scd(n);
    for(int i = 1; i <= n; ++ i) scd(a[i][0]);
    for(int i = 1; i <= n; ++ i) scd(a[i][1]);
    for(int i = 1; i <= n; ++ i) val[i] = 0;
    val[1] = inf; LL ans = 0;
    for(int i = 2; i <= n; ++ i) val[i] = min(a[i][0] ^ a[1][1], a[i][1] ^ a[1][0]);
    for(int i = 1; i < n; ++ i)
    {
        int pos = -1;
        for(int k = 1; k <= n; ++ k)
            if(pos < 0 || val[k] < val[pos]) pos = k;
        ans += val[pos]; val[pos] = inf;
        for(int k = 1; k <= n; ++ k)
        {
            if(val[k] >= inf) continue;
            val[k] = min(val[k], min(a[k][0] ^ a[pos][1], a[k][1] ^ a[pos][0]));
        }
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