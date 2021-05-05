/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-05
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

int solve(LL minv, LL maxv, LL mea, LL mdi)
{
    if(!(minv <= maxv && mea >= minv && mea <= maxv && mdi >= minv && mdi <= maxv)) return -1;
    if(mea == minv && (mdi != minv || maxv != minv)) return -1;
    if(mea == maxv && (mdi != maxv || maxv != minv)) return -1;
    if(minv == maxv && mea == maxv && mdi == maxv) return 1;
    if((mdi == mea) && (2ll * mdi == maxv + minv)) return 2;
    for(int i = 3; i <= 1000000; ++ i)
    {
        LL sum = mea * i;
        LL half = (i & 1) ? (i - 1) >> 1 : (i - 2) >> 1;
        sum -= (i & 1) ? mdi : mdi << 1;
        sum -= (minv * half + maxv * half);
        if(sum == 0) return i;
        LL pos = (mdi - minv) * (half - 1), neg = (maxv - mdi) * (half - 1);
        if(sum + neg >= 0 && sum <= pos) return i;
    }
    return -1;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        LL a, b, c, d; scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        int ans = solve(a, b, c, d);
        prcas; 
        if(ans < 0) puts("IMPOSSIBLE"); else printf("%d\n", ans);
    }
    return 0;
}