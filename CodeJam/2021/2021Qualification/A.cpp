/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-03-27
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

int T, n, a[105];

int solve()
{
    scd(n);
    for(int i = 1; i <= n; ++ i) scd(a[i]);
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
    return ans;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; printf("%d\n", ans);
    }
    return 0;
}
