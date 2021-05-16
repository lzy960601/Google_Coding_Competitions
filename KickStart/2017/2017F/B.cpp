/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-16
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

const int maxn = 10005;
int n, a[maxn];

bool check(int len, int mi, int ma)
{
    if(len <= 1) return true;
    int p = (len - 1) / 2;
    if(a[p] != mi && a[p] != ma) return false;
    if(a[p] == mi) ++ mi; else -- ma;
    for(int i = p; i < len - 1; ++ i) a[i] = a[i + 1];
    return check(len - 1, mi, ma);
}

bool solve()
{
    scd(n);
    for(int i = 0; i < n; ++ i) scd(a[i]);
    return check(n, 1, n);
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        bool ans = solve();
        prcas; puts(ans ? "YES" : "NO");
    }
    return 0;
}