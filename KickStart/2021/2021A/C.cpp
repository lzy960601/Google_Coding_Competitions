/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-03-21
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
#define lowbit(x) ((x) & (-(x)))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

int T, n, m;
int a[305][305], b[305][305], v[305][305];
priority_queue<pair<int, pii>> q;

bool legal(int x, int y) { return x >= 1 && y >= 1 && x <= n && y<= m; }

void upd(int h, int x, int y)
{
    if(!legal(x, y)) return;
    if(a[x][y] >= h - 1) return;
    a[x][y] = h - 1;
    q.push(mp(a[x][y], mp(x, y)));
}

LL solve()
{
    scanf("%d%d", &n, &m);
    while(!q.empty()) q.pop();
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
        {
            scd(a[i][j]); b[i][j] = a[i][j]; v[i][j] = 0;
            q.push(mp(a[i][j], mp(i, j)));
        }
    while(!q.empty())
    {
        int h = q.top().fi, x = q.top().se.fi, y = q.top().se.se;
        q.pop();
        v[x][y] = 1;
        upd(h, x - 1, y);
        upd(h, x + 1, y);
        upd(h, x, y - 1);
        upd(h, x, y + 1);
        while(!q.empty() && v[q.top().se.fi][q.top().se.se] > 0) q.pop();
    }
    LL ans = 0;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            ans += a[i][j] - b[i][j];
    return ans;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        prcas;
        printf("%lld\n", solve());
    }
    return 0;
}
