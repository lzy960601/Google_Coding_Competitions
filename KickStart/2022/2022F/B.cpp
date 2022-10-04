/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2022-10-04
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
#define rng(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
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

const int maxn = 100005;
int level[maxn], Q, N, a[maxn];
vi g[maxn];

void DFS(int u, int f, int lv)
{
    level[lv] ++; a[u] = lv;
    for(int p : g[u]) if(p != f) DFS(p, u, lv + 1);
}

int solve()
{
    scanf("%d%d", &N, &Q);
    for(int i = 1; i <= N; ++ i) g[i].clear(), level[i] = a[i] = 0;
    for(int i = 1; i < N; ++ i)
    {
        int x, y; scanf("%d%d", &x, &y);
        g[x].pb(y); g[y].pb(x);
    }
    DFS(1, 0, 1);
    int curlv = 1;
    while(Q --)
    {
        int x; scd(x);
        level[curlv] --;
        if(level[curlv] == 0) curlv ++;
    }
    int ans = 0;
    for(int i = 1; i <= N; ++ i) if(a[i] < curlv) ans ++;
    return ans;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; printf("%d\n", ans);
    }
    return 0;
}