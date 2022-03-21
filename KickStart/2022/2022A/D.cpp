/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2022-03-20
File: D.cpp
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

#define IN freopen("D.in", "r", stdin)
#define OUT freopen("D.out", "w", stdout)
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

LL table[15];
LL dp[2][15][120][120]; // 是否顶住，当前第几位，当前和，余数

LL cal(LL ub)
{
    if(ub <= 0) return 0;
    int m = 0, dig[50];
    while(ub > 0)
    {
        dig[++ m] = ub % 10;
        ub /= 10;
    }
    reverse(dig + 1, dig + m + 1);
    LL result = table[m - 1];

    for(int mo = 1; mo <= 9 * m; ++ mo)
    {
        for(int i = 0; i < 2; ++ i)
            for(int ii = 0; ii <= m; ++ ii)
                for(int j = 0; j < 120; ++ j)
                    for(int k = 0; k < 120; ++ k)
                        dp[i][ii][j][k] = 0;
        for(int d = 1; d < dig[1]; ++ d)
            dp[0][1][d][d % mo] += 1;
        dp[1][1][dig[1]][dig[1] % mo] += 1;
        for(int idx = 2; idx <= m; ++ idx)
            for(int lsum = 1; lsum <= min(9 * (idx - 1), mo); ++ lsum)
                for(int od = 0; od < mo; ++ od)
                    for(int d = 0; d <= 9; ++ d)
                    {
                        if(d == dig[idx])
                            dp[1][idx][lsum + d][d * od % mo] += dp[1][idx - 1][lsum][od];
                        dp[0][idx][lsum + d][d * od % mo] += dp[0][idx - 1][lsum][od];
                        if(d < dig[idx])
                            dp[0][idx][lsum + d][d * od % mo] += dp[1][idx - 1][lsum][od];
                    }
        result += dp[0][m][mo][0];
        result += dp[1][m][mo][0];
    }
    return result;
}

void precal()
{
    LL num = 0;
    for(int i = 1; i <= 13; ++ i)
    {
        num = num * 10 + 9;
        table[i] = cal(num);
    }
}

LL solve()
{
    LL A, B; scld(A); scld(B);
    return cal(B) - cal(A - 1);
}

int main()
{
    precal();
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        LL ans = solve();
        prcas; printf("%lld\n", ans);
    }
    return 0;
}