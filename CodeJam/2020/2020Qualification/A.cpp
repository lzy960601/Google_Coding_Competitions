/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-04-04
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

int k, r, c;
int T, n;
int a[105][105], b[105];

int main()
{	
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scd(n); k = r = c = 0;
        for(int i = 1; i <= n; ++ i)
            for(int j = 1; j <= n; ++ j)
            {
                scd(a[i][j]);
                if(i == j) k += a[i][j];
            }
        // row
        for(int i = 1; i <= n; ++ i)
        {
            for(int p = 1; p <= n; ++ p) b[p] = 0;
            for(int p = 1; p <= n; ++ p)
                if(b[a[i][p]] > 0) { ++ r; break; } else b[a[i][p]] = 1;
        }
        // column
        for(int i = 1; i <= n; ++ i)
        {
            for(int p = 1; p <= n; ++ p) b[p] = 0;
            for(int p = 1; p <= n; ++ p)
                if(b[a[p][i]] > 0) { ++ c; break; } else b[a[p][i]] = 1;
        }
        prcas; printf("%d %d %d\n", k, r, c);
    }
    return 0;
}
