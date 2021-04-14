/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-14
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

const int maxn = 1005;
vi g[maxn];
int onc[maxn], dis[maxn], T, n;

int findc(int u, int f)
{
    dis[u] = 1;
    for(int p : g[u])
    {
        if(p == f) continue;
        if(dis[p])
        {
            onc[u] = 1;
            return p;
        }
        int a = findc(p, u);
        if(a != 0)
        {
            if(a < 0) return a;
            onc[u] = 1;
            if(a == u) return -1; else return a;
        }
    }
    return 0;
}

void DFS(int u, int f, int d)
{
    dis[u] = d;
    for(int p : g[u])
    {
        if(p == f || onc[p] > 0) continue;
        DFS(p, u, d + 1);
    }
}

void solve(int cas)
{
    scd(n);
    for(int i = 1; i <= n; ++ i) g[i].clear(), onc[i] = dis[i] = 0;
    for(int i = 1; i <= n; ++ i)
    {
        int x, y; scanf("%d%d", &x, &y);
        g[x].pb(y); g[y].pb(x);
    }
    findc(1, 0);
    for(int i = 1; i <= n; ++ i)
        if(onc[i]) DFS(i, 0, 0);
    prcas; 
    for(int i = 1; i <= n; ++ i) printf("%d%c", dis[i], i == n ? '\n' : ' ');
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
        solve(cas);
    return 0;
}
