/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2022-10-04
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
#define rng(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
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
struct seed
{
    LL Q, L, V;
    void read() { scanf("%lld%lld%lld", &Q, &L, &V); }
    bool operator < (const struct seed &p) const 
    { return L < p.L; }
}a[maxn];
LL D, N, X;
priority_queue<pll> q;

LL solve()
{
    scanf("%lld%lld%lld", &D, &N, &X);
    for(int i = 1; i <= N; ++ i) a[i].read();
    sort(a + 1, a + N + 1); a[N + 1] = {0ll, D, 0ll};
    while(!q.empty()) q.pop();
    LL last = D, ans = 0;
    for(int i = 1; i <= N + 1; ++ i)
    {
        LL dayid = D - a[i].L;
        LL quota = (last - dayid) * X;
        while(quota > 0 && !q.empty())
        {
            pll now = q.top(); q.pop();
            LL plant = min(now.se, quota);
            quota -= plant; now.se -= plant;
            ans += plant * now.fi;
            if(now.se > 0) q.push(now);
        }
        q.push(mp(a[i].V, a[i].Q));
        last = dayid;
    }
    return ans;
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