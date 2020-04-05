/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-07-28
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
int c[maxn << 1], a[maxn << 1], cc[maxn << 1], ca[maxn << 1];
vi gc[maxn], ga[maxn];
int T, G, n, m, ans[maxn];

pii cal_c(int p, int t)
{
    int r = ((p - 1 - m + t) % n + n) % n + 1;
    int l = ((p - 1 - m) % n + n) % n + 1;
    if(l > r) r += n;
    return mp(l, r);
}

pii cal_a(int p, int t)
{
    int r = (p - 1 + m) % n + 1;
    int l = (p - 1 + m - t) % n + 1;
    if(l > r) r += n;
    return mp(l, r);
}

bool visit(int p, int t)
{
    int sum = 0;
    // Clock
    pii cloc = cal_c(p, t);
    sum += c[cloc.se] - c[cloc.fi - 1];
    // Anti
    pii anti = cal_a(p, t);
    sum += a[anti.se] - a[anti.fi - 1];
    return sum > 0;
}

int main()
{
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d%d", &n, &G, &m);
        for(int i = 0; i <= (n << 1); ++ i) c[i] = a[i] = cc[i] = ca[i] = 0;
        for(int i = 1; i <= n; ++ i) gc[i].clear(), ga[i].clear();
        for(int i = 1; i <= G; ++ i)
        {
            ans[i] = 0;
            int x; char cc;
            scanf("%d %c", &x, &cc);
            if(cc == 'C') {c[x] ++; c[x + n] ++; gc[x].pb(i);}
            else {a[x] ++; a[x + n] ++; ga[x].pb(i);}
        }
        for(int i = 1; i <= (n << 1); ++ i) c[i] += c[i - 1], a[i] += a[i - 1];
        for(int i = 1; i <= n; ++ i)
        {
            int l = 0, r = min(m, n - 1);
            if(!visit(i, r)) continue;
            while(r - l > 1)
            {
                int mid = (l + r) >> 1;
                if(visit(i, mid)) r = mid; else l = mid;
            }
            while(!visit(i, l)) ++ l;
            int pos_c = ((i - 1 - m + l) % n + n) % n + 1;
            int pos_a = (i - 1 + m - l) % n + 1;
            cc[pos_c] ++; ca[pos_a] ++;
            //printf("%d c:%d a:%d\n", i, pos_c, pos_a);
        }
        for(int i = 1; i <= n; ++ i)
        {
            for(int p : gc[i]) ans[p] = cc[i];
            for(int p : ga[i]) ans[p] = ca[i];
        }
        printf("Case #%d:", cas);
        for(int i = 1; i <= G; ++ i) printf(" %d", ans[i]);
        puts("");
    }
    return 0;
}
