/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-11-18
File: C.cpp
*****************************************/
  
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

bitset<1005> dp[10][11]; // base 500
int T;

int main()
{	
    scd(T);
    dp[0][0].set(500);
    for(int cas = 1; cas <= T; ++ cas)
    {
        for(int i = 1; i < 10; ++ i)
            for(int j = 0; j < 11; ++ j)
                dp[i][j].reset();
        for(int p = 1; p <= 9; ++ p)
        {
            int c; scd(c);
            for(int num = -500; num <= 500; ++ num)
            {
                if((num ^ c) & 1) continue;
                int x = (num + c) >> 1, y = c - x;
                if(x < 0 || y < 0) continue;
                int v = (11 + (1ll * x * p % 11) - (1ll * y * p % 11)) % 11;
                for(int m = 0; m < 11; ++ m)
                    if(num < 0) dp[p][(m + v) % 11] |= (dp[p - 1][m] >> (-num));
                    else dp[p][(m + v) % 11] |= (dp[p - 1][m] << num);
            }
        }
        prcas; if(dp[9][0].test(500) || dp[9][0].test(501)) puts("YES"); else puts("NO");
    }
    return 0;
}
