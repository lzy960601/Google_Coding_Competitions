/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-15
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

int n;

int query(int x, int y)
{
    printf("M %d %d\n", x, y);
    fflush(stdout);
    int t; scd(t);
    return t;
}

void doswap(int x, int y)
{
    printf("S %d %d\n", x, y);
    fflush(stdout);
    int t; scd(t);
}

void solve()
{
    for(int i = 1; i < n; ++ i)
    {
        int pos = query(i, n);
        if(pos != i) doswap(i, pos);
    }
}

int main()
{
    int T; scd(T); scd(n);
    for(int cas = 1; cas <= T; ++ cas)
    {
        solve();
        puts("D");
        int x; scd(x);
        assert(x == 1);
    }
    return 0;
}