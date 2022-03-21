/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2022-03-20
File: A.cpp
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

#define IN freopen("A.in", "r", stdin)
#define OUT freopen("A.out", "w", stdout)
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

int solve()
{
    char s1[maxn], s2[maxn];
    int n, m;
    scs(s1 + 1); n = strlen(s1 + 1);
    scs(s2 + 1); m = strlen(s2 + 1);
    int idx = 0;
    for(int i = 1; i <= n; ++ i)
    {
        ++ idx;
        while(idx <= m && s2[idx] != s1[i]) ++ idx;
        if(idx > m) break;
    }
    if(idx > m) return -1; else return m - n;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; 
        if(ans >= 0) printf("%d\n", ans); 
        else puts("IMPOSSIBLE");
    }
    return 0;
}