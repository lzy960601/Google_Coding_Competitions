/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-07-28
File: A.cpp
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
int rec[1024], a[maxn];
int sum[maxn], n, T, m, su;

void add(int p, int v)
{
    while(p <= n)
    {
        sum[p] += v;
        p += lowbit(p);
    }
}

int cal(int p)
{
    int ret = 0;
    while(p > 0)
    {
        ret += sum[p];
        p -=lowbit(p);
    }
    return ret;
}

int solve()
{
    if((su & 1) == 0) return n;
    if(n == 1 && su == 1) return 0;
    int l0 = 0, l1, r0, r1 = n;
    int l = 1, r = n;
    while(r - l > 1)
    {
        int mid = (l + r) >> 1;
        if(cal(mid) >= 1) r = mid; else l = mid;
    }
    while(cal(l) <= 0) ++ l;
    l1 = l;
    l = 0, r = n - 1;
    while(r - l > 1)
    {
        int mid = (l + r) >> 1;
        if(cal(mid) >= su) r = mid; else l = mid;
    }
    while(cal(r) >= su) -- r;
    r0 = r;
    return max(0, max(r1 - l1, r0 - l0));
}

int main()
{	
    for(int mask = 0; mask < 1024; ++ mask)
    {
        int cnt = 0;
        for(int i = 0; i < 10; ++ i)
            if((mask >> i) & 1) cnt ++;
        rec[mask] = cnt & 1;
    }
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &m); su = 0;
        for(int i = 1; i <= n; ++ i) sum[i] = 0;
        for(int i = 1; i <= n; ++ i)
        {
            int x; scd(x);
            a[i] = rec[x];
            su += a[i]; add(i, a[i]);
        }
        printf("Case #%d:", cas);
        while(m --)
        {
            int pos, val; scanf("%d%d", &pos, &val);
            pos ++; val = rec[val];
            add(pos, -a[pos]); su -= a[pos];
            a[pos] = val; add(pos, a[pos]); su += a[pos];
            printf(" %d", solve());
        }
        puts("");
    }
    return 0;
}
