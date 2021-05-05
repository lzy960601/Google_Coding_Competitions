/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-05
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

struct answer
{
    char s[55];
    int O, Q;
    void readS()
    {
        scs(s + 1);
        Q = strlen(s + 1);
    }
    void readO() 
    {
        scd(O);
        if((O << 1) < Q) rev();
    }
    void rev()
    {
        for(int i = 1; i <= Q; ++ i)
            s[i] = (s[i] == 'T') ? 'F' : 'T';
        O = Q - O;
    }
}a[2], me;

pii calsd(vi &pos, char s1[], char s2[])
{
    int same = 0, diff = 0;
    for(int p : pos)
        if(s1[p] == s2[p]) ++ same; else ++ diff;
    return mp(same, diff);
}

int solve()
{
    int n, m, ans = 0; scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++ i) a[i].readS();
    me.readS();
    for(int i = 0; i < n; ++ i) a[i].readO();
    if(n == 1)
    {
        vi tmp; tmp.clear();
        for(int i = 1; i <= m; ++ i) tmp.pb(i);
        pii me_sd = calsd(tmp, a[0].s, me.s);
        for(int i = 0; i <= me_sd.fi; ++ i)
        {
            if(i > a[0].O || i + me_sd.se < a[0].O) continue;
            int sc = i, dc = a[0].O - i;
            ans = max(ans, sc + me_sd.se - dc);
        }
        return ans;
    }
    // base a[0]
    vi smp, dfp; smp.clear(); dfp.clear();
    for(int i = 1; i <= m; ++ i)
        if(a[0].s[i] == a[1].s[i]) smp.pb(i); else dfp.pb(i);
    int sn = smp.size(), dn = dfp.size();
    pii smp_sd = calsd(smp, a[0].s, me.s);
    pii dfp_sd = calsd(dfp, a[0].s, me.s);
    for(int i = 0; i <= sn; ++ i)
    {
        if(i > min(a[0].O, a[1].O)) break;
        if(a[0].O - i + a[1].O - i != dn) continue;
        int sc = i, dc = a[0].O - i;
        int val = min(smp_sd.fi, sc) + min(sn - sc, smp_sd.se);
        val += min(dfp_sd.fi, dc) + min(dfp_sd.se, dn - dc);
        ans = max(ans, val);
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