/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-03-22
File: B.cpp
*****************************************/
  
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

int T, n, k, p;
LL dp[55][1505];
LL val[55][35];

int main()
{
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d%d", &n, &k, &p);
        for(int i = 1; i <= n; ++ i)
        {
            val[i][0] = 0;
            for(int j = 1; j <= k; ++ j)
            {
                int x; scd(x);
                val[i][j] = val[i][j - 1] + x;
            }
        }
        LL ans = 0;
        for(int i = 0; i <= n; ++ i)
            for(int j = 0; j <= p; ++ j)
                dp[i][j] = 0;
        for(int i = 1; i <= n; ++ i)
            for(int j = 0; j <= k; ++ j)
                for(int u = j; u <= p; ++ u)
                {
                    dp[i][u] = max(dp[i][u], dp[i - 1][u - j] + val[i][j]);
                    ans = max(ans, dp[i][u]);
                }
        prcas; printf("%lld\n", ans);
    }
    return 0;
}
