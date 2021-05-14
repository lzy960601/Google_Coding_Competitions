/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-14
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

const int base = 31;
const int mod = 1e9 + 7;
const int maxn = 305;
int has[maxn][maxn], dp[maxn][maxn][maxn], n;
char s[maxn];

void upd(int &x, int y) { x = min(x, y); }

int solve()
{
    scs(s + 1); n = strlen(s + 1);
    for(int i = 0; i <= n; ++ i)
        for(int j = 0; j <= n; ++ j)
            has[i][j] = 0;
    for(int i = 1; i <= n; ++ i)
    {
        int b = 1; 
        for(int j = i; j <= n; ++ j)
        {
            has[i][j] = (has[i][j - 1] + 1ll * b * (s[j] - 'a' + 1) % mod) % mod;
            b = 1ll * b * base % mod;
        }
    }
    for(int i = 0; i <= n; ++ i)
        for(int j = 0; j <= n; ++ j)
            for(int k = 0; k <= n; ++ k)
                dp[i][j][k] = 1e9 +7;
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; ++ i)
    {
        for(int j = 0; j < i; ++ j)
            for(int k = j; k < i; ++ k)
            {
                upd(dp[i][j][k], dp[i - 1][j][k] + 1);
                int l = k - j + 1;
                if(j > 0 && k + l <= i && has[j][k] == has[i - l + 1][i])
                    upd(dp[i][j][k], dp[i - l][j][k] + 1);
            }
        int mi = 1e9 + 100;
        for(int j = 0; j < i; ++ j)
            for(int k = j; k < i; ++ k)
                upd(mi, dp[i][j][k]);
        for(int j = 0; j <= i; ++ j)
            upd(dp[i][j][i], mi + 1);
        for(int j = 0; j < i; ++ j)
            for(int k = 0; k < i; ++ k)
                upd(dp[i][j][k], mi + 1);
    }
    int ans = 1e9 + 1000;
    for(int j = 0; j <= n; ++ j)
        for(int k = 0; k <= n; ++ k)
            upd(ans, dp[n][j][k]);
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