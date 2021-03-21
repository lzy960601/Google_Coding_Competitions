/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-03-21
File: D.cpp
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

const int maxn = 505;
int a[maxn][maxn], b[maxn][maxn], r[maxn], c[maxn];
int T, n, f[maxn << 1], cost[maxn << 1];

int find(int t)
{
    if(f[t] == t) return t;
    else return f[t] = find(f[t]);
}

int solve()
{
    scd(n); int sum = 0;
    for(int i = 1; i <= n; ++ i) 
        for(int j = 1; j <= n; ++ j)
            scd(a[i][j]);
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
            scd(b[i][j]), sum += b[i][j];
    for(int i = 1; i <= n; ++ i) scd(r[i]);
    for(int i = 1; i <= n; ++ i) scd(c[i]);
    for(int i = 1; i <= (n << 1); ++ i) f[i] = i;
    for(int i = 1; i <= (n << 1); ++ i) cost[i] = (i <= n) ? 0 : b[1][i - n];
    for(int k = 1; k <= (n << 1); ++ k)
    {
        int id = 0;
        for(int i = 2; i <= (n << 1); ++ i)
        {
            int fa = find(i);
            if(fa == 1) continue;
            if(id == 0 || cost[i] > cost[id]) id = i;
        }
        if(id == 0) break;
        sum -= cost[id]; f[find(id)] = 1;
        for(int i = 2; i <= (n << 1); ++ i)
        {
            int fa = find(i);
            if(fa == 1) { cost[i] = 0; continue; }
            if(id <= n && i > n) cost[i] = max(cost[i], b[id][i - n]);
            if(id > n && i <= n) cost[i] = max(cost[i], b[i][id - n]);
        }
    }
    return sum;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; printf("%d\n", ans);
    }
    return 0;
}
