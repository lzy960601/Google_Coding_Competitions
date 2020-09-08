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

const LL limit = 1e12;
const int maxn = 505;
int n, m, S, R;
LL dis[maxn][maxn], stone[maxn][maxn];
vi rpti[maxn];
bool inQ[maxn][maxn];


struct Recipe
{
    int len, tar;
    vi rec;

    void read()
    {
        scd(len); rec.clear();
        int x;
        for(int i = 1; i <= len; ++ i) {scd(x); rec.pb(x);}
        scd(tar); sort(rec.begin(), rec.end());
    }
}rpt[maxn];
struct Status
{
    int pos, typ;
    LL val;

    bool operator < (const struct Status &p) const
    {return val > p.val;}
};
priority_queue<Status> q;

void FLOYD()
{
    for(int k = 1; k <= n; ++ k)
        for(int i = 1; i <= n; ++ i)
            for(int j = 1; j <= n; ++ j)
                if(dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
}

void READ()
{
    scanf("%d%d%d%d", &n, &m, &S, &R);
    for(int i = 1; i <= n; ++ i)
    {
        for(int j = 1; j <= n; ++ j)
            dis[i][j] = limit;
        dis[i][i] = 0;
        for(int j = 1; j <= S; ++ j)
            stone[i][j] = limit, inQ[i][j] = false;
    }
    for(int i = 1; i <= S; ++ i) rpti[i].clear();
    while(m --) {int x, y; scanf("%d%d", &x, &y); dis[x][y] = dis[y][x] = 1;}
    while(!q.empty()) q.pop();
    for(int i = 1; i <= n; ++ i)
    {
        int c, x; scd(c);
        while(c --) 
        { 
            scd(x); stone[i][x] = 0; 
            q.push({i, x, 0});
            inQ[i][x] = true;
        }
    }
    for(int i = 1; i <= R; ++ i)
    {
        rpt[i].read();
        int last = 0;
        for(int p : rpt[i].rec)
            if(p != last)
            {
                rpti[p].pb(i);
                last = p;
            }
    }
}

void Combine(int i, int t)
{
    for(int id : rpti[t])
    {
        LL cost = 0;
        for(int k : rpt[id].rec) cost += stone[i][k];
        if(cost >= limit) continue;
        int ta = rpt[id].tar;
        if(stone[i][ta] > cost)
        {
            stone[i][ta] = cost;
            q.push({i, ta, stone[i][ta]});
        }
    }
}

void update(Status sta)
{
    int p = sta.pos, t = sta.typ;
    //assert(stone[p][t] == sta.val);
    LL d = stone[p][t];
    Combine(p, t);
    for(int i = 1; i <= n; ++ i)
    {
        if(stone[i][t] > d + dis[i][p])
        {
            stone[i][t] = d + dis[i][p];
            Combine(i, t); 
        }
    }
}

void SPFA()
{
    while(!q.empty())
    {
        Status sta = q.top(); q.pop();
        if(stone[sta.pos][sta.typ] < sta.val) continue;
        update(sta);
    }
}

void PREADD()
{
    for(int i = 1; i <= n; ++ i)
        for(int k = 1; k <= S; ++ k)
            for(int j = 1; j <= n; ++ j)
                stone[i][k] = min(stone[i][k], dis[i][j] + stone[j][k]);
    for(int i = 1; i <= n; ++ i)
        for(int t = 1; t <= S; ++ t)
            Combine(i, t);
}

void SOLVE(int cas)
{
    READ();
    FLOYD();
    PREADD();
    SPFA();
    LL ans = 1e12;
    for(int i = 1; i <= n; ++ i) ans = min(ans, stone[i][1]);
    prcas; printf("%lld\n", ans < limit ? ans : (LL)-1);
}

int main()
{	
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        SOLVE(cas);
    }
    return 0;
}


