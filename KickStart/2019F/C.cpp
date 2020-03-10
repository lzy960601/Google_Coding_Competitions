/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-10-01
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
#define lowbit(x) ((x) & (-x))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

const int maxn = 100005;
LL dp[maxn][4], a[maxn];
vi g[maxn];
int T, n;

// 0 = not choose & not cal, 1 = not choose but cal, 2 = choose & cal, 3 = u is leaf ? a[u] : dp[u][1]
void DFS(int u, int f)
{
    int cnt = 0;
    dp[u][0] = dp[u][1] = 0; dp[u][2] = dp[u][3] = a[u];
    for(int p : g[u]) if(p != f) DFS(p, u);
    for(int p : g[u])
    {
        if(p == f) continue; 
        cnt ++;
        dp[u][2] += max(dp[p][0] + a[p], max(dp[p][3], dp[p][2]));
        if(cnt <= 1) dp[u][1] = dp[p][2]; else dp[u][1] = max(dp[p][2] + dp[u][0], max(max(dp[p][0], dp[p][1]), dp[p][2]) + dp[u][1]);
        dp[u][0] += max(dp[p][0], dp[p][1]);
    }  
    if(cnt > 0) {dp[u][1] += a[u]; dp[u][3] = dp[u][1];}
}

int main()
{
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scd(n);
        for(int i = 1; i <= n; ++ i) g[i].clear();
        for(int i = 1; i <= n; ++ i) scld(a[i]);
        for(int i = 1; i < n; ++ i)
        {
            int x, y; scanf("%d%d", &x, &y);
            g[x].pb(y); g[y].pb(x);
        }
        DFS(1, 0);
        prcas; printf("%lld\n", max(dp[1][2], max(dp[1][0], dp[1][1])));
    }
    return 0;
}
