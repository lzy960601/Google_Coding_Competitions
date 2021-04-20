/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-18
File: A.cpp
*****************************************/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
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

int a[20], nc;

LL getmin()
{
    bool flag = false;
    LL ret = 0;
    for(int i = 1; i <= nc; ++ i)
    {
        int v = a[i], x = 0;
        if(flag) x = 8;
        else
        {
            if(v & 1)
            {
                x = v - 1;
                flag = true;
            }else x = v;
        }
        ret = 10ll * ret + x;
    }
    return ret;
}

LL getmax()
{
    bool flag = false;
    LL ret = 0;
    for(int i = 1; i <= nc; ++ i)
    {
        int v = a[i], x = 0;
        if(flag) x = 0;
        else
        {
            if(v & 1)
            {
                x = v + 1;
                flag = true;
                a[i] = x;
                for(int k = i; k >= 0; -- k)
                {
                    if(a[k] & 1) ++ a[k];
                    if(a[k] > 9) a[k - 1] ++;
                    a[k] %= 10;
                }
                continue;
            }else x = v;
        }
        a[i] = x;
    }
    for(int i = 0; i <= nc; ++ i) ret = 10ll * ret + a[i];
    return ret;
}

LL solve()
{
    LL num, nu; scld(num); nu = num;
    nc = 0; a[0] = 0;
    while(num > 0)
    {
        a[++ nc] = num % 10;
        num /= 10;
    }
    reverse(a + 1, a + nc + 1);
    LL ans = 1e18;
    ans = min(ans, nu - getmin());
    ans = min(ans, getmax() - nu);
    return ans;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        LL ans = solve();
        prcas; printf("%lld\n", ans);
    }
    return 0;
}