/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-05-02
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

char s[1005];

inline int aabs(int x) {return x < 0 ? -x : x;}

int solve()
{
    int x, y;
    scanf("%d%d", &x, &y);
    scs(s + 1);
    int n = strlen(s + 1);
    for(int i = 0; i <= n; ++ i)
    {
        int d = aabs(x) + aabs(y);
        if(d <= i) return i;
        char c = s[i + 1];
        if(c == 'S') -- y;
        if(c == 'N') ++ y;
        if(c == 'E') ++ x;
        if(c == 'W') -- x;
    }
    return -1;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas;
        if(ans < 0) puts("IMPOSSIBLE"); else printf("%d\n", ans);
    }
    return 0;
}
