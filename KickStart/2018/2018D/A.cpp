/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-03-20
File: A.cpp
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

#define IN freopen("A.in", "r", stdin)
#define OUT freopen("A.out", "w", stdout)
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

const int maxn = 500005;
const LL inf = 1e18;
LL a[maxn], O, D; 
int T, n, c;
multiset<LL> s;
multiset<LL>::iterator it;

void gen()
{
    LL A, B, C, M, L, X1, X2;
    scd(n); scanf("%lld%lld", &O, &D);
    scanf("%lld%lld%lld%lld%lld%lld%lld", &X1, &X2, &A, &B, &C, &M, &L);
    a[1] = X1; a[2] = X2; a[0] = 0;
    for(int i = 3; i <= n; ++ i) a[i] = (A * a[i - 1] + B * a[i - 2] + C) % M;
    for(int i = 1; i <= n; ++ i) a[i] += L;
    for(int i = 1; i <= n; ++ i) a[i] += a[i - 1];
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        gen(); c = 0; s.clear(); int last = 1;
        s.insert(0); s.insert(inf);
        LL ans = -inf;
        for(int i = 1; i <= n; ++ i)
        {
            if((a[i] - a[i - 1]) & 1) ++ c;
            while(c > O)
            {
                s.erase(a[last - 1]);
                if(last > 0 && ((a[last] - a[last - 1]) & 1)) -- c;
                ++ last;
            }
            it = s.lower_bound(a[i] - D);
            if((*it) < inf) ans = max(ans, a[i] - (*it));
            s.insert(a[i]);
        }
        prcas; if(ans == -inf) puts("IMPOSSIBLE"); else printf("%lld\n", ans);
    }
    return 0;
}
