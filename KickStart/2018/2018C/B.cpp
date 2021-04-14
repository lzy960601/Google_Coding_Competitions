/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-14
File: B.cpp
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

int n; LL ans;
vector<pii> g[20];
int ano[20];

void DFS(int id, int sum, int ma, int cnt)
{
    //_debug("%d %d %d %d", id, sum, ma, cnt);
    if(cnt + ((n - id + 1) >> 1) < 3) return;
    if(id > n)
    {
        if((ma << 1) < sum && cnt >= 3) 
            ++ ans;
        return;
    }
    DFS(id + 1, sum, ma, cnt);
    if(ano[id] > 0) return;
    for(pii p : g[id])
    {
        if(ano[p.se] > 0) continue;
        ano[p.se] = id; ano[id] = p.se;
        DFS(id + 1, sum + p.fi, max(ma, p.fi), cnt + 1);
        ano[p.se] = ano[id] = 0;
    }
}

LL solve()
{
    ans = 0;
    scd(n); 
    for(int i = 1; i <= n; ++ i)
    {
        g[i].clear();
        ano[i] = 0;
    }
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
        {
            int x; scd(x);
            if(x == 0) continue;
            if(i < j) g[i].pb(mp(x, j));
        }
    DFS(1, 0, 0, 0);
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
