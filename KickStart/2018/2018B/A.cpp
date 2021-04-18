/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-17
File: A.cpp
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


LL dp[20][9][2];

LL cal(LL num)
{
    int a[20], ac = 0;
    while(num > 0)
    {
        a[++ ac] = num % 10;
        num /= 10;
    }
    for(int k = 0; k < 9; ++ k)
        dp[0][k][0] = dp[0][k][1] = 0;
    dp[0][0][1] = 1;
    for(int i = 1; i <= ac; ++ i)
    {
        int v = a[ac - i + 1];
        for(int k = 0; k < 9; ++ k)
            dp[i][k][0] = dp[i][k][1] = 0;
        for(int lm = 0; lm < 9; ++ lm)
            for(int v1 = 0; v1 < 9; ++ v1)
            {
                dp[i][(v1 + lm) % 9][0] += dp[i - 1][lm][0];
                if(v1 < v) dp[i][(v1 + lm) % 9][0] += dp[i - 1][lm][1];
                if(v1 == v) dp[i][(v1 + lm) % 9][1] += dp[i - 1][lm][1];
            }
    }
    LL ans = 0;
    for(int mo = 1; mo < 9; ++ mo)
        ans += dp[ac][mo][0] + dp[ac][mo][1];
    return ans;
}

LL solve()
{
    LL x, y;
    scanf("%lld%lld", &x, &y);
    return cal(y) - cal(x) + 1;
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
