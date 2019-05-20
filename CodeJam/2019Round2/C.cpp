/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<LL, LL> pll;

const int maxn = 305;
pii a[maxn];
vector< pll > g;
map<pii, int> m;
int n, T, cnt;

int gcd(int x, int y)
{
    if(y == 0) return x;
    if(x == 0) return y;
    return gcd(y, x % y);
}

bool cmp(pii x, pii y)
{
    return 1ll * x.fi * y.se < 1ll * x.se * y.fi;
}

bool judge(pll r)
{
    for(int i = 2; i <= n; ++ i)
    {
        LL nowval = 1ll * r.fi * a[i].fi + 1ll * r.se * a[i].se;
        LL lstval = 1ll * r.fi * a[i - 1].fi + 1ll * r.se * a[i - 1].se;
        if(nowval <= lstval) return false;
    }
    return true;
}

pll solve(pll u, pll v)
{
    //printf("%d %d\n", u.fi, u.se);
    if(u.fi == 0) return mp(1ll, v.se / v.fi + 1);
    LL o = u.fi / u.se + 1;
    if(o < (v.fi + v.se - 1) / v.se) return mp(o, 1ll);
    if(o == 1)
    {
        pll tmp = solve(mp(v.se, v.fi), mp(u.se, u.fi));
        return mp(tmp.se, tmp.fi);
    }
    o -= 1;
    u.fi -= u.se * o; v.fi -= v.se * o;
    pll tt = solve(u, v);
    tt.fi += tt.se * o;
    return tt;
}

int abs(int x) {return x < 0 ? -x : x;}

int main()
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d", &n); cnt = 0; m.clear(); g.clear();
        for(int i = 1; i <= n; ++ i)
        {
            int x, y; scanf("%d%d", &x, &y);
            a[i] = mp(x, y);
        }
        for(int i = 1; i <= n; ++ i)
            for(int j = i + 1; j <= n; ++ j)
            {
                if(a[i].fi >= a[j].fi && a[i].se >= a[j].se) continue;
                if(a[i].fi <= a[j].fi && a[i].se <= a[j].se) continue;
                int fir = abs(a[i].fi - a[j].fi);
                int sec = abs(a[i].se - a[j].se);
                if(sec == 0) fir = 1;
                if(fir == 0) sec = 1;
                int gg = gcd(fir, sec); fir /= gg; sec /= gg;
                pii tmp = mp(sec, fir);
                //printf("!!! %d %d\n", tmp.fi, tmp.se);
                if(m[tmp] == 0) { m[tmp] = ++ cnt; g.pb(mp((LL)sec, (LL)fir)); }
            }
        g.pb(mp(0ll, 1ll)); g.pb(mp((LL)(1e9 + 7), 1ll)); sort(g.begin(), g.end(), cmp);
        LL ansx = -1, ansy = -1;
        for(int i = 1; i <= cnt + 1; ++ i)
        {
            pll res = solve(g[i - 1], g[i]);
            if(judge(res))
            {
                if(ansx < 0 || res.fi < ansx || (res.fi == ansx && res.se < ansy)) {ansx = res.fi; ansy = res.se;}
            }
        }
        prr(cas); if(ansx < 0) puts("IMPOSSIBLE"); else printf("%lld %lld\n", ansx, ansy);
    }
    return 0;
}

