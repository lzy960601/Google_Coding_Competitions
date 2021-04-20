/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-19
File: D.cpp
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

const int maxn = 50005;
const int maxm = 100005;

inline LL gcd(LL x, LL y)
{
    if(x == 0) return y;
    if(y == 0) return x;
    return gcd(y, x % y);
}

struct query
{
    int node, val, id;
    void read(int k) { scanf("%d%d", &node, &val); id = k; }
    bool operator < (const struct query &p) const
    { return val < p.val; }
}q[maxm];
LL ans[maxm];
int n, m;
int dcnt, pos[maxn], sz[maxn];
struct edge
{
    int x, y, L;
    LL A;
    void read() { scanf("%d%d%d%lld", &x, &y, &L, &A); }
    bool operator < (const struct edge &p) const
    { return L < p.L; }
    int getson() { return pos[x] < pos[y] ? y : x; }
}e[maxn];
vi g[maxn];

void getsz(int u, int f)
{
    ++ dcnt; pos[u] = dcnt;
    sz[u] = 1;
    for(int p : g[u])
    {
        if(p == f) continue;
        getsz(p, u);
        sz[u] += sz[p];
    }
}

struct SegTree
{
    int ls[maxn << 2], rs[maxn << 2];
    LL val[maxn << 2];
    int ncnt;

    void mt(int &o, int l, int r)
    {
        if(o == 0) o = ++ ncnt;
        val[o] = 0;
        if(l == r) return;
        ls[o] = rs[o] = 0;
        int mid = (l + r) >> 1;
        mt(ls[o], l, mid);
        mt(rs[o], mid + 1, r);
    }

    void modify(int &o, int l, int r, int lg, int rg, LL v)
    {
        if(l >= lg && r <= rg)
        {
            val[o] = gcd(val[o], v);
            return;
        }
        int mid = (l + r) >> 1;
        if(lg <= mid) modify(ls[o], l, mid, lg, min(mid, rg), v);
        if(rg > mid) modify(rs[o], mid + 1, r, max(lg, mid + 1), rg, v);
    }

    LL get(int &o, int l, int r, int p)
    {
        if(l == r) return val[o];
        LL ret = 0;
        int mid = (l + r) >> 1;
        if(p <= mid) ret = get(ls[o], l, mid, p); 
        else ret = get(rs[o], mid + 1, r, p);
        return gcd(ret, val[o]);
    }
}st;

void solve(int cas)
{
    scanf("%d%d", &n, &m); int root = 0;
    for(int i = 1; i <= n; ++ i) g[i].clear(), sz[i] = 0;
    for(int i = 1; i < n; ++ i)
    {
        e[i].read();
        g[e[i].x].pb(e[i].y);
        g[e[i].y].pb(e[i].x);
    }
    dcnt = 0; getsz(1, 0);
    st.ncnt = 0; st.mt(root, 1, n);
    for(int i = 1; i <= m; ++ i) q[i].read(i);
    sort(e + 1, e + n);
    sort(q + 1, q + m + 1);
    int idx = 1;
    for(int i = 1; i <= m; ++ i)
    {
        query p = q[i];
        while(idx < n && e[idx].L <= p.val)
        {
            int node = e[idx].getson();
            int po = pos[node];
            int ed = po + sz[node] - 1;
            st.modify(root, 1, n, po, ed, e[idx].A);
            ++ idx;
        }
        ans[p.id] = st.get(root, 1, n, pos[p.node]);
    }
    prcas;
    for(int i = 1; i <= m; ++ i) printf("%lld%c", ans[i], i == m ? '\n' : ' ');
}

int main()
{
    //IN; OUT;
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas) 
        solve(cas);
    return 0;
}