/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-18
File: C.cpp
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

const int maxn = 500005;
vi ls, lsh;
int n; pii co[maxn];
LL rec[maxn];

void gen()
{
    int A, B, C, D, E, F, M;
    scanf("%d%d", &co[1].fi, &co[1].se);
    scanf("%d%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F, &M);
    for(int i = 2; i <= n; ++ i)
    {
        co[i].fi = (1ll * A * co[i - 1].fi + 1ll * B * co[i - 1].se + C) % M;
        co[i].se = (1ll * D * co[i - 1].fi + 1ll * E * co[i - 1].se + F) % M;
    }
    ls.clear(); lsh.clear();
    for(int i = 1; i <= n; ++ i) ls.pb(co[i].se);
    sort(ls.begin(), ls.end());
    lsh.pb(ls[0]); 
    for(unsigned int i = 1; i < ls.size(); ++ i)
        if(ls[i] != ls[i - 1]) lsh.pb(ls[i]);
    for(int i = 1; i <= n; ++ i) 
        co[i].se = lower_bound(lsh.begin(), lsh.end(), co[i].se) - lsh.begin() + 1;
}

struct BIT
{
    int lim;
    LL val[maxn];
    void clear(int k) { lim = k; for(int i = 0; i <= k; ++ i) val[i] = 0; }
    void add(int pos, LL v)
    {
        while(pos <= lim)
        {
            val[pos] += v;
            pos += lowbit(pos);
        }
    }
    LL cal(int pos)
    {
        LL ret = 0 ;
        while(pos > 0)
        {
            ret += val[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }
}bit;

int xs = 1;
bool cmp(pii x, pii y)
{
    return x.fi * xs < y.fi * xs || (x.fi == y.fi && x.se > y.se); 
}

LL getans(int para)
{
    xs = para; LL ret = 0;
    sort(co + 1, co + n + 1, cmp);
    for(int i = 1; i <= n; ++ i) rec[i] = 0;
    bit.clear(lsh.size());
    for(int i = 1; i <= n; ++ i)
    {
        rec[i] = bit.cal(co[i].se - 1);
        bit.add(co[i].se, 1);
    }
    bit.clear(lsh.size());
    for(int i = 1; i <= n; ++ i)
    {
        ret += bit.cal(co[i].se - 1);
        bit.add(co[i].se, rec[i]);
    }
    return ret;
}

LL solve()
{
    scd(n); gen();
    LL ans = 1ll * n * (n - 1) * (n - 2) / 6;
    ans -= getans(1);
    ans -= getans(-1);
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