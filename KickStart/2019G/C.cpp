/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-10-19
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

const int maxn = 25;
int dp[1048550];
LL a[maxn], b[maxn], h;
int n, T;

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%lld", &n, &h);
        for(int i = 0; i < n; ++ i) scld(a[i]);
        for(int i = 0; i < n; ++ i) scld(b[i]);
        for(int mask = 0; mask < (1 << n); ++ mask)
        {
            LL sum = 0;
            for(int i = 0; i < n; ++ i) 
                if((mask >> i) & 1) sum += a[i];
            if(sum >= h) dp[mask] = 1; else dp[mask] = 0;
        }
        for(int i = 0; i < n; ++ i)
            for(int mask = 0; mask < (1 << n); ++ mask)
                if((mask >> i) & 1) dp[mask ^ (1 << i)] += dp[mask];
        LL ans = 0;
        for(int mask = 0; mask < (1 << n); ++ mask)
        {
            LL sum = 0, task = 0;
            for(int i = 0; i < n; ++ i)
                if((mask >> i) & 1) sum += b[i]; else task |= (1 << i);
            if(sum < h) continue;
            ans += dp[task];
        }
        prcas; printf("%lld\n", ans);
    } 
    return 0;
}
