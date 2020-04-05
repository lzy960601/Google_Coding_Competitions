/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-08-25
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

#define IN freopen("sample.in", "r", stdin)
#define OUT freopen("sample.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-x))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

const int maxn = 100005;
struct node
{
    int x, y, label;
    void read(int l) {scanf("%d%d", &x, &y); label = l;}
    bool operator < (const struct node &p) const {return x < p.x;}
}que[maxn];
pii a[maxn];
int ans[maxn];
int n, m, T;

bool cmp(pii u, pii v)
{
    return u.se * v.fi < u.fi * v.se;
}

int main()
{   
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &m, &n);
        for(int i = 1; i <= n; ++ i)
        {
            int x, y; scanf("%d%d", &x, &y);
            a[i] = mp(x, y);
        }
        for(int i = 1; i <= m; ++ i) que[i].read(i);
        sort(que + 1, que + m + 1);
        sort(a + 1, a + n + 1, cmp);
        int sum = 0;
        for(int i = 1; i <= n; ++ i) sum += a[i].fi;
        int k = m, now = 0; for(int i = 1; i <= m; ++ i) ans[i] = 0;
        for(int i = n; i >= 1; -- i)
        {
            while(k > 0 && que[k].x > sum) k --;
            if(k <= 0) break;
            while(k > 0 && que[k].x >= sum - a[i].fi)
            {
                int o = sum - que[k].x;
                LL d = 1ll * o * a[i].se / a[i].fi;
                if(d + now >= que[k].y) ans[que[k].label] = 1;
                k --;
            }
            now += a[i].se;
            sum -= a[i].fi;
        }
        prcas; for(int i = 1; i <= m; ++ i) if(ans[i] == 1) putchar('Y'); else putchar('N');
        puts("");
    }
    return 0;
}
