/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-30
File: A.cpp
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

#define IN freopen("A.in", "r", stdin)
#define OUT freopen("A.out", "w", stdout)
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

double P, Q;
char cc[21][21];
double a[21][21];
int n, m, S, bx, by;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void read()
{
    char c = getchar();
    for(int i = 0; i < n; ++ i)
        for(int j = 0; j < m; ++ j)
        {
            while(c != '.' && c != 'A') c = getchar();
            cc[i][j] = c; c = getchar();
        }
}

bool legal(int x, int y)
{ return x >= 0 && y >= 0 && x < n && y < m; }

void DFS(int x, int y, int step, double val, double &ans)
{
    if(step >= S)
    {
        ans = max(ans, val);
        return;
    }
    for(int d = 0; d < 4; ++ d)
    {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];
        if(!legal(nx, ny)) continue;
        double now = a[nx][ny], nxt = val;
        if(cc[nx][ny] == 'A')
        {
            nxt += a[nx][ny] * P;
            a[nx][ny] *= (1.0 - P);
            DFS(nx, ny, step + 1, nxt, ans);
        }else
        {
            nxt += a[nx][ny] * Q;
            a[nx][ny] *= (1.0 - Q);
            DFS(nx, ny, step + 1, nxt, ans);
        }
        a[nx][ny] = now;
    }
}

double solve()
{
    cin >> n >> m >> bx >> by >> S;
    cin >> P >> Q;
    read();
    double ans = 0;
    for(int i = 0; i < n; ++ i)
        for(int j = 0; j < m; ++ j)
            a[i][j] = 1.0;
    DFS(bx, by, 0, 0.0, ans);
    return ans;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        double ans = solve();
        prcas; printf("%.12f\n", ans);
    }
    return 0;
}