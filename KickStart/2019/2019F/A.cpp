/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-10-01
File: A.cpp
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
#define lowbit(x) ((x) & (-x))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

const int maxn = 105;
int cnt[1005], a[maxn], b[maxn][maxn], dp[maxn][maxn];
int T, n, m;

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &m); m ++;
        for(int i = 1; i <= n; ++ i) scd(a[i]);
        for(int i = 1; i <= n; ++ i)
        {
            int ma = 0;
            for(int j = i; j <= n; ++ j) cnt[a[j]] = 0;
            for(int j = i; j <= n; ++ j)
            {
                ma = max(ma, ++ cnt[a[j]]);
                b[i][j] = j - i + 1 - ma;
            }
        }
        for(int i = 0; i <= n; ++ i)
            for(int j = 0; j <= m; ++ j)
                dp[i][j] = 1e9 + 7;
        dp[1][1] = dp[0][0] = 0;
        for(int i = 2; i <= n; ++ i)
            for(int j = 1; j <= m; ++ j)
                for(int k = 1; k <= i; ++ k)
                    dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + b[k][i]);
        int ans = 1e9 + 7;
        for(int i = 1; i <= m; ++ i) ans = min(ans, dp[n][i]);
        prcas; printf("%d\n", ans);
    }
    return 0;
}
