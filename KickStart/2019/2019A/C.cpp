/*****************************************
Author: lizi
Email: zyli@smail.nju.edu.cn
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

const int N = 200005;
const int inf = 1000000000;
struct pa 
{
    int x, y;
    bool operator < (const struct pa &p)const 
    {
        if (x!=p.x) return x>p.x;
        return y<p.y;
    }
}ans, A[N];
struct node 
{
    int x, y, l, r;
}a[N];
int b[N], f[N << 2], t[N << 2], T;
set<int> F[N << 2];
set<pa> G;
int n, m, q[N << 1];
inline void build(int o, int l, int r) 
{
    f[o] = 0;
    t[o] = 0;
    F[o].clear();
    if (l == r) return ;
    int mid = (l + r) >> 1;
    build(o * 2, l, mid);
    build(o * 2 + 1, mid + 1, r);
}
inline void up(int x) 
{
    t[x] = min(t[x * 2], t[x * 2 + 1]) + f[x];
}
inline void change(int o, int l, int r, int ll, int rr, int p) 
{
    if (l == ll && r == rr) 
    {
        f[o] ++;
        t[o] ++;
        F[o].insert(p);
        return ;
    }
    int mid=(l + r) >> 1;
    if (rr <= mid) change(o * 2, l, mid, ll, rr, p);
    else if (ll > mid) change(o * 2 + 1, mid + 1, r, ll, rr, p);
    else change(o * 2, l, mid, ll, mid, p), change(o * 2 + 1, mid + 1, r, mid + 1, rr, p);
    up(o);
}
inline void del(int o,int l,int r,int ll,int rr,int p) 
{
    if (l == ll && r == rr) 
    {
        f[o] --;
        t[o] --;
        F[o].erase(p);
        return;
    }
    int mid = (l + r) >> 1;
    if (rr <= mid) del(o * 2, l, mid, ll, rr, p);
    else if (ll > mid) del(o * 2 + 1, mid + 1, r, ll, rr, p);
    else del(o * 2, l, mid, ll, mid, p), del(o * 2 + 1,mid + 1, r, mid + 1, rr, p);
    up(o);
}
inline void change(int o, int l, int r, int ll) 
{
    if (l==r) 
    {
        t[o] = inf;
        return ;
    }
    int mid=(l + r) >> 1;
    if (ll <= mid) change(o * 2, l, mid, ll);
    else change(o * 2 + 1, mid + 1, r, ll);
    up(o);
}
inline void ask(int o, int l, int r) 
{
    if (!F[o].empty()) ans.y = (*F[o].begin());
    if (l == r) 
    {
        ans.x = l;
        return ;
    }
    int mid = (l + r) >> 1;
    if (t[o * 2] < t[o * 2 + 1]) ask(o * 2, l, mid);
    else ask(o * 2 + 1, mid + 1, r);
}
int main() 
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &m, &n);
        int Ans = m, r = 0;
        for (int i = 1; i <= n; i ++) scanf("%d%d", &a[i].x, &a[i].y);
        for (int i = 1; i <= n; i ++) q[++ r] = a[i].x, q[++ r] = a[i].y;
        sort(q + 1, q + 1 + r);
        int tot=0;
        A[++ tot] = {q[1], q[1]};
        for (int i = 2; i <= r; i ++) 
        {
            if (q[i] != q[i - 1]) 
            {
                if (q[i - 1] + 1 < q[i]) A[++ tot] = {q[i-1] + 1, q[i] - 1};
                A[++ tot] = {q[i], q[i]};
            }
        }
        m = tot;
        build(1, 1, m);
        for (int i = 1; i <= n; i ++) {
            int l = 1, r = m;
            while (l <= r) 
            {
                int mid = ( l + r) >> 1;
                if (A[mid].x >= a[i].x) a[i].l = mid, r = mid-1;
                else l = mid + 1;
            }
            l = 1, r = m;
            while (l <= r) 
            {
                int mid=(l + r) >> 1;
                if (A[mid].y <= a[i].y) a[i].r = mid, l = mid + 1;
                else r = mid - 1;
            }
            change(1, 1, m, a[i].l, a[i].r, i);
        }
        G.clear();
        for (int i = 1; i <= n; i ++) b[i]=0, G.insert({0,i});
        for (int i = 1; i <= n; i ++) 
        {
            while (t[1] <= 1) 
            {
                ans.x=0, ans.y=0;
                ask(1, 1, m);
                change(1, 1, m, ans.x);
                if (ans.y) 
                {
                    G.erase(pa{b[ans.y],ans.y});
                    b[ans.y] += A[ans.x].y - A[ans.x].x + 1;
                    G.insert(pa{b[ans.y],ans.y});
                }
            }
            pa gt=(*G.begin());
            Ans = min(Ans, gt.x);
            G.erase(G.begin());
            del(1, 1, m, a[gt.y].l, a[gt.y].r, gt.y);
        }
        prr(cas); printf("%d\n", Ans);
    }
}
