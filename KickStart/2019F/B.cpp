/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-09-30
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
#define lowbit(x) ((x) & (-x))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

const int base = 1000;
unordered_map<LL, int> m;
int T, n, s;
LL g[50005];

LL has(vi x)
{
    LL sum = 0, b = 1;
    for(int p : x)
    {
        sum += b * (p - 1);
        b *= base;
    }
    return sum;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        m.clear();
        scanf("%d%d", &n, &s);
        for(int i = 1; i <= n; ++ i)
        {
            vi now, tmp; tmp.clear();
            int k, x; scd(k); 
            for(int p = 0; p < k; ++ p) {scd(x); tmp.pb(x);}
            sort(tmp.begin(), tmp.end()); g[i] = has(tmp);
            for(int mask = 1; mask < (1 << k); ++ mask)
            {
                now.clear();
                for(int p = 0; p < k; ++ p)
                    if((mask >> p) & 1) now.pb(tmp[p]);
                m[has(now)] ++;
            }
        }
        LL ans = 0;
        for(int i = 1; i <= n; ++ i) ans += (n - m[g[i]]);
        prcas; printf("%lld\n", ans);
    }
    return 0;
}
