/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-11-15
File: B.cpp
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

LL F(int k)
{
    LL tmp = 1;
    for(int i = 1; i <= k; ++ i) 
        tmp *= 5;
    return tmp;
}

LL dp[20][2];

LL cal(LL v)
{
    if(v == 0) return 0ll;
    vi tmp; tmp.clear();
    while(v > 0) 
    {
        tmp.pb(v % 10);
        v /= 10;
    }
    int n = tmp.size();
    LL ret = 0;
    for(int i = 1; i < n; ++ i) ret += F(i);
    reverse(tmp.begin(), tmp.end());
    dp[0][1] = 1; dp[0][0] = 0;
    for(int i = 1; i <= n; ++ i)
    {
        dp[i][0] = dp[i][1] = 0;
        int t = tmp[i - 1];
        for(int k = 0; k < 10; ++ k)
        {
            if((k + i) & 1) continue;
            dp[i][0] += dp[i - 1][0];
            if(k < t) dp[i][0] += dp[i - 1][1];
        }
        if((t + i) & 1) continue;
        dp[i][1] = dp[i - 1][1];
    }
    return ret + dp[n][0] + dp[n][1];
}

int T;
LL x, y;

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%lld%lld", &x, &y);
        prcas;
        printf("%lld\n", cal(y) - cal(x - 1));
    }
    return 0;
}
