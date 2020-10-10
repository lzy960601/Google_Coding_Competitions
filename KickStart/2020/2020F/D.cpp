/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-09-27
File: D.cpp
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

#define IN freopen("D.in", "r", stdin)
#define OUT freopen("D.out", "w", stdout)
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

int T, n, m, k;

unordered_map<ull, double> ans;

void unpress(int g[], ull state)
{
    for(int i = 0; i <= n + 1; ++ i) g[i] = 0;
    int last = 0, num = 0;
    while(state > 0)
    {
        if(state & 1)
        {
            int v = num - last;
            ++ g[v]; last = num;
        }
        state >>= 1; ++ num;
    }
}

ull press(int g[], int len)
{
    -- g[len]; ++ g[len + 1];
    ull ret = 0;
    int num = 0;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= g[i]; ++ j)
        {
            num += i;
            ret |= 1ll << num;
        }
    ++ g[len]; -- g[len + 1];
    return ret;
}

int tg[55];
int presum = 0;
ull target = 0;

struct Strategy
{
    int num, cnt;
    double expe, poss;
    bool operator < (const struct Strategy &p) const
    {return expe < p.expe;}
    void print() { printf("%d %d %f %f\n", num, cnt, expe, poss); }
};

double DFS(ull state)
{
    if(state == target) return 0;
    if(ans.find(state) != ans.end()) return ans[state];
    int ng[55]; unpress(ng, state);
    vector<Strategy> tmp; tmp.clear();
    int sum = ng[n];
    ng[0] = m; for(int i = n; i >= 1; -- i) ng[0] -= ng[i];
    for(int i = n - 1; i >= 0; -- i)
    {
        if(ng[i] == 0) continue;
        if(sum < tg[i + 1])
        {
            ull nex = press(ng, i);
            tmp.pb({i, ng[i], DFS(nex), (double)ng[i] / (double)m});
        }
        sum += ng[i];
    }
    sort(tmp.begin(), tmp.end());
    //printf("\n%llu : \n", state); for(Strategy s : tmp) s.print();
    double ret = 1e18, P = 0, S = 0;
    for(Strategy s : tmp)
    {
        S += s.expe * s.poss;
        P += s.poss;
        double nex = (1 + S) / P;
        ret = min(nex, ret);
    }
    return ans[state] = ret;
}

void Solve(int cas)
{
    presum = 0; target = 0;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n + 1; ++ i) tg[i] = 0;
    for(int i = 1; i <= k; ++ i)
    {
        int x; scd(x);
        presum += x; target |= 1ll << presum;
        ++ tg[x];
    }
    for(int i = n; i >= 1; -- i) tg[i] += tg[i + 1];
    ans.clear(); double ret = DFS(0ll);
    prcas; printf("%.10f\n", ret);
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas) Solve(cas);
    return 0;
}
