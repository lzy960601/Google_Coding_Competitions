/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-08-25
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

#define IN freopen("sample.in", "r", stdin)
#define OUT freopen("sample.out", "w", stdout)
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
set<int> s;
bool vis[maxn];
int n, m, T;
vi g[maxn];

void DFS(int x)
{
    vis[x] = true;
    for(int p : g[x])
        if(!vis[p]) DFS(p);
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; cas ++)
    {
        scanf("%d%d", &n, &m); s.clear();
        for(int i = 1; i <= n; ++ i) g[i].clear(), vis[i] = false;
        for(int i = 1; i <= m; ++ i)
        {
            int x, y; scanf("%d%d", &x, &y);
            g[x].pb(y); g[y].pb(x);
        }
        int cnt = 0;
        for(int i = 1; i <= n; ++ i)
            if(!vis[i]) {cnt ++; DFS(i);}
        prcas; printf("%d\n", n - 1 + cnt - 1);
    }
    return 0;
}
