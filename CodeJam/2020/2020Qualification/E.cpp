/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-04-04
File: E.cpp
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

#define IN freopen("E.in", "r", stdin)
#define OUT freopen("E.out", "w", stdout)
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
int a[55][55], cnt[55], ord[55], ur[55], uc[55], link[55], used[55];

bool cmp(int x, int y) {return cnt[x] < cnt[y];}

void presolve()
{
    for(int i = 1; i <= n; ++ i)
    {
        a[i][i] = max(1, m - n * (n - i));
        m -= a[i][i];
    }
    if(a[n - 1][n - 1] == 1 && a[n][n] > 2) { -- a[n][n]; ++ a[n - 1][n - 1]; }
    if(a[1][1] < n - 1 && a[2][2] == n) { ++ a[1][1]; -- a[2][2]; }
    for(int i = 1; i <= n; ++ i) -- cnt[a[i][i]];
}

vi e[55];

bool dfs(int x) 
{
    for(auto &y : e[x])   
        if (!used[y]) 
        {
            used[y] = 1;
            if(link[y] <= 0 || dfs(link[y]))
            {
                link[y] = x;
                return true;
            }
        }
    return false;
}

int hungary() 
{
    int res = 0;
    for(int i = 1; i <= n; ++ i) link[i] = 0;
    for(int i = 1; i <= n; ++ i) 
    {
        for(int k = 1; k <= n; ++ k) used[k] = 0;
        if(dfs(i)) ++ res;
    }
    return res;
}

bool solve(int v)
{
    for(int i = 1; i <= n; ++ i) ur[i] = uc[i] = 0;
    int c = 0;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
            if(a[i][j] == v) { ur[i] = 1; uc[j] = 1; ++ c; }
    for(int i = 1; i <= n; ++ i) e[i].clear();
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
            if(ur[i] <= 0 && uc[j] <= 0 && a[i][j] <= 0) 
            {
                e[i].pb(j);
            }
    int x = hungary();
    if(x + c < n) return false;
    for(int i = 1; i <= n; ++ i)
        if(link[i] > 0) a[link[i]][i] = v;
    return true;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++ i)
        {
            cnt[i] = n; ord[i] = i;
            for(int j = 1; j <= n; ++ j) a[i][j] = 0;
        }
        prcas; 
        if(m == n + 1 || m == n * n - 1) { puts("IMPOSSIBLE"); continue; }
        if(n == 3 && (m == 5 || m == 7)) { puts("IMPOSSIBLE"); continue; }
        presolve(); 
        bool flag = true;
        sort(ord + 1, ord + n + 1, cmp);
        for(int i = 1; i <= n; ++ i) 
            if(!solve(ord[i])) { flag = false; break; }
        if(!flag) puts("IMPOSSIBLE");
        else
        {
            puts("POSSIBLE");
            for(int i = 1; i <= n; ++ i)
                for(int j = 1; j <= n; ++ j)
                    printf("%d%c", a[i][j], j == n ? '\n' : ' ');
        }
    }
    return 0;
}
