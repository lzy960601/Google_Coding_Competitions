/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-23
File: CC.cpp
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

#define IN freopen("CC.in", "r", stdin)
#define OUT freopen("CC.out", "w", stdout)
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

double dp[61][61][61];
struct state
{
    int x, y, z;
}pre[61][61][61];

char c[3] = {'R', 'P', 'S'};

int main()
{
    double x = 1000, y; scanf("%lf", &y);
    for(int sum = 0; sum <= 60; ++ sum)
        for(int i0 = 0; i0 <= sum; ++ i0)
            for(int i1 = 0; i1 + i0 <= sum; ++ i1)
            {
                int i2 = sum - i0 - i1;
                dp[i0][i1][i2] = -1;
            }
    dp[0][0][0] = 0;
    dp[1][0][0] = dp[0][1][0] = dp[0][0][1] = (x + y) / 3.0;
    pre[1][0][0] = pre[0][1][0] = pre[0][0][1] = {0, 0, 0};
    for(int sum = 1; sum < 60; ++ sum)
        for(int i0 = 0; i0 <= sum; ++ i0)
            for(int i1 = 0; i1 + i0 <= sum; ++ i1)
            {
                int i2 = sum - i0 - i1;
                double nx;
                // 0
                nx = dp[i0][i1][i2] + ((double)i1 / (double)sum) * x + ((double)i2 / (double)sum) * y;
                if(nx > dp[i0 + 1][i1][i2])
                {
                    dp[i0 + 1][i1][i2] = nx;
                    pre[i0 + 1][i1][i2] = {i0, i1, i2};
                }
                // 1
                nx = dp[i0][i1][i2] + ((double)i2 / (double)sum) * x + ((double)i0 / (double)sum) * y;
                if(nx > dp[i0][i1 + 1][i2])
                {
                    dp[i0][i1 + 1][i2] = nx;
                    pre[i0][i1 + 1][i2] = {i0, i1, i2};
                }
                // 2
                nx = dp[i0][i1][i2] + ((double)i0 / (double)sum) * x + ((double)i1 / (double)sum) * y;
                if(nx > dp[i0][i1][i2 + 1])
                {
                    dp[i0][i1][i2 + 1] = nx;
                    pre[i0][i1][i2 + 1] = {i0, i1, i2};
                }
            }
    double ma = -1.0;
    int dx, dy, dz;
    string s = "";
    for(int i = 0; i <= 60; ++ i)
        for(int j = 0; j + i <= 60; ++ j)
        {
            int k = 60 - i - j;
            if(dp[i][j][k] > ma)
            {
                ma = dp[i][j][k];
                dx = i; dy = j; dz = k;
            }
        }
    while(dx + dy + dz > 0)
    {
        state NN = pre[dx][dy][dz];
        if(NN.x < dx) s += c[0];
        if(NN.y < dy) s += c[1];
        if(NN.z < dz) s += c[2];
        dx = NN.x; dy = NN.y; dz = NN.z;
    }
    reverse(rng(s));
    cout << s << endl;
    return 0;
}