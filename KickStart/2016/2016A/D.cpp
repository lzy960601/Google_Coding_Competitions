/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-18
File: D.cpp
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

#define IN freopen("D.in", "r", stdin)
#define OUT freopen("D.out", "w", stdout)
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

const int maxn = 13;
int K[maxn], L[maxn], n;
LL A[maxn][maxn], C[maxn][maxn], m;
vector<pll> g[maxn];

void DFS(vi &ids, int now, int lim, vector<pll> &ret, LL cost, LL attack)
{
    if(now > lim)
    {
        ret.pb(mp(cost, attack));
        return;
    }
    for(pll p : g[ids[now]])
        DFS(ids, now + 1, lim, ret, cost + p.fi, attack + p.se);
}

LL getret(vi &ids)
{
    vector<pll> a, b; a.clear(); b.clear();
    DFS(ids, 0, 3, a, 0ll, 0ll); DFS(ids, 4, 7, b, 0ll, 0ll);
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    vector<LL> c; c.clear();
    for(int i = 0; i < b.size(); ++ i)
        if(i == 0) c.pb(b[i].se); else c.pb(max(c[i - 1], b[i].se));
    LL ans = 0;
    int id = (int)b.size() - 1;
    for(int i = 0; i < a.size(); ++ i)
    {
        while(id >= 0 && b[id].fi + a[i].fi > m) -- id;
        if(id >= 0) ans = max(ans, a[i].se + c[id]); else break;
    }
    return ans;
}

LL solve()
{
    scanf("%lld%d", &m, &n);
    for(int i = 1; i <= n; ++ i)
    {
        scanf("%d%d", &K[i], &L[i]);
        for(int j = 1; j <= K[i]; ++ j) scanf("%lld", &A[i][j]);
        for(int j = 1; j < K[i]; ++ j) scanf("%lld", &C[i][j]);
        g[i].clear(); LL sum = 0;
        for(int j = L[i]; j <= K[i]; ++ j)
        {
            g[i].pb(mp(sum, A[i][j]));
            sum += C[i][j];
        }
    }
    LL ans = 0;
    for(int mask = 0; mask < (1 << n); ++ mask)
    {
        vi ids; ids.clear();
        int cnt = 0;
        for(int k = 0; k < n; ++ k)
            if( (mask >> k) & 1 )
            {
                ++ cnt;
                ids.pb(k + 1);
            }
        if(cnt != 8) continue;
        ans = max(ans, getret(ids));
    }
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