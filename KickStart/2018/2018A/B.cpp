/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-19
File: B.cpp
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

int n, k;
double a[20005], suf[20005];

double solve()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++ i) scanf("%lf", &a[i]);
    sort(a + 1, a + n + 1);
    suf[n + 1] = 0;
    for(int i = n; i >= 1; -- i) suf[i] = a[i] + suf[i + 1];
    double ans = suf[1] / (double)(n);
    int idx = 1;
    while(k --)
    {
        while(idx <= n && a[idx] < ans) ++ idx;
        ans = suf[idx] / (double)n + ans * (double)(idx - 1) / (double)n;
    }
    return ans;
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
