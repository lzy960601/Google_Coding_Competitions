/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-11-15
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

const int maxn = 100005;
int T, a[maxn][2], n;

int aabs(int v) { return v < 0 ? -v : v;}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d", &n);
        vector<LL> xx, yy; xx.clear(); yy.clear();
        for(int i = 1; i <= n; ++ i)
        { 
            LL x, y; scanf("%lld%lld", &x, &y);
            xx.pb(x); yy.pb(y);
        }
        sort(xx.begin(), xx.end());
        sort(yy.begin(), yy.end());
        
        LL ans = 0;
        int k = (n + 1) / 2 - 1;

        // X
        for(int i = 0; i < n; ++ i) xx[i] -= i;
        sort(xx.begin(), xx.end());
        LL tx = xx[k];
        for(int v : xx) ans += aabs(tx - v);
        // Y
        int ty = yy[k];
        for(int v : yy) ans += aabs(v - ty);

        prcas; printf("%lld\n", ans);
    }
    return 0;
}
