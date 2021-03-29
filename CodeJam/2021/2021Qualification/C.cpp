/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-03-27
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

int a[105], b[105], c, n, T, CC;

int solve()
{
    scanf("%d%d", &n, &c); CC = c;
    for(int i = 1; i <= n; ++ i) a[i] = 0;
    for(int i = 1; i < n; ++ i) b[i] = 1;
    a[n] = n; c -= n - 1;
    if(c < 0) return -1;
    for(int k = n - 1; k >= 1; -- k)
    {
        int val = min(c, n - k);
        c -= val; b[k] += val;
    }
    if(c > 0) return -1;
    for(int k = n - 1; k >= 1; -- k)
    {
        int val = b[k];
        if(val == 1) { a[k] = k; continue; }
        int nx = k + val - 1;
        for(int i = k; i < nx; ++ i) a[i] = a[i + 1];
        reverse(a + k, a + nx);
        a[nx] = k;
    }
    if(c > 0) return -1;
    return 0;
}

int check(int co)
{
    int ans = 0;
    for(int i = 1; i < n; ++ i)
    {
        int id = 0;
        for(int j = i; j <= n; ++ j)
            if(id == 0 || a[j] < a[id]) id = j;
        int len = id - i + 1;
        ans += len;
        for(int j = 1; j <= (len >> 1); ++ j)
            swap(a[i + j - 1], a[id - j + 1]);
     }
    return ans == co;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas;
        if(ans < 0) puts("IMPOSSIBLE");
        else for(int i = 1; i <= n; ++ i) printf("%d%c", a[i], i == n ? '\n' : ' ');
        //if(check(CC)) puts("OK"); else puts("WRONG");
    }
    return 0;
}
