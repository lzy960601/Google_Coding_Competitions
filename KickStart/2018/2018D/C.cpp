/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-03-23
File: C.cpp
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

#define IN freopen("C.in", "r", stdin)
#define OUT freopen("C.out", "w", stdout)
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

const int maxn = 105;
LL u[maxn][maxn][maxn], d[maxn][maxn][maxn], l[maxn][maxn][maxn], r[maxn][maxn][maxn];
LL pu[maxn][maxn][maxn], pd[maxn][maxn][maxn], pl[maxn][maxn][maxn], pr[maxn][maxn][maxn];
LL ver[maxn], hol[maxn][maxn], hor[maxn][maxn], suf[maxn];
map<string, int> sm;
int T, n, m, W;
char a[maxn][maxn], ss[maxn];

LL gcd(LL x, LL y)
{
    if(x == 0 && y == 0) return 1;
    if(x == 0) return y;
    if(y == 0) return x;
    return gcd(y, x % y);
}

void cal(int x, int y, LL uu[], LL dd[], LL ll[], LL rr[])
{
    string tmp = "";
    for(int i = y; i <= m; ++ i)
    {
        tmp += a[x][i];
        if(sm.find(tmp) != sm.end()) rr[i - y + 1] = sm[tmp];
    }
    tmp = "";
    for(int i = x; i <= n; ++ i)
    {
        tmp += a[i][y];
        if(sm.find(tmp) != sm.end()) dd[i - x + 1] = sm[tmp];
    }
    tmp = "";
    for(int i = x; i >= 1; -- i)
    {
        tmp += a[i][y];
        if(sm.find(tmp) != sm.end()) uu[x - i + 1] = sm[tmp];
    }
    tmp = "";
    for(int i = y; i >= 1; -- i)
    {
        tmp += a[x][i];
        if(sm.find(tmp) != sm.end()) ll[y - i + 1] = sm[tmp];
    }
}

void upd(LL sum, LL sz, pll& ans, int& cnt)
{
    if(sum * ans.se < ans.fi * sz) return;
    if(sum * ans.se > ans.fi * sz) { ans = mp(sum, sz); cnt = 1; return; }
    ++ cnt;
}

pair<pll, int> solve()
{
    int cnt = 0;
    pll ans = mp(0, 1);
    cin >> n >> m >> W;
    for(int i = 1; i <= n; ++ i) scs(a[i] + 1);
    sm.clear();
    while(W --)
    {
        string s = "";
        scs(ss + 1); int len = strlen(ss + 1);
        for(int i = 1; i <= len; ++ i) s += ss[i];
        sm[s] += s.length(); 
        //reverse(s.begin(), s.end());
        //sm[s] ++;
    }
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            for(int k = 0; k <= max(n, m); ++ k)
            {
                u[i][j][k] = d[i][j][k] = l[i][j][k] = r[i][j][k] = 0;
                pu[i][j][k] = pd[i][j][k] = pl[i][j][k] = pr[i][j][k] = 0;
            }
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            cal(i, j, u[i][j], d[i][j], l[i][j], r[i][j]);
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            for(int k = 1; k <= max(n, m); ++ k)
            {
                pu[i][j][k] = pu[i][j][k - 1] + u[i][j][k];
                pd[i][j][k] = pd[i][j][k - 1] + d[i][j][k];
                pl[i][j][k] = pl[i][j][k - 1] + l[i][j][k];
                pr[i][j][k] = pr[i][j][k - 1] + r[i][j][k];
            }
    for(int ub = 1; ub <= n; ++ ub)
    {
        for(int i = 1; i <= m; ++ i)
            for(int k = 0; k <= max(n, m); ++ k)
                hol[i][k] = hor[i][k] = 0;
        for(int db = ub; db <= n; ++ db)
        {
            for(int i = 1; i <= m; ++ i)
            {
                ver[i] = 0;
                for(int k = ub; k <= db; ++ k)
                    ver[i] += pu[k][i][k - ub + 1] + pd[k][i][db - k + 1];
                for(int k = 1; k <= max(n, m); ++ k)
                {
                    hol[i][k] += pl[db][i][k];
                    hor[i][k] += pr[db][i][k];
                }
            }
            for(int s = m; s >= 1; -- s)
            {
                suf[s] = 0;
                for(int i = 1; i <= s; ++ i)
                    suf[s] += hor[i][s - i + 1];
            }
            for(int lb = 1; lb <= m; ++ lb)
            {
                LL versum = 0, holsum = 0;
                for(int rb = lb; rb <= m; ++ rb)
                {
                    versum += ver[rb];
                    holsum += hol[rb][rb - lb + 1];
                    LL horsum = suf[rb];
                    LL sum = versum + holsum + horsum;
                    LL sz = (rb - lb + 1) + (db - ub + 1);
                    upd(sum, sz, ans, cnt);
                }
                for(int s = lb; s <= m; ++ s)
                    suf[s] -= hor[lb][s - lb + 1];
            }
        }
    }
    return mp(ans, cnt);
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        pair<pii, int> ans = solve();
        LL ggg = gcd(ans.fi.fi, ans.fi.se);
        prcas; printf("%lld/%lld %d\n", ans.fi.fi / ggg, ans.fi.se / ggg, ans.se);
    }
    return 0;
}
