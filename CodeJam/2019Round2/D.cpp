/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-05-20
File: D.cpp
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
const double eln = 2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("sample.in", "r", stdin)
#define OUT freopen("sample.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr1(x) printf("Case %d: ", x)
#define pn1(x) printf("Case %d:\n", x)
#define pr2(x) printf("Case #%d: ", x)
#define pn2(x) printf("Case #%d:\n", x)
#define lowbit(x) (x & (-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

const int maxn = 100005;
const int mod = 1e9 + 7;

vector<int> g[maxn], gr[maxn], gcc[maxn];
bool canvis[maxn], subg[maxn];
int a[maxn], tot[maxn], path[maxn], label[maxn];
int T, n, sccno[maxn], pre[maxn], low[maxn], deg[maxn], scc_cnt, dfs_clock;
queue<int> q;
stack<int> s;

void dfs(int u)
{
	pre[u] = low[u] = ++ dfs_clock;
	s.push(u);
	for(int v : g[u])
	{
        if(v == u) continue;
		if(!pre[v])
		{
			dfs(v);
			low[u] = min(low[u], low[v]);
		}else if(!sccno[v]) low[u] = min(low[u], pre[v]);
	}
	if(low[u] == pre[u])
	{
		scc_cnt ++;
		for(;;)
		{
			int x = s.top(); s.pop();
			sccno[x] = scc_cnt;
			if(x == u)break;
		}
	}
}

void SCC(int nodenum)
{
    scc_cnt = dfs_clock = 0;
    for(int i = 1; i <= nodenum; ++ i) sccno[i] = pre[i] = low[i] = tot[i] = 0;
    while(!s.empty()) s.pop();
    for(int i = 1; i <= nodenum; ++ i) if(canvis[i] && pre[i] == 0) dfs(i);
}

void dfs_re(int u)
{
	pre[u] = low[u] = ++ dfs_clock;
	s.push(u);
	for(int v : gr[u])
	{
        if(v == u || !subg[v]) continue;
		if(!pre[v])
		{
			dfs_re(v);
			low[u] = min(low[u], low[v]);
		}else if(!sccno[v]) low[u] = min(low[u], pre[v]);
	}
	if(low[u] == pre[u])
	{
		scc_cnt ++;
		for(;;)
		{
			int x = s.top(); s.pop();
			sccno[x] = scc_cnt;
            tot[scc_cnt] = (tot[scc_cnt] + a[x]) % mod;
			if(x == u)break;
		}
	}
}

void SCC_re(int nodenum)
{
    scc_cnt = dfs_clock = 0;
    for(int i = 1; i <= nodenum; ++ i) sccno[i] = pre[i] = low[i] = tot[i] = 0;
    while(!s.empty()) s.pop();
    dfs_re(1);
}

int main()
{
  	scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i) g[i].clear(), gr[i].clear(), gcc[i].clear(), canvis[i] = false, subg[i] = false, path[i] = 0, deg[i] = 0;
        for(int i = 1; i <= n; ++ i)
        {
            int x, y; scd(x); scd(y);
            g[i].pb(x); g[i].pb(y);
        }
        // Exclude useless nodes
        while(!q.empty()) q.pop();
        for(int i = 1; i <= n; ++ i)
        {
            scd(a[i]);
            if(a[i] > 0) {q.push(i); canvis[i] = true;}
        }
        while(!q.empty())
        {
            int x = q.front(); q.pop();
            for(int p : g[x])
            {
                if(canvis[p]) continue;
                canvis[p] = true;
                q.push(p);
            }
        }
        if(!canvis[1]) {pr2(cas); puts("0"); continue;}
        for(int i = 1; i <= n; ++ i)
            for(int p : g[i])
                if(canvis[i] && canvis[p] && p != i) gr[p].pb(i);
        // Traverse from lead
        while(!q.empty()) q.pop();
        q.push(1); subg[1] = true;
        while(!q.empty())
        {
            int x = q.front(); q.pop();
            for(int p : gr[x])
            {
                if(subg[p]) continue;
                q.push(p); subg[p] = true;
            }
        }
        // Find SCC
        SCC(n);
        bool unbounded = false;
        for(int i = 1; i <= n && !unbounded; ++ i)
            for(int k = 0; k < 2; ++ k)
                if(canvis[i] && canvis[g[i][k]] && sccno[i] == sccno[g[i][k]] && subg[g[i][1 - k]]) {unbounded = true; break;}
        if(unbounded) {pr2(cas); puts("UNBOUNDED"); continue;}
        // Find SCC in Q'
        SCC_re(n);
        for(int i = 1; i <= n; ++ i)
            for(int p : gr[i])
            {
                if(!subg[i] || !subg[p] || sccno[p] == sccno[i]) continue;
                int bg = sccno[i];
                int ed = sccno[p];
                gcc[bg].pb(ed); deg[ed] ++;
            }
        // Calculate ans
        int ans = 0;
        while(!q.empty()) q.pop();
        for(int i = 1; i <= scc_cnt; ++ i) label[i] = 0;
        q.push(sccno[1]); path[sccno[1]] = 1;
        while(!q.empty())
        {
            int x = q.front(); q.pop();
            ans = (ans + 1ll * path[x] * tot[x] % mod) % mod;
            for(int p : gcc[x])
            {
                deg[p] --;
                path[p] = (path[p] + path[x]) % mod;
                if(deg[p] == 0) q.push(p);
            }
        }
        pr2(cas); printf("%d\n", ans);
    }
    return 0;
}

