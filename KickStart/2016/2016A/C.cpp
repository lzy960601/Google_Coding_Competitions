/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-18
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
double c[maxn];
int n;

double f(double v)
{
    double p = 1, ret = 0;
    for(int i = n; i >= 0; -- i)
    {
        ret += p * c[i];
        p *= v;
    }
    return ret;
}

double solve()
{
    scd(n);
    for(int i = 0; i <= n; ++ i) scanf("%lf", &c[i]);
    c[0] = -c[0];
    double l = 0, r = 2;
    int cnt = 100;
    while(cnt --)
    {
        double mid = (l + r) * 0.5;
        if(f(mid) < 0) r = mid; else l = mid;
    }
    return l - 1;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        double ans = solve();
        prcas; printf("%.12f\n", ans);
    }
    return 0;
}