/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-10
File: B.cpp
*****************************************/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")  
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

vector< pll > rd;

LL solve()
{
    int n; scd(n); rd.clear();
    LL sum = 0;
    while(n --)
    {
        LL x, y; scanf("%lld%lld", &x, &y);
        rd.pb(mp(x, y));
        sum += x * y;
    }
    for(LL su = 2; su <= min((LL)20000, sum - 1); ++ su)
    {
        bool flag = true;
        LL s = sum - su, tot = 0;
        for(pll p : rd)
        {
            LL cnt = 0;
            while(s % p.fi == 0)
            {
                s /= p.fi;
                ++ cnt;
                tot += p.fi;
            }
            if(cnt > p.se) { flag = false; break; }
        }
        if(s <= 1 && tot == su && flag) return sum - su;
    }
    return 0;
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

