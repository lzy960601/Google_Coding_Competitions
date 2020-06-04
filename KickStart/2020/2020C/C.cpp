/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-05-17
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

const int maxn = 100005;
unordered_map<LL, int> rec;
LL sum[maxn];
int n, T;

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scd(n); sum[0] = 0;
        LL ma = 0;
        for(int i = 1; i <= n; ++ i)
        {
            int x;
            scd(x); sum[i] = sum[i - 1] + x;
            if(x > 0) ma += x;
        }
        int up = (int)sqrt((double)ma + 0.5) + 1;
        rec.clear(); rec[0ll] = 1;
        LL ans = 0;
        for(int i = 1; i <= n; ++ i)
        {
            for(int k = 0; k <= up; ++ k)
            {
                LL nd = sum[i] - 1ll * k * k;
                if(rec.find(nd) != rec.end()) ans += rec[nd];
            }
            rec[sum[i]] ++;
        }
        prcas; printf("%lld\n", ans);
    }
    return 0;
}
