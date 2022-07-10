/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2022-07-10
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

const int maxn = 10005;
double a[maxn];
int n, m;

double get_med(int l, int r)
{
    if(l > r) return -1;
    int k = r - l + 1;
    int mid = (l + r) >> 1;
    if(k & 1) return a[mid]; else return (a[mid] + a[mid + 1]) * 0.5;
}

double solve()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i) scanf("%lf", &a[i]);
    sort(a + 1, a + n + 1);
    double ans = get_med(1, n - m + 1);
    for(int i = n - m + 2; i <= n; ++ i) ans += a[i];
    return ans;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        double ans = solve();
        prcas; printf("%f\n", ans);
    }
    return 0;
}