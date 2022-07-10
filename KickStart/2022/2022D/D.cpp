/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2022-07-10
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
vi g[maxn], gg[maxn];
int pre[maxn],low[maxn],sccno[maxn],tot[maxn], deg[maxn];
int dfs_clock,scc_cnt,maxx;
stack<int> s;

void dfs(int u)
{
	pre[u]=low[u]=++dfs_clock;
	s.push(u);
	for(int v : g[u])
	{
		if(!pre[v])
		{
			dfs(v);
			low[u]=min(low[u],low[v]);
		}else if(!sccno[v])low[u]=min(low[u],pre[v]);
	}
	if(low[u]==pre[u])
	{
		scc_cnt++;
		for(;;)
		{
			int x=s.top();s.pop();
			sccno[x]=scc_cnt;
            tot[scc_cnt] ++;
			if(x==u)break;
		}
	}
}

void find(int n)
{
	dfs_clock = scc_cnt = 0;
    for(int i = 1; i <= n; ++ i) sccno[i] = pre[i] = low[i] = tot[i] = 0;
	while(!s.empty()) s.pop();
	for(int i = 1; i <= n; ++ i) if(!pre[i]) dfs(i);
}

int n, m, k;
vector<pii> rec;
set<int> cov[maxn];

int solve()
{
    scanf("%d%d%d", &n, &m, &k); rec.clear();
    for(int i = 1; i <= n; ++ i) g[i].clear();
    while(m --)
    {
        int x, y; scanf("%d%d", &x, &y);
        g[y].pb(x);
        rec.pb(mp(x, y));
    }
    find(n);
    for(int i = 1; i <= scc_cnt; ++ i)
    {
        deg[i] = 0;
        gg[i].clear();
        cov[i].clear();
    }
    for(pii p : rec)
    {
        int x = sccno[p.fi], y = sccno[p.se];
        if(x == y) continue;
        gg[x].pb(y); deg[y] ++;
        cov[y].insert(x);
    }
    int ans = 0;
    queue<int> q; while(!q.empty()) q.pop();
    for(int i = 1; i <= scc_cnt; ++ i) if(deg[i] == 0) q.push(i);
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        int ma = tot[v], su = tot[v];
        for(int p : cov[v]) if(p != v) su += tot[p];
        if(su > k)
        {
            ans += tot[v];
            tot[v] = k + 1;
        }else{
            for(int p : cov[v])
                for(int pp : cov[p])
                    cov[v].insert(pp);
            for(int p : cov[v]) if(p != v) ma += tot[p];
            if(ma > k) { ans += tot[v]; tot[v] = k + 1; }
        }
        for(int p : gg[v])
        {
            deg[p] --;
            if(deg[p] == 0) q.push(p);
        }
    }
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