/*****************************************
Author: lizi
Email: lzy9maxkmaxk1@gmail.com
Date: 2019-10-19
File: B.cpp
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;

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

const int maxk = 51;
int cnt[65][2];
int n, T;
LL m, ans, ret[65][2], suf[65];

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        for(int i = 0; i <= maxk; ++ i) cnt[i][0] = cnt[i][1] = 0;
        scanf("%d%lld", &n, &m);
        while(n --)
        {
            LL x; scanf("%lld", &x); ans = 0;
            for(int i = 0; i <= maxk; ++ i, x >>= 1) cnt[i][x & 1] ++;
        }
        for(int i = 0; i <= maxk; ++ i) ret[i][0] = 1ll * cnt[i][1] * (1ll << i), ret[i][1] = 1ll * cnt[i][0] * (1ll << i);
        suf[0] = min(ret[0][0], ret[0][1]); for(int i = 1; i <= maxk; ++ i) suf[i] = suf[i - 1] + min(ret[i][0], ret[i][1]);
        for(int i = maxk; i >= 0 && m >= 0; -- i)
        {
            LL t = 0; if(i > 0) t = suf[i - 1];
            if(ret[i][1] + t <= m)
            {
                ans |= 1ll << i;
                m -= ret[i][1];
            }else m -= ret[i][0];
        }
        if(m < 0) ans = -1;
        prcas; printf("%lld\n", ans);
    }
    return 0;
}
