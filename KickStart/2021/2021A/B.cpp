/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-03-21
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

int T, n, m;
int a[1005][1005], u[1005][1005], d[1005][1005], l[1005][1005], r[1005][1005];

int cal(int x, int y)
{
    if(x == 0 || y == 0) return 0;
    return min(x, y) - 1;
}

int solve()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            scd(a[i][j]);
    for(int i = 0; i <= n + 1; ++ i)
        for(int j = 0; j <= m + 1; ++ j)
            u[i][j] = d[i][j] = l[i][j] = r[i][j] = 0;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            if(a[i][j] == 0)
            {
                u[i][j] = l[i][j] = 0;
            }else
            {
                u[i][j] = u[i - 1][j] + 1;
                l[i][j] = l[i][j - 1] + 1;
            }
    for(int i = n; i >= 1; -- i)
        for(int j = m; j >= 1; -- j)
            if(a[i][j] == 0)
            {
                d[i][j] = r[i][j] = 0;
            }else
            {
                d[i][j] = d[i + 1][j] + 1;
                r[i][j] = r[i][j + 1] + 1;
            }
    int ans = 0;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
        {
            if(a[i][j] == 0) continue;
            int uu = u[i][j], dd = d[i][j], ll = l[i][j], rr = r[i][j];
            ans += cal(uu >> 1, rr) + cal(uu, rr >> 1);
            ans += cal(dd >> 1, rr) + cal(dd, rr >> 1);
            ans += cal(uu >> 1, ll) + cal(uu, ll >> 1);
            ans += cal(dd >> 1, ll) + cal(dd, ll >> 1);
        }
    return ans;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        prcas; printf("%d\n", solve());
    }
    return 0;
}

