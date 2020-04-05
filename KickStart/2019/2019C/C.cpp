/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-05-26
File: C.cpp
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

#define LL long long
#define IN freopen("sample.in", "r", stdin)
#define OUT freopen("sample.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas(x) printf("Case #%d: ", x)
#define pncas(x) printf("Case #%d:\n", x)
#define lowbit(x) (x & (-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

const int maxn = 1005;
vi g[maxn];
int n, m, T, a[maxn], b[maxn];
int dp[maxn][maxn][2];

int main()
{
  	scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scd(n); scd(m);
        for(int i = 1; i <= 1000; ++ i) g[i].clear();
        for(int i = 1; i <= n; ++ i) scd(a[i]);
        for(int i = 1; i <= n; ++ i) scd(b[i]);
        for(int i = 1; i <= n; ++ i) g[b[i]].pb(a[i]);
        for(int i = 1; i <= 1000; ++ i) sort(g[i].begin(), g[i].end());
        for(int i = 0; i <= 1000; ++ i)
            for(int j = 0; j <= 1000; ++ j)
                dp[i][j][0] = dp[i][j][1] = 1e9;
        for(int i = 0; i <= 1000; ++ i) dp[i][0][0] = dp[i][0][1] = 0;
        for(int i = 1; i <= 1000; ++ i)
        {
            for(int k = 0; k <= m; ++ k) dp[i][k][0] = dp[i - 1][k][0], dp[i][k][1] = dp[i - 1][k][1];
            for(int j = 0; j < g[i].size(); ++ j)
            {
                int o = j + 1, d = g[i][j];
                for(int k = o; k <= m; ++ k)
                {
                    dp[i][k][0] = min(dp[i][k][0], dp[i - 1][k - o][0] + 2 * d);
                    dp[i][k][1] = min(dp[i][k][1], dp[i - 1][k - o][0] + d);
                    dp[i][k][1] = min(dp[i][k][1], dp[i - 1][k - o][1] + 2 * d);
                }
            }
        }
        int ans = 1e9;
        for(int i = 1; i <= 1000; ++ i) ans = min(ans, dp[i][m][1]);
        prcas(cas); printf("%d\n", ans);
    }
    return 0;
}
