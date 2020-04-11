/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-04-11
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

const int tr = 40;

int T;
LL n;
vi rec;

int main()
{
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scld(n); pncas;
        if(n <= 500)
        {
            for(int i = 1; i <= n; ++ i) printf("%d 1\n", i);
            continue;
        }
        n -= tr; rec.clear();
        for(int i = tr; i >= 1; -- i)
        {
            LL res = (1ll << (i - 1)) - 1;
            if(res <= n) { rec.pb(i); n -= res; }
            if(n == 0) break;
        }
        reverse(rec.begin(), rec.end());
        int x = 1, y = 1;
        printf("1 1\n");
        for(int p : rec)
        {
            while(x < p)
            {
                if(y == x) ++ y;
                ++ x;
                printf("%d %d\n", x, y);
            }
            if(y == 1)
            {
                while(y < x)
                {
                    ++ y; printf("%d %d\n", x, y);
                }
            }else
            {
                while(y > 1)
                {
                    -- y; printf("%d %d\n", x, y);
                }
            }
        }
        while(x < tr)
        {
            if(y == x) ++ y;
            ++ x;
            printf("%d %d\n", x, y);
        }
        while(n > 0)
        {
            if(y == x) ++ y;
            ++ x; -- n;
            printf("%d %d\n", x, y);
        }
    }
    return 0;
}
