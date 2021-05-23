/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-23
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

bool check(LL x, LL y)
{
    if(x < y) return false;
    if((x + y) % 2 == 0) return false;
    LL v = x + y - 1;
    LL B = v >> 1;
    LL A = x - B;
    return A > 0 && B > 0;
}

LL solve()
{
    LL n; scld(n); n <<= 1;
    int ans = 0;
    for(LL i = 1; i * i <= n; ++ i)
    {
        if(n % i > 0) continue;
        if(i * i == n)
        {
            if(check(i, i)) ++ ans;
            continue;
        }
        if(check(i, n / i) || check(n / i, i)) ++ ans;
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