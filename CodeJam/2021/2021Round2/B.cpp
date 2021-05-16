/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-15
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

const int maxn = 1000005;
int dp[maxn][2];
vector<int> g[maxn];

void pre()
{
    for(int i = 2; i <= 1000000; ++ i)
        for(int j = 2 * i; j <= 1000000; j += i)
            g[j].pb(i);
}

int main()
{
    pre();
    dp[2][1] = 1;
    for(int k = 3; k <= 1000000; ++ k)
    {
        dp[k][1] = 1;
        for(int p : g[k])
            dp[k][1] = max(dp[k][1], dp[k / p - 1][1] + 1);
    }
    for(int k = 3; k <= 1000000; ++ k)
    {
        dp[k][0] = 1;
        for(int p : g[k])
            if(p >= 3) dp[k][0] = max(dp[k][0], dp[k / p - 1][1] + 1);
    }
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int x; scd(x);
        prcas; printf("%d\n", dp[x][0]);
    }
    return 0;
}