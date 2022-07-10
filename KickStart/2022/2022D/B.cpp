/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2022-07-10
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

const int maxn = 6005;
int a[maxn], b[maxn];
LL ma[maxn], mb[maxn];
int n, m, k;

void cal(int v[], int len, LL s[])
{
    LL pre[len + 5], suf[len + 5];
    pre[0] = suf[0] = 0;
    for(int i = 1; i <= len; ++ i) pre[i] = pre[i - 1] + v[i];
    for(int i = 1; i <= len; ++ i) suf[i] = suf[i - 1] + v[len - i + 1];
    s[0] = 0;
    for(int i = 1; i <= len; ++ i)
    {
        s[i] = 0;
        for(int j = 0; j <= i; ++ j)
            s[i] = max(s[i], pre[j] + suf[i - j]);
    }
}

LL solve()
{
    scd(n);
    for(int i = 1; i <= n; ++ i) scd(a[i]);
    scd(m);
    for(int i = 1; i <= m; ++ i) scd(b[i]);
    cal(a, n, ma); cal(b, m, mb);
    scd(k);
    LL ans = 0;
    for(int i = max(0, k - m); i <= min(n, k); ++ i)
        ans = max(ans, ma[i] + mb[k - i]);
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