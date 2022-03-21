/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2022-03-20
File: C.cpp
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

#define IN freopen("C.in", "r", stdin)
#define OUT freopen("C.out", "w", stdout)
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

const int maxn = 50005;
char s[maxn];
int dp[maxn][100], n, islegal[100];

bool match(int mask, int bg, int ed)
{
    for(int i = 0; i <= ed - bg; ++ i)
    {
        int v = (mask >> i) & 1;
        if(s[ed - i] == '?') continue;
        int f = s[ed - i] - '0';
        if(v != f) return false;
    }
    return true;
}

int solve()
{
    int n;
    scd(n); scs(s + 1);
    if(n < 5) return 1;
    if(n == 5)
    {
        for(int mask = 0; mask < (1 << 6); ++ mask)
            if(match(mask, 1, 5) && islegal[mask] > 0) return 1;
        return -1;
    }
    for(int i = 1; i <= 6; ++ i)
        for(int mask = 0; mask < (1 << 6); ++ mask)
            dp[i][mask] = 0;
    for(int mask = 0; mask < (1 << 6); ++ mask)
        if(match(mask, 1, 6) && islegal[mask] > 0) dp[6][mask] = 1;
    for(int i = 7; i <= n; ++ i)
        for(int tmask = 0; tmask < (1 << 6); ++ tmask)
        {
            dp[i][tmask] = 0;
            if(!match(tmask, i - 5, i)) continue;
            dp[i][tmask] |= dp[i - 1][tmask >> 1];
            dp[i][tmask] |= dp[i - 1][(tmask >> 1) | (1 << 5)];
            dp[i][tmask] &= islegal[tmask];
        }
    for(int mask = 0; mask < (1 << 6); ++ mask)
        if(dp[n][mask] > 0) return 1;
    return -1;
}

bool check1(string t)
{
    for(int i = 0; i <= 2; ++ i)
        if(t[i] != t[5 - i]) return false;
    return true;
}

bool check2(string t)
{
    bool flag1 = true, flag2 = true;
    for(int i = 0; i < 2; ++ i)
        if(t[i] != t[4 - i]) flag1 = false;
    for(int i = 1; i < 3; ++ i)
        if(t[i] != t[6 - i]) flag2 = false;
    return flag1 || flag2;
}

int main()
{
    for(int mask = 0; mask < (1 << 6); ++ mask)
    {
        string t = "";
        for(int i = 0; i < 6; ++ i)
            t += (char)(((mask >> i) & 1) + '0');
        if(!check1(t) && !check2(t)) islegal[mask] = 1;
        //if(!check1(t) && !check2(t)) cout << t << endl; else cout << "!!   " << t << endl;
    }
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; 
        puts(ans > 0 ? "POSSIBLE" : "IMPOSSIBLE");
    }
    return 0;
}