/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-05-17
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

int a[35][35], vis[35];
int n, m, T, deg[26];
char s[35];
vi ans, g[26];
queue<int> q;

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        for(int i = 0; i < 26; ++ i) g[i].clear(), vis[i] = deg[i] = 0;;
        scanf("%d%d", &n, &m); ans.clear();
        for(int i = 1; i <= n; ++ i)
        {
            scs(s + 1);
            for(int k = 1; k <= m; ++ k)
            {
                int v = s[k] - 'A';
                a[i][k] = v;
                vis[v] = 1;
            }
        }
        for(int i = n - 1; i >= 1; -- i)
            for(int k = 1; k <= m; ++ k)
            {
                int x = a[i][k], y = a[i + 1][k];
                if(x != y) { ++ deg[x]; g[y].pb(x); }
            }
        while(!q.empty()) q.pop();
        for(int k = 0; k < 26; ++ k)
            if(vis[k] && deg[k] <= 0) q.push(k);
        while(!q.empty())
        {
            int t = q.front(); q.pop();
            vis[t] = 2; ans.pb(t);
            for(int p : g[t])
            {
                deg[p] --;
                if(deg[p] == 0) q.push(p);
            }
        }
        bool flag = true;
        for(int i = 0; i < 26; ++ i) if(vis[i] == 1) flag = false;
        prcas;
        if(flag)
        {
            putchar(ans[0] + 'A');
            for(int i = 1; i < ans.size(); ++ i) putchar(ans[i] + 'A');
            puts("");
        }else puts("-1");
    }
    return 0;
}
