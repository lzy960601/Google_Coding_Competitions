/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-23
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

const int mod = 1e9 + 7;
int N, K, kk[100005];
char s[100005], t[100005];

int solve()
{
    scanf("%d%d", &N, &K);
    kk[0] = 1;
    for(int i = 1; i <= N; ++ i)
        kk[i] = 1ll * kk[i - 1] * K % mod;
    scs(s + 1);
    int ans = 0, last = (N + 1) >> 1;
    for(int i = 1; i <= last; ++ i)
    {
        int v = s[i] - 'a';
        for(int j = 0; j < K; ++ j)
            if(j >= v) break; else (ans += kk[last - i]) %= mod;
    }
    for(int i = 1; i <= last; ++ i) t[i] = s[i];
    for(int i = last + 1; i <= N; ++ i) t[i] = s[N - i + 1];
    int flag = 1;
    for(int i = 1; i <= N; ++ i)
    {
        if(s[i] > t[i]) break;
        if(s[i] < t[i]) { flag = 0; break; }
        if(i == N) flag = 0;
    }
    return (ans + flag) % mod;
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