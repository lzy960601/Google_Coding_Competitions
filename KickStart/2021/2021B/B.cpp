/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-19
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

const int maxn = 300005;
LL a[maxn];
int n;

int cal()
{
    int ans = 2;
    for(int i = 1; i <= n - 2; ++ i)
    {
        LL d = a[i + 1] - a[i];
        int idx = 0;
        for(int k = i + 2; k <= n; ++ k)
            if(a[k] == a[i] + d * (k - i)) ans = max(ans, k - i + 1);
            else
            {
                if(idx == 0) idx = k; else break;
                ans = max(ans, k - i + 1);
            }
        if(idx == 0) break; else i = idx - 2;
    }
    return ans;
}

int solve()
{
    scd(n);
    for(int i = 1; i <= n; ++ i) scld(a[i]);
    int ans = 2;
    ans = max(ans, cal());
    reverse(a + 1, a + n + 1);
    ans = max(ans, cal());
    return ans;
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