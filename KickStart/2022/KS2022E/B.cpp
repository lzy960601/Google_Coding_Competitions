/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2022-08-21
File: B.cpp
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

#define IN freopen("B.in", "r", stdin)
#define OUT freopen("B.out", "w", stdout)
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
pii a[maxn];
int n, res[maxn];

void solve(int cas) {
    scd(n); a[0] = mp(-1, -1);
    for(int i = 1; i <= n; ++ i) {
        int x; scd(x);
        a[i] = mp(x, i);
    }
    sort(a + 1, a + n + 1);
    int last = 1;
    for(int i = 1; i <= n; ++ i) {
        while(last <= n && a[last].fi <= a[i].fi * 2) ++ last;
        int idx = last - 1;
        if(idx == i) -- idx;
        res[a[i].se] = a[idx].fi;
    }
    prcas;
    for(int i = 1; i <= n; ++ i) printf("%d%c", res[i], i == n ? '\n' : ' ');
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        solve(cas);
        // prcas; printf("\n", ans);
    }
    return 0;
}