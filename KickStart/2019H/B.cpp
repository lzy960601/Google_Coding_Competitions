/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-11-18
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

const int maxn = 105;
char s[maxn];
vector<pii> g[maxn << 2];
int n, T, ans, cnt[maxn << 2], all;
int vis[2][maxn << 2], col[maxn << 2];

void DFS(int u, int c, int s, int &cnt)
{
    if(vis[s][u])
    {
        if(c != col[u]) cnt = 1e9 + 7;
        return;
    }
    vis[s][u] = 1; col[u] = c; if(c == 1) cnt ++;
    for(pii p : g[u]) DFS(p.fi, c ^ p.se, s, cnt);
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scd(n); ans = 0; all = 4 * n - 2;
        for(int i = 1; i <= all; ++ i) g[i].clear();
        for(int i = 1; i <= all; ++ i) vis[0][i] = vis[1][i] = 0;
        for(int i = 1; i <= n; ++ i)
        {
            scs(s + 1);
            for(int j = 1; j <= n; ++ j)
            {
                int x = i + j - 1;
                int y = i - j + n - 1 + 2 * n;
                int v = (s[j] == '.');
                g[x].pb(mp(y, v)); g[y].pb(mp(x, v));
            }
        }
        for(int i = 1; i <= all; ++ i)
        {
            if(vis[0][i]) continue;
            int cx = 0, cy = 0;
            DFS(i, 0, 0, cx); DFS(i, 1, 1, cy);
            ans += min(cx, cy);
        }
        prcas; printf("%d\n", ans);
    }
    return 0;
}
