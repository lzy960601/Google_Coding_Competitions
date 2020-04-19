/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-07-28
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

#define IN freopen("sample.in", "r", stdin)
#define OUT freopen("sample.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-x))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

const int maxn = 100005;
const int inf = 1e9 + 7;
struct node
{
    int num;
    int ls, rs;
    LL sum, lg, rg;
    void clear(LL ll, LL rr){num = ls = rs = sum = 0; lg = ll; rg = rr;}
    bool isone(){return lg == rg;}
};

struct SegTree
{
    int kk;
    node tr[maxn << 6];
    
    void clear(LL l, LL r) {tr[0].clear(0, 0); tr[kk = 1].clear(l, r);}

    void pushup(int rt)
    {
        int ls = tr[rt].ls, rs = tr[rt].rs;
        if(ls + rs == 0) return;
        tr[rt].num = tr[ls].num + tr[rs].num;
        tr[rt].sum = tr[ls].sum + tr[rs].sum;
    }

    void add(int rt, LL val)
    {
        if(tr[rt].isone())
        {
            tr[rt].num ++;
            tr[rt].sum += val;
            return;
        }
        LL mid = (tr[rt].lg + tr[rt].rg) >> 1;
        if(val <= mid)
        {
            if(tr[rt].ls == 0)
            {
                tr[++ kk].clear(tr[rt].lg, mid);
                tr[rt].ls = kk;
            }
            add(tr[rt].ls, val);
        }else
        {
            if(tr[rt].rs == 0)
            {
                tr[++ kk].clear(mid + 1, tr[rt].rg);
                tr[rt].rs = kk;
            }
            add(tr[rt].rs, val);
        }
        pushup(rt);
    }

    void del(int rt, LL val)
    {
        if(tr[rt].isone())
        {
            tr[rt].num --;
            tr[rt].sum -= val;
            return;
        }
        LL mid = (tr[rt].lg + tr[rt].rg) >> 1;
        if(val <= mid) del(tr[rt].ls, val); else del(tr[rt].rs, val);
        pushup(rt);
    }

    LL query(int rt, int k)
    {
        if(k <= 0) return 0ll;
        if(tr[rt].num <= k) return tr[rt].sum;
        int ls = tr[rt].ls, rs = tr[rt].rs;
        if(ls == 0) return query(rs, k);
        if(rs == 0) return query(ls, k);
        if(tr[ls].num >= k) return query(ls, k);
        return tr[ls].sum + query(rs, k - tr[ls].num);
    }
}pre, suf;

int T, n, m;
pii dat[maxn];

LL getres(int num, int pos)
{
    LL sum = dat[pos].se;
    sum += pre.query(1, num);
    sum += suf.query(1, m - num);
    sum += 1ll * (2 * num - m) * dat[pos].fi;
    return sum;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &m, &n);
        for(int i = 1; i <= n; ++ i) scanf("%d", &dat[i].fi);
        for(int i = 1; i <= n; ++ i) scanf("%d", &dat[i].se);
        sort(dat + 1, dat + n + 1);
        LL ans = 1e18;
        pre.clear(-inf, inf << 1); suf.clear(-inf, inf << 1);
        for(int i = n; i >= 1; -- i) suf.add(1, dat[i].fi + dat[i].se);
        for(int i = 1; i <= n; ++ i)
        {
            suf.del(1, dat[i].se + dat[i].fi);
            if(pre.tr[1].num >= (m >> 1) && suf.tr[1].num >= m - (m >> 1)) ans = min(ans, getres(m >> 1, i));
            if(pre.tr[1].num > m - (m >> 1) && suf.tr[1].num >= (m >> 1)) ans = min(ans, getres(m - (m >> 1), i));
            pre.add(1, dat[i].se - dat[i].fi);
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}
