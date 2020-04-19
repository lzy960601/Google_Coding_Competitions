/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-04-19
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

const int maxn = 1005;
int T, n;
LL a[maxn], D;

bool check(LL x)
{
    for(int i = 1; i <= n; ++ i) x += a[i] - 1, x -= x % a[i];
    return x <= D;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scd(n); scld(D); for(int i = 1; i <= n; ++ i) scld(a[i]);
        LL l = 1, r = D;
        while(r - l > 1)
        {
            LL mid = (l + r) >> 1;
            if(check(mid)) l = mid; else r = mid;
        }
        while(!check(r)) -- r;
        prcas; printf("%lld\n", r);
    }
    return 0;
}
