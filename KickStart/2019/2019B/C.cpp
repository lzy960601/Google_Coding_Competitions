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

const int maxn = 200005;

struct SegTree
{
    int nodecnt;
    struct node
    {
        int val, tag;
        int ls, rs, l, r;
        void clear(int x, int y){l = x; r = y; ls = rs = val = tag = 0;}
        bool isone(){return l > 0 && r > 0 && l == r;}
        bool match(int x, int y){return l == x && r == y;}
    }tr[maxn << 1];

    void mt(int x, int y)
    {
        tr[nodecnt].clear(x, y);
        if(x == y) return;
        int mid = (x + y) >> 1, tmp = nodecnt;
        nodecnt ++; tr[tmp].ls = nodecnt; mt(x, mid);
        nodecnt ++; tr[tmp].rs = nodecnt; mt(mid + 1, y);
    }

    void init(int n)
    {
        nodecnt = 1;
        mt(1, n);
    }

    void pushup(int t)
    {
        if(tr[t].ls + tr[t].rs == 0) return;
        int ls = tr[t].ls, rs = tr[t].rs;
        tr[t].val = max(tr[ls].val, tr[rs].val);
    }

    void pushdown(int t)
    {
        if(tr[t].ls + tr[t].rs == 0 || tr[t].tag == 0) return;
        int ls = tr[t].ls, rs = tr[t].rs, tg = tr[t].tag;
        tr[t].tag = 0;
        tr[ls].tag += tg; tr[ls].val += tg;
        tr[rs].tag += tg; tr[rs].val += tg;
        pushup(t);
    }

    int query(int o, int l, int r)
    {
        if(tr[o].match(l, r)) return tr[o].val;
        int mid = (tr[o].l + tr[o].r) >> 1;
        int ret = -1e9 - 7;
        if(l <= mid) ret = max(ret, query(tr[o].ls, l, min(mid, r)));
        if(r > mid) ret = max(ret, query(tr[o].rs, max(mid + 1, l), r));
        return ret;
    }

    void modify(int o, int l, int r, int tg)
    {
        if(tr[o].match(l, r))
        {
            tr[o].val += tg;
            tr[o].tag += tg;
            return;
        }
        pushdown(o);
        int mid = (tr[o].l + tr[o].r) >> 1;
        if(l <= mid) modify(tr[o].ls, l, min(mid, r), tg);
        if(r > mid) modify(tr[o].rs, max(l, mid + 1), r, tg);
        pushup(o);
    }
}seg;

int a[maxn], cnt[maxn], n, m, T, ans = 0;
vi g[maxn];

int main()
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &m); ans = 0;
        for(int i = 1; i <= n; ++ i) scanf("%d", &a[i]), cnt[a[i]] = 0, g[a[i]].clear();
        seg.init(n);
        for(int i = n; i >= 1; -- i)
        {
            int v = a[i];
            cnt[v] ++; a[i] = 1;
            seg.modify(1, i, n, 1);
            g[v].pb(i);
            if(cnt[v] > m)
            {
                int pos = g[v][cnt[v] - m - 1];
                seg.modify(1, pos, n, -m - a[pos]);
                a[pos] = -m;
            }
            if(cnt[v] > m + 1)
            {
                int pos = g[v][cnt[v] - m - 2];
                seg.modify(1, pos, n, 0 - a[pos]);
                a[pos] = 0;
            }
            ans = max(ans, seg.query(1, i, n));
        }
        prr(cas); printf("%d\n", ans);
    }
    return 0;
}
