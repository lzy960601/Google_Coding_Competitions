/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-03-09
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

const int maxn = 55;
const int inf = 1e9 + 7;

int T, n, m;
typedef pair< int, pair<int, int> > piii;
vector< piii > g;
int label[maxn];

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++ i) label[i] = 0;
        g.clear();
        for(int i = 1; i <= m; ++ i)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            g.pb( mp(z, mp(x, y)) );
        }
        sort(g.begin(), g.end());
        int cnt = 0;
        for(piii unit : g)
        {
            int d = unit.fi, x = unit.se.fi, y = unit.se.se;
            if(d == 0) {cnt ++; label[x] = label[y] = 2; continue;}
            if(label[x] == 0 && label[y] == 0) {cnt ++; label[x] = label[y] = 1; continue;}
            if(label[x] != 0) swap(x, y);
            if(label[x] != 0) continue;
            if(label[y] == 2) cnt ++; label[x] = 1;
        }
        prcas; printf("%lld\n", 1ll << cnt);
    }
    return 0;
}
