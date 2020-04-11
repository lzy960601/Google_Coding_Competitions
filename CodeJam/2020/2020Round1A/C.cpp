/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-04-11
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

const int maxn = 100005;

int global_ite = 0;

vi q;

LL ans = 0, last = 0;
int T, R, C, o, cou;

int u[maxn], d[maxn], l[maxn], r[maxn], val[maxn], alive[maxn], inq[maxn];
void del_no(int k)
{
    if(k == 0 || alive[k] == 0) return;
    //printf("%d %d %d\n", global_ite, (k + C - 1) / C, (k - 1) % C + 1);
    alive[k] = 0; last -= val[k]; ++ cou;
    if(u[k] > 0) d[u[k]] = d[k];
    if(d[k] > 0) u[d[k]] = u[k];
    if(l[k] > 0) r[l[k]] = r[k];
    if(r[k] > 0) l[r[k]] = l[k];
}

bool judge(int k)
{
    int sum = 0, ccc = 0;
    if(u[k] > 0) { ++ ccc; sum += val[u[k]]; }
    if(d[k] > 0) { ++ ccc; sum += val[d[k]]; }
    if(l[k] > 0) { ++ ccc; sum += val[l[k]]; }
    if(r[k] > 0) { ++ ccc; sum += val[r[k]]; }
    return (val[k] * ccc < sum);
}

void ite()
{
    ans += last;
    global_ite ++;
    cou = 0;
    vi can; can.clear();
    for(int id : q)
    {
        inq[id] = 0;
        if(judge(id)) can.pb(id);
    }
    for(int v : can) del_no(v);
    q.clear();
    for(int v : can)
    {
        if(l[v] > 0 && !inq[l[v]]) { q.pb(l[v]); inq[l[v]] = 1; }
        if(r[v] > 0 && !inq[r[v]]) { q.pb(r[v]); inq[r[v]] = 1; }
        if(u[v] > 0 && !inq[u[v]]) { q.pb(u[v]); inq[u[v]] = 1; }
        if(d[v] > 0 && !inq[d[v]]) { q.pb(d[v]); inq[d[v]] = 1; }
    }
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &R, &C); ans = last = o = 0; q.clear();
        for(int i = 1; i <= R; ++ i)
            for(int j = 1; j <= C; ++ j)
            {
                int x; scd(x); ++ o; alive[o] = 1;
                val[o] = x; last += x;
                if(i == 1) u[o] = 0; else u[o] = o - C;
                if(i == R) d[o] = 0; else d[o] = o + C;
                if(j == 1) l[o] = 0; else l[o] = o - 1;
                if(j == C) r[o] = 0; else r[o] = o + 1;
                q.pb(o);
            }
        cou = R * C; global_ite = 0;
        while(cou > 0) ite();
        prcas; printf("%lld\n", ans);
    }
    return 0;
}
