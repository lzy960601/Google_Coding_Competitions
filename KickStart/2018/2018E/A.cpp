/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-07
File: A.cpp
*****************************************/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")  
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

#define IN freopen("A.in", "r", stdin)
#define OUT freopen("A.out", "w", stdout)
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

const int inf = 1e9 + 7;

struct field
{
    int a[3], id;
    field(int x, int y, int z, int k) { a[0] = x; a[1] = y; a[2] = z; id = k; }
};
vector<field> bahu, bala, bahupre;
vi ls, lsh;
int n, a[21], b[21], cnt[3], s[3];

void makeseq(int id, int v[], vector<field> &rec)
{
    if(id == 1) for(int i = 0; i < 3; ++ i) cnt[i] = s[i] = 0;
    if(id > 3 * n)
    {
        int i = rec.size();
        rec.pb(field(s[0], s[1], s[2], i));
        return;
    }
    for(int i = 0; i < 3; ++ i)
    {
        if(cnt[i] >= n) continue;
        ++ cnt[i]; s[i] += v[id];
        makeseq(id + 1, v, rec);
        -- cnt[i]; s[i] -= v[id];
    }
}

int cmpara = 0;
bool cmp(field x, field y) { return x.a[cmpara] < y.a[cmpara]; }

struct BIT
{
    int val[3005], lim;
    void clear(int k) { lim = k; }
    void add(int pos, int v)
    {
        while(pos <= lim)
        {
            val[pos] += v;
            pos += lowbit(pos);
        }
    }
    int cal(int pos)
    {
        int ret = 0;
        while(pos > 0)
        {
            ret += val[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }
}bit;

int getidx(vi &g, int v)
{
    int id = lower_bound(g.begin(), g.end(), v) - g.begin();
    return id + 1;
}

void cal2(int sz, vi &ret, int id1, int id2)
{
    bit.clear(lsh.size());
    cmpara = id1; sort(bahu.begin(), bahu.end(), cmp); sort(bala.begin(), bala.end(), cmp);
    int ii = 0;
    for(field f : bahu)
    {
        while(ii < sz && bala[ii].a[id1] <= f.a[id1])
        {
            bit.add(bala[ii].a[id2], 1);
            ++ ii;
        }
        ret[f.id] += bit.cal(f.a[id2]);
    }
    for(int i = 0; i < ii; ++ i)
        bit.add(bala[i].a[id2], -1);
}

struct BBIT
{
    BIT b[3005];
    int lim;
    void clear(int k) { lim = k; for(int i = 0; i <= k; ++ i) b[i].clear(k);}
    void add(int x, int y, int c)
    {
        while(x <= lim)
        {
            b[x].add(y, c);
            x += lowbit(x);
        }
    }
    int cal(int x, int y)
    {
        int ret = 0;
        while(x > 0)
        {
            ret += b[x].cal(y);
            x -= lowbit(x);
        }
        return ret;
    }
}bbit;

void cal3(int sz, vi &ret)
{
    cmpara = 0; sort(bahu.begin(), bahu.end(), cmp); sort(bala.begin(), bala.end(), cmp);
    int ii = 0; bbit.clear(lsh.size());
    for(field f : bahu)
    {
        while(ii < sz && bala[ii].a[0] <= f.a[0])
        {
            bbit.add(bala[ii].a[1], bala[ii].a[2], 1);
            ++ ii;
        }
        int num = bbit.cal(f.a[1], f.a[2]);
        ret[f.id] -= num << 1;
    }
    for(int i = 0; i < ii; ++ i)
        bbit.add(bala[i].a[1], bala[i].a[2], -1);
}

bool fcmp(field x, field y)
{
    for(int k = 0; k < 3; ++ k)
    {
        if(x.a[k] < y.a[k]) return true;
        if(x.a[k] > y.a[k]) return false;
    }
    return false;
}

void getunique(vector<field>& A, vector<field>& B)
{
    for(field f : A) sort(f.a, f.a + 3);
    sort(A.begin(), A.end(), fcmp);
    B.clear(); int cnt = 0;
    B.pb(A[0]); B[0].id = cnt ++;
    for(int i = 1; i < A.size(); ++ i)
    {
        if(A[i].a[0] == A[i - 1].a[0] && A[i].a[1] == A[i - 1].a[1] && A[i].a[2] == A[i - 1].a[2])
        continue;
        B.pb(A[i]); B[cnt].id = cnt; ++ cnt;
    }
}

double solve()
{
    scd(n);
    bahu.clear(); bala.clear(); bahupre.clear();
    for(int i = 1; i <= 3 * n; ++ i) scd(a[i]);
    for(int i = 1; i <= 3 * n; ++ i) scd(b[i]);
    makeseq(1, a, bahupre);
    makeseq(1, b, bala);
    getunique(bahupre, bahu);
    int m = bala.size(), ans = 0;
    ls.clear(); lsh.clear();
    for(field f : bala) ls.pb(f.a[2]);
    sort(ls.begin(), ls.end()); lsh.pb(ls[0]); 
    for(int i = 1; i < ls.size(); ++ i) 
        if(ls[i] != ls[i - 1]) lsh.pb(ls[i]);
    lsh.pb(inf); bit.clear(lsh.size());
    vi ret(bahu.size(), 0);
    for(int k = 0; k < 3; ++ k)
    {
        for(int i = 0; i < bahu.size(); ++ i) bahu[i].a[k] = getidx(lsh, bahu[i].a[k]) - 1;
        for(int i = 0; i < m; ++ i) bala[i].a[k] = getidx(lsh, bala[i].a[k]);
    }
    cal2(m, ret, 0, 1); cal2(m, ret, 0, 2); cal2(m, ret, 1, 2);
    cal3(m, ret);
    ans = 0; for(int p : ret) ans = max(ans, p);
    return (double)ans / (double)m;
}

int main()
{	
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        double ans = solve();
        prcas; printf("%.12f\n", ans);
    }
    return 0;
}

