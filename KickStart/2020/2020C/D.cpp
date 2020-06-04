/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-05-17
File: D.cpp
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

#define IN freopen("D.in", "r", stdin)
#define OUT freopen("D.out", "w", stdout)
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

const int maxn = 200005;
struct BIT
{
    int lim;
    LL sum[maxn];

    void init(int n){ lim = n; for(int i = 1; i <= n; ++ i) sum[i] = 0; }

    void add(int p, LL v)
    {
        while(p <= lim)
        {
            sum[p] += v;
            p += lowbit(p);
        }
    }

    LL cal(int p)
    {
        LL ret = 0;
        while(p > 0)
        {
            ret += sum[p];
            p -= lowbit(p);
        }
        return ret;
    }

    LL cal_rng(int l, int r) { return cal(r) - cal(l - 1); }
}s1, s2;

int T, n, q, a[maxn];
char s[2];

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &q);
        s1.init(n); s2.init(n);
        for(int i = 1; i <= n; ++ i)
        {
            scd(a[i]);
            int xs = ((i % 2 == 1) ? 1 : -1);
            s1.add(i, xs * a[i]);
            s2.add(i, 1ll * i * a[i] * xs);
        }
        LL ans = 0;
        while(q --)
        {
            scs(s);
            if(s[0] == 'U')
            {
                int x, y; scanf("%d%d", &x, &y);
                int xs = ((x % 2 == 1) ? 1 : -1);
                int c = y - a[x];
                s1.add(x, xs * c);
                s2.add(x, 1ll * x * c * xs);
                a[x] = y;
            }else
            {
                int l, r; scanf("%d%d", &l, &r);
                LL r1 = s1.cal_rng(l, r);
                LL r2 = s2.cal_rng(l, r);
                LL v = r2 - r1 * (l - 1);
                if(l & 1) ans += v; else ans -= v;
            }
        }
        prcas; printf("%lld\n", ans);
    }
    return 0;
}
