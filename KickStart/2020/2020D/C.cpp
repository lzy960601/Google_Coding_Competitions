/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-07-12
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

const int maxn = 500005;
vi g[maxn];
int n, T, A, B, AB, sz[maxn], dep[maxn];
int cnt1[maxn], cnt2[maxn], cnt3[maxn];
bool big[maxn];
double ans, N;

void cal_sz(int v,int p)
{
    dep[v] = dep[p] + 1;
    sz[v]=1;
    for(auto x : g[v])
    {
        if(x!=p)
        {
            cal_sz(x,v);
            sz[v]+=sz[x];
        }
    }
}

void add(int v,int p,int x)
{
    int d = dep[v];
    cnt1[d % A] += x; cnt2[d % B] += x; cnt3[d % AB] += x;
    for(auto u : g[v])
    {
        if(u!=p && !big[u])
            add(u,v,x);
    }
}

double solve(int v)
{
    int d = dep[v];
    double cA = cnt1[d % A];
    double cB = cnt2[d % B];
    double cAB = cnt3[d % AB];

    double ret = cA / N + cB / N;
    ret -= (cA / N) * (cB / N);

    //printf("%d : %.10f\n", v, ret);

    return ret;
}

void DFS(int v,int p,bool k)
{
    int bn=-1;
    for(auto u : g[v])
    {
        if(u!=p)
        {
            if(bn==-1 || sz[u]>sz[bn])bn=u;
        }
    }
    for(auto u : g[v])
    {
        if(u!=p && u!=bn)
            DFS(u,v,false);
    }
    if(bn!=-1)
    {
        DFS(bn,v,true);
        big[bn]=true;
    }
    add(v,p,1);
    
    ans += solve(v);

    if(bn!=-1)big[bn]=false;
    if(!k)add(v,p,-1);
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d%d", &n, &A, &B); N = n;
        int gcd = __gcd(A, B);
        if(1ll * A * B / gcd > 1ll * n) AB = n + 1;
        else AB = (A / gcd) * B;
        ans = 0.0;
        for(int i = 1; i <= n; ++ i)
        {
            g[i].clear();
            dep[i] = 0;
            cnt1[i] = cnt2[i] = cnt3[i] = 0;
            big[i] = false;
        }
        for(int i = 2; i <= n; ++ i)
        {
            int x; scd(x);
            g[x].pb(i);
        }
        dep[0] = -1; cal_sz(1, 0);
        DFS(1, 0, false);
        prcas; printf("%.10f\n", ans);
    }
    return 0;
}
