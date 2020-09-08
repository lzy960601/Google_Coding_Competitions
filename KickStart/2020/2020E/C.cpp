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
struct toys
{
    int play, forget, pf, id;
    void read(int k){ id = k; scanf("%d%d", &play, &forget); pf = play + forget; }
}a[maxn];
int T, n;

bool cmp1(toys x, toys y)
{
    return x.pf > y.pf;
}

bool cmp2(toys x, toys y)
{
    return x.id < y.id;
}

int judge()
{
    LL sum = 0;
    for(int i = 1; i <= n; ++ i) sum += a[i].play;
    for(int i = 1; i <= n; ++ i)
    {
        if(sum >= a[i].pf) return i - 1;
        sum -= a[i].play;
    }
    return -1;
}

priority_queue< pii > q;

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scd(n); 
        for(int i = 1; i <= n; ++ i) a[i].read(i);

        sort(a + 1, a + n + 1, cmp1); int tmp = judge();
        if(tmp >= 0) { prcas; printf("%d INDEFINITELY\n", tmp); continue; } 

        LL sum = 0;
        for(int i = 1; i <= n; ++ i) sum += a[i].play;
        LL ans = sum, now = sum, mac = 0, cnt = 0;
        sort(a + 1, a + n + 1, cmp2);
        while(!q.empty()) q.pop();
        for(int i = 1; i <= n; ++ i)
        {
            if(sum >= a[i].pf)
            {
                q.push(mp(a[i].pf, i));
                now += a[i].play;
                if(now > ans)
                {
                    ans = now;
                    mac = cnt;
                }
            }else
            {
                ++ cnt;
                sum -= a[i].play;
                now -= a[i].play;
                while(!q.empty() && sum < q.top().fi)
                {
                    ++ cnt;
                    pii t = q.top(); q.pop();
                    sum -= a[t.se].play;
                    now -= 2ll * a[t.se].play;
                }
            }
        }
        prcas; printf("%lld %lld\n", mac, ans);
    }
    return 0;
}


