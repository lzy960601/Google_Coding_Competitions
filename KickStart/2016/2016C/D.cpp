/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-21
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

int n;
pii a[4005];

bool solve()
{
    scd(n);
    for(int i = 1; i <= n; ++ i) scanf("%d%d", &a[i].fi, &a[i].se);
    int x = 1, y = 1;
    while(x > 0)
    {
        x = 0; y = 0;
        for(int i = 1; i <= n; ++ i)
        {
            if(a[i].fi <= 0) continue;
            x = max(x, a[i].fi);
            y = max(y, a[i].se);
        }
        for(int i = 1; i <= n; ++ i)
            if(x == a[i].fi && y == a[i].se) return true;
        for(int i = 1; i <= n; ++ i)
            if(x == a[i].fi || y == a[i].se) a[i] = mp(-1, -1);
    }
    return false;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        bool ans = solve();
        prcas; puts(ans ? "YES" : "NO");
    }
    return 0;
}