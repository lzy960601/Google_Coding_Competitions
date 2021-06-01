/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-06-01
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

int cal(int n, int m)
{
    if(n <= 2) return n * (2 * (m / 3) + m % 3);
    int x[3], v[3];
    v[0] = (n + 2) / 3, v[1] = (n + 1) / 3, v[2] = n / 3;
    x[0] = 2 * (m / 3) + m % 3;
    x[1] = 2 * (m / 3) + max(0, m % 3 - 1);
    x[2] = 2 * (m / 3) + ((m % 3 + 1) >> 1);
    int a[3] = {0, 1, 2};
    int cnt = 6, ans = 0;
    while(cnt --)
    {
        int sum = 0;
        for(int i = 0; i < 3; ++ i)
            sum += v[i] * x[a[i]];
        ans = max(ans, sum);
        next_permutation(a, a + 3);
    }
    return ans;
}

int solve()
{
    int n, m; scanf("%d%d", &n, &m);
    if(n <= 2 && m <= 2) return n * m;
    return max(cal(n, m), cal(m, n));
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