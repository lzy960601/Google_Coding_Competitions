/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-15
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

const int N = 105;
const int INF = 1e9 + 7;
int cost[N][N], n;
int lx[N], ly[N], match[N], slack[N], pre[N]; 
bool vy[N]; 
void augment(int root) 
{
    memset(vy, 0, sizeof(vy)); 
    memset(slack, 0x3f3f3f3f, sizeof(slack)); 
    int py; 
    match[py = 0] = root; 
    do {
        vy[py] = true;
        int x = match[py], delta = INF, yy;
        for (int y = 1; y <= n; ++y)
            if (!vy[y]) 
            { 
                if (lx[x] + ly[y] - cost[x][y] < slack[y]) 
                { 
                    slack[y] = lx[x] + ly[y] - cost[x][y]; 
                    pre[y] = py; 
                } 
                if (slack[y] < delta) 
                { 
                    delta = slack[y]; yy = y; 
                }
            } 
            for (int y = 0; y <= n; ++y) 
                if (vy[y]) 
                { 
                    lx[match[y]] -= delta; 
                    ly[y] += delta; 
                } else 
                    slack[y] -= delta; py = yy; 
        } while (match[py] != -1); 
        do { 
            int y = pre[py]; 
            match[py] = match[y]; 
            py = y; 
        } while (py);
} 
int KM() 
{
    for (int i = 1; i <= n; ++i) 
    { 
        lx[i] = ly[i] = 0; match[i] = -1; 
        for (int j = 1; j <= n; ++j) lx[i] = max(lx[i], cost[i][j]); 
    } 
    int ans = 0; for (int i = 1; i <= n; ++i) augment(i); 
    for (int i = 1; i <= n; ++i) 
    {
        ans += lx[i] + ly[i];
    } 
    return ans;
}

char s1[11][11], s2[11][11];

int aabs(int x) { return x < 0 ? -x : x; }

int solve()
{
    int nn, mm, f, s;
    scanf("%d%d%d%d", &nn, &mm, &f, &s); f <<= 1;
    for(int i = 1; i <= nn; ++ i) scs(s1[i] + 1);
    for(int i = 1; i <= nn; ++ i) scs(s2[i] + 1);
    n = nn * mm;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
        {
            int ix = (i - 1) / mm + 1, iy = ((i - 1) % mm) + 1;
            int jx = (j - 1) / mm + 1, jy = ((j - 1) % mm) + 1;
            int c = (aabs(ix - jx) + aabs(iy - jy)) * s + f * (s1[ix][iy] != s2[jx][jy]);
            cost[i][j] = -c;
        }
    return (-KM()) >> 1;
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