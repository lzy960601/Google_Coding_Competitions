/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-20
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
#define rng(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
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
pii a[maxn];
int n;

void gen()
{
    int x, y, A, B, C1, C2, M;
    scanf("%d%d%d%d%d%d%d", &x, &y, &A, &B, &C1, &C2, &M);
    for(int i = 1; i <= n; ++ i)
    {
        a[i] = mp(min(x, y), max(x, y));
        int nx = (1ll * A * x + 1ll * B * y + 1ll * C1) % M;
        int ny = (1ll * A * y + 1ll * B * x + 1ll * C2) % M;
        x = nx; y = ny;
    }
}

set<int> s;
vi gin[maxn << 1], gout[maxn << 1];
int cnt[maxn];

int solve()
{
    scd(n); gen();
    vi ls, lsh; ls.clear(); lsh.clear();
    for(int i = 1; i <= n; ++ i)
        ls.pb(a[i].fi), ls.pb(a[i].se + 1);
    sort(rng(ls)); lsh.pb(ls[0]);
    for(int i = 1; i < SZ(ls); ++ i)
        if(ls[i] != ls[i - 1]) lsh.pb(ls[i]);
    for(int i = 0; i < SZ(lsh); ++ i) gin[i].clear(), gout[i].clear();
    for(int i = 1; i <= n; ++ i)
    {
        cnt[i] = 0;
        gin[lower_bound(rng(lsh), a[i].fi) - lsh.begin()].pb(i);
        gout[lower_bound(rng(lsh), a[i].se + 1) - lsh.begin()].pb(i);
    }
    s.clear(); int sum = 0, ans = 0;
    for(int i = 0; i < SZ(lsh); ++ i)
    {
        if(SZ(s) > 0) sum += lsh[i] - lsh[i - 1];
        if(SZ(s) == 1)
        {
            int v = *s.begin();
            cnt[v] += lsh[i] - lsh[i - 1];
            ans = max(ans, cnt[v]);
        }
        for(int p : gout[i]) s.erase(p);
        for(int p : gin[i]) s.insert(p);
    }
    return sum - ans;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; printf("%d\n", ans);
    }
    return 0;
}