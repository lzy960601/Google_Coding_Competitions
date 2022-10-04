/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2022-08-21
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

const LL inf = 1e18l;

int n, m, P, xr, yr;
LL dp[15][15][25][1055];
int inq[15][15][25][1055];
pii pos[15][15];

struct State {
    int x, y;
    int minute;
    int mask;
};

struct Cost {
    char op;
    int nu;
    LL process(LL v) {
        if (op == '+') return v + nu;
        if (op == '-') return v - nu;
        if (op == '*') return v * nu;
        if (op == '/') {
            int vv = v < 0 ? -v : v;
            if(v >= 0 || vv % nu == 0) return v / nu;
            return -((vv + nu - 1) / nu);
        }
        return -inf;
    }
    void read() {
        char c = getchar();
        while(c != '+' && c != '-' && c != '*' && c != '/') {
            c = getchar();
            //puts("!!!" + c);
        }
        op = c; scd(nu);
        //cerr << op << " --- " << nu << endl;
    }
}co[5];
int dirx[5] = {-1, 0, 0, 1, 0};
int diry[5] = {0, 1, -1, 0, 0};

queue<State> q;

LL solve()
{
    scanf("%d%d%d%d%d", &n, &P, &m, &xr, &yr);
    //cerr << n << P << m << endl;
    for(int i = 0; i < 4; ++ i) co[i].read();
    co[4] = {'+', 0};
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
            pos[i][j] = mp(-1, -1);
    for(int i = 0; i < P; ++ i) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        pos[x][y] = mp(i, z);
    }
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
            for(int k = 0; k <= m; ++ k)
                for(int mask = 0; mask < (1 << P); ++ mask) {
                    dp[i][j][k][mask] = -inf;
                    inq[i][j][k][mask] = 0;
                }
    dp[xr][yr][0][0] = 0; inq[xr][yr][0][0] = 1;
    while(!q.empty()) q.pop();
    q.push({xr, yr, 0, 0});
    while(!q.empty()) {
        State sta = q.front(); q.pop();
        LL c = dp[sta.x][sta.y][sta.minute][sta.mask];
        //cerr << sta.x << "-" << sta.y << " : " << sta.minute << "(" << m << ")" << " | " << sta.mask << " === " << c << endl;
        if(sta.minute >= m) continue;
        for(int d = 0; d < 5; ++ d) {
            int nx = sta.x + dirx[d];
            int ny = sta.y + diry[d];
            int nmask = sta.mask;
            int nm = sta.minute + 1;
            if(nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
            LL nv = co[d].process(c);

            // not deliver
            if (!inq[nx][ny][nm][nmask]) {
                inq[nx][ny][nm][nmask] = 1;
                q.push({nx, ny, nm, nmask});
            }
            dp[nx][ny][nm][nmask] = max(dp[nx][ny][nm][nmask], nv);

            // deliver
            pii pp = pos[nx][ny];
            if(pp.fi < 0 || ((sta.mask >> pp.fi) & 1) == 1) continue;
            nv += pp.se; nmask |= (1 << pp.fi);
            if (!inq[nx][ny][nm][nmask]) {
                inq[nx][ny][nm][nmask] = 1;
                q.push({nx, ny, nm, nmask});
            }
            dp[nx][ny][nm][nmask] = max(dp[nx][ny][nm][nmask], nv);
        }
    }
    LL ans = -inf;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
            ans = max(ans, dp[i][j][m][(1 << P) - 1]);
    return ans;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        LL ans = solve();
        prcas; 
        if(ans <= -inf) puts("IMPOSSIBLE"); else printf("%lld\n", ans);
    }
    return 0;
}