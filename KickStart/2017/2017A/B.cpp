/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-02
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

const int maxn = 2005;
char s1[maxn], s2[maxn];
int dp[maxn][maxn], n, m;

bool solve()
{
    scs(s1 + 1); n = strlen(s1 + 1);
    scs(s2 + 1); m = strlen(s2 + 1);
    for(int i = 0; i <= n; ++ i) 
        for(int j = 0; j <= m; ++ j)
            dp[i][j] = 0;
    int l1 = 1, l2 = 1;
    while(l1 <= n && s1[l1] == '*') ++ l1;
    while(l2 <= m && s2[l2] == '*') ++ l2;
    for(int i = 0; i < l1; ++ i)
        for(int j = 0; j < l2; ++ j)
            dp[i][j] = 1;   
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
        {
            if(s1[i] != '*' && s2[j] != '*')
            {
                if(s1[i] == s2[j]) dp[i][j] |= dp[i - 1][j - 1];
            }
            if(s1[i] == '*')
            {
                int cnt = 0, now = j;
                while(cnt <= 4 && now >= 0)
                {
                    if(dp[i - 1][now] > 0) { dp[i][j] = 1; break; }
                    if(now > 0 && s2[now] != '*') ++ cnt; -- now;
                }
            }
            if(s2[j] == '*')
            {
                int cnt = 0, now = i;
                while(cnt <= 4 && now >= 0)
                {
                    if(dp[now][j - 1] > 0) { dp[i][j] = 1; break; }
                    if(now > 0 && s1[now] != '*') ++ cnt; -- now;
                }
            }
        }
    return dp[n][m] > 0;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        bool ans = solve();
        prcas; puts(ans ? "TRUE" : "FALSE");
    }
    return 0;
}
/****************************************************
8
****
It
Shakes*e
S*speare
Shakes*e
*peare
*
abcde
ab*de
abccccde
*a
*b
*a*
*b*
**a**b**c**d**e
**

Case #1: TRUE
Case #2: TRUE
Case #3: FALSE
Case #4: FALSE
Case #5: TRUE
Case #6: FALSE
Case #7: TRUE
Case #8: TRUE
****************************************************/