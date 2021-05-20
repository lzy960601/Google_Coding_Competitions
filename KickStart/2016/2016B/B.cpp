/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-20
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

const int mod = 1e9 + 7;

int mi(int x, int y, int m)
{
    int ret = 1;
    while(y > 0)
    {
        if(y & 1) ret = 1ll * ret * x % m;
        x = 1ll * x * x % m;
        y >>= 1;
    }
    return ret % m;
}

int cntA[100005], cntB[100005];

int solve()
{
    int A, B, K; LL N;
    scanf("%d%d%lld%d", &A, &B, &N, &K);
    for(int i = 0; i < K; ++ i) cntA[i] = cntB[i] = 0;
    for(int i = 0; i < K; ++ i)
    {
        LL v = ((N + ((K - i) % K)) / K) % mod;
        (cntA[mi(i, A, K)] += v) %= mod;
        (cntB[mi(i, B, K)] += v) %= mod;
    }
    int ans = 0;
    for(int i = 0; i < K; ++ i)
        (ans += 1ll * cntA[i] * cntB[(K - i) % K] % mod) %= mod;
    for(int i = 0; i < K; ++ i)
    {
        LL v = ((N + ((K - i) % K)) / K) % mod;
        int ma = mi(i, A, K), mb = mi(i, B, K);
        if((ma + mb) % K == 0) (ans += (mod - v * v % mod)) %= mod;
    }
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