/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-12
File: B.cpp
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
typedef vector<LL> vll;

const int maxn = 200005;
const LL inf = 1e18L;
LL n, m, a[maxn], b[maxn], sa[maxn], sb[maxn];

void gen()
{
    LL x, y, r, s, C, D, E1, E2, F;
    scanf("%lld%lld%lld%lld%lld%lld%lld", &x, &y, &C, &D, &E1, &E2, &F);
    a[1] = x; b[1] = y; r = s = 0;
    for(int i = 2; i <= n; ++ i)
    {
        LL nx = (C * x + D * y + E1) % F;
        LL ny = (D * x + C * y + E2) % F;
        LL nr = (C * r + D * s + E1) % 2;
        LL ns = (D * r + C * s + E2) % 2;
        a[i] = (nr % 2 == 1) ? -nx : nx;
        b[i] = (ns % 2 == 1) ? -ny : ny;
        x = nx; y = ny; r = nr; s = ns;
    }
}

struct BIT
{
    LL v[maxn];
    int lim;

    void init(int k) { lim = k; for(int i = 0; i <= lim; ++ i) v[i] = 0; }

    void add(int p, LL q)
    {
        while(p <= lim)
        {
            v[p] += q;
            p += lowbit(p);
        }
    }

    LL cal(int p)
    {
        LL ret = 0;
        while(p > 0)
        {
            ret += v[p];
            p -= lowbit(p);
        }
        return ret;
    }
}bit;

LL count(LL v, vll &lsh, LL pre[], LL xs) // A - (B) >= C --> (B) <= A - C
{
    LL cnt = 0; 
    bit.init(lsh.size());
    for(int i = 0; i <= n; ++ i)
    {
        LL val = pre[i] - v;
        if(xs < 0)
        {
            int idx = lower_bound(lsh.begin(), lsh.end(), val) - lsh.begin(); // -1 + 1
            cnt += (LL)i - bit.cal(idx);
        }else
        {
            int idx = upper_bound(lsh.begin(), lsh.end(), val) - lsh.begin(); // -1 + 1
            cnt += bit.cal(idx);
        }
        bit.add(lower_bound(lsh.begin(), lsh.end(), pre[i]) - lsh.begin() + 1, 1);
    }
    return cnt;
}

pll getminmax(LL pre[], LL K)
{
    vll lsh, ls; ls.clear(); lsh.clear();
    for(int i = 0; i <= n; ++ i) ls.pb(pre[i]);
    sort(ls.begin(), ls.end());
    lsh.pb(ls[0]);
    for(int i = 1; i < ls.size(); ++ i)
        if(ls[i] != ls[i - 1]) lsh.pb(ls[i]);
    lsh.pb(inf);
    LL ma, mi, l, r;

    // cal max K
    l = -inf, r = inf;
    while(r - l > 1)
    {
        LL mid = (l + r) / 2;
        if(count(mid, lsh, pre, 1) < K) r = mid; else l = mid;
    }
    while(count(r, lsh, pre, 1) < K) -- r;
    ma = r;

    // cal min K
    l = -inf, r = inf;
    while(r - l > 1)
    {
        LL mid = (l + r) / 2;
        if(count(mid, lsh, pre, -1) < K) l = mid; else r = mid;
    }
    while(count(l, lsh, pre, -1) < K) ++ l;
    mi = l;
    return mp(ma, mi);
}

vll getTopK(LL pre[], LL K, LL v, LL x)
{
    vll ret; ret.clear(); 
    priority_queue<LL> q;
    while(!q.empty()) q.pop();
    for(int i = 0; i <= n; ++ i)
    {
        vll tmp; tmp.clear();
        while(!q.empty() && (x * pre[i] + q.top()) > x * v)
        {
            LL y = q.top(); q.pop();
            ret.pb(pre[i] + x * y);
            tmp.pb(y);
        }
        q.push(-x * pre[i]);
        for(LL p : tmp) q.push(p);
    }
    while(ret.size() < K) ret.pb(v);
    sort(ret.begin(), ret.end());
    return ret;
}

vll getcombine(LL pre[], LL K)
{
    if(n * (n + 1) <= 4ll * K)
    {
        vll tmp; tmp.clear();
        for(int i = 1; i <= n; ++ i)
            for(int j = i; j <= n; ++ j)
                tmp.pb(pre[j] - pre[i - 1]);
        sort(tmp.begin(), tmp.end());
        return tmp;
    }
    pll mm = getminmax(pre, K);
    vll maxK = getTopK(pre, K, mm.fi, 1);
    vll minK = getTopK(pre, K, mm.se, -1);
    vll ret; ret.clear();
    ret.insert(ret.end(), minK.begin(), minK.end());
    ret.insert(ret.end(), maxK.begin(), maxK.end());
    sort(ret.begin(), ret.end());
    return ret;
}

LL check(LL v, vll &A, vll &B)
{
    LL cnt = 0;
    int la = A.size(), lb = B.size();
    int xa = -1, xb = -1, ya = la, yb = lb;
    for(int i = 0; i < la; ++ i)
    {
        if(A[i] >= 0) break;
        xa = i;
    }
    for(int i = la - 1; i >= 0; -- i)
    {
        if(A[i] <= 0) break;
        ya = i;
    }
    for(int i = 0; i < lb; ++ i)
    {
        if(B[i] >= 0) break;
        xb = i;
    }
    for(int i = lb - 1; i >= 0; -- i)
    {
        if(B[i] <= 0) break;
        yb = i;
    }

    // --
    for(int i = 0, id = xb; i <= xa; ++ i)
    {
        while(id >= 0 && A[i] * B[id] < v) -- id;
        cnt += id + 1;
    }
    // ++
    for(int i = la - 1, id = yb; i >= ya; -- i)
    {
        while(id < lb && A[i] * B[id] < v) ++ id;
        cnt += lb - id;
    }
    if(v <= 0) 
    {
        cnt += 1ll * (ya - xa - 1) * lb;
        cnt += 1ll * (yb - xb - 1) * la;
        cnt -= 1ll * (ya - xa - 1) * (yb - xb - 1);
        // -+
        for(int i = 0, id = yb; i <= xa; ++ i)
        {
            while(id < lb && A[i] * B[id] >= v) ++ id;
            cnt += id - yb;
        }
        // +-
        for(int i = la - 1, id = xb; i >= ya; -- i)
        {
            while(id >= 0 && A[i] * B[id] >= v) -- id;
            cnt += xb - id;
        }
    }
    return cnt;
}

LL solve()
{
    scanf("%lld%lld", &n, &m); gen();
    sa[0] = sb[0] = 0;
    for(int i = 1; i <= n; ++ i)
    {
        sa[i] = sa[i - 1] + a[i];
        sb[i] = sb[i - 1] + b[i];
    }
    vll veca = getcombine(sa, m);
    vll vecb = getcombine(sb, m);
    LL l = -inf, r = inf;
    while(r - l > 1)
    {
        LL mid = (l + r) / 2;
        if(check(mid, veca, vecb) >= m) l = mid; else r = mid;
    }
    while(check(r, veca, vecb) < m) -- r;
    return r;
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