/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-19
File: B.cpp
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
int a[maxn][maxn], v[maxn][maxn], n, m;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct cell
{
    int h, x, y;
    bool operator < (const struct cell &p) const
    { return h > p.h; }
};
priority_queue<cell> q;

bool legal(int x, int y)
{ return 1 <= x && 1 <= y && x <= n && y <= m; }

int solve()
{
    int ans = 0;
    while(!q.empty()) q.pop();
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
        {
            v[i][j] = 0;
            scd(a[i][j]);
            if(i == 1 || j == 1 || i == n || j == m)
            {
                v[i][j] = 1;
                q.push({a[i][j], i, j});
            }
        }
    while(!q.empty())
    {
        cell c = q.top(); q.pop();
        int h = c.h, x = c.x, y = c.y;
        for(int d = 0; d < 4; ++ d)
        {
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];
            if(!legal(nx, ny) || v[nx][ny] > 0) continue;
            v[nx][ny] = 1; q.push({max(h, a[nx][ny]), nx, ny});
            ans += max(0, h - a[nx][ny]);
        }
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