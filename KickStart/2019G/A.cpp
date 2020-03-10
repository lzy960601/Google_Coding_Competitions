/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-10-19
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

const int maxn = 100005;
int cnt[maxn];
bool lost[maxn];
int n, m, q, T;

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        LL ans = 0;
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 1; i <= n; ++ i) lost[i] = false, cnt[i] = 0;
        for(int i = 1; i <= m; ++ i)
        {
            int x; scd(x);
            lost[x] = true;
        }
        for(int i = 1; i <= q; ++ i)
        {
            int x; scd(x);
            cnt[x] ++;
        }
        for(int k = 1; k <= n; ++ k)
        {
            if(cnt[k] == 0) continue;
            int sum = 0;
            for(int i = 1; i * k <= n; ++ i)
            {
                int t = i * k;
                if(!lost[t]) sum ++;
            }
            ans += 1ll * sum * cnt[k];
        }
        prcas; printf("%lld\n", ans);
    }
    return 0;
}
