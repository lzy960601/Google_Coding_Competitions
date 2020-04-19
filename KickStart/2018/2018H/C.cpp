/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-03-09
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

const int mod = 1e9 + 7;
const int maxn = 200005;

int mi(int x, int y)
{
    int ret = 1;
    while(y > 0)
    {
        if(y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ret;
}

int fac[maxn], ivf[maxn], two[maxn];
int T, n, m;

inline int C(int x, int y) {return 1ll * fac[x] * (1ll * ivf[y] * ivf[x - y] % mod) % mod;}

int cal(int v)
{
    int tmp = 1ll * C(m, v) * two[v] % mod;
    return 1ll * tmp * fac[2 * n - v] % mod;
}

int main()
{	
    two[0] = 1; for(int i = 1; i <= 100000; ++ i) two[i] = 2ll * two[i - 1] % mod;
    fac[0] = 1; for(int i = 1; i <= 200000; ++ i) fac[i] = 1ll * i * fac[i - 1] % mod;
    ivf[200000] = mi(fac[200000], mod - 2);
    for(int i = 199999; i >= 0; -- i) ivf[i] = 1ll * (i + 1) * ivf[i + 1] % mod;

    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &m);
        int ans = 0;
        for(int i = 0; i <= m; ++ i)
        {
            int num = (i & 1) ? mod - cal(i) : cal(i);
            (ans += num) %= mod;
        }
        prcas; printf("%d\n", ans);
    }
    return 0;
}
