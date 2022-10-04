/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2022-10-04
File: D.cpp
*****************************************/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
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
#define rng(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
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

struct Meeting 
{
    int id, l, r;
    void read() { scanf("%d%d%d", &id, &l, &r); }
};
int N, K, X, D, M;
vector<Meeting> bg[maxn], ed[maxn];
int now[maxn];
set<pii> use, bak;

bool check()
{
    if(bak.empty()) return false;
    set<pii>::iterator ui = use.end(), bi = bak.begin();
    ui --; pii rem = *ui, add = *bi;
    return rem.fi > add.fi;
}

void update(int id, int delta, int &sum)
{
    pii bef = mp(now[id], id);
    if(use.find(bef) != use.end())
    {
        use.erase(bef); sum -= bef.fi;
        now[id] += delta; use.insert(mp(now[id], id));
        sum += now[id];
    } else if(bak.find(bef) != bak.end())
    {
        bak.erase(bef);
        now[id] += delta; bak.insert(mp(now[id], id));
    }else assert(1);
    while(check())
    {
        set<pii>::iterator ui = use.end(), bi = bak.begin();
        ui --; pii rem = *ui, add = *bi;
        sum -= rem.fi; use.erase(rem); bak.erase(add);
        sum += add.fi; use.insert(add); bak.insert(rem);
    }
}

int solve()
{
    int ans = 1e9 + 7, sum = 0;
    scanf("%d%d%d%d%d", &N, &K, &X, &D, &M); use.clear(); bak.clear();
    for(int i = 0; i <= D; ++ i) bg[i].clear(), ed[i].clear();
    for(int i = 1; i <= N; ++ i) now[i] = 0;
    for(int i = 1; i <= K; ++ i) use.insert(mp(0, i));
    for(int i = K + 1; i <= N; ++ i) bak.insert(mp(0, i));
    for(int i = 1; i <= M; ++ i)
    {
        Meeting x; x.read();
        if(x.l == x.r) continue;
        bg[x.l].pb(x); ed[x.r].pb(x);
    }
    int ri = 0;
    for(int le = 0; le + X <= D; ++ le)
    {
        while(ri < le + X)
        {
            for(Meeting x : bg[ri]) update(x.id, 1, sum);
            ri ++;
        }
        for(Meeting x : ed[le]) update(x.id, -1, sum);
        ans = min(ans, sum);
    }
    return ans;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; printf("%d\n", ans);
    }
    return 0;
}