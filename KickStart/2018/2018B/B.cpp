/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-17
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

const int maxn = 105;
const LL inf = 1e18 + 5;

LL dp[maxn][66666], P;
vector<pii> g[maxn];
int ans[maxn], cnt[66666];
int T, n, m;

void solve()
{
    scanf("%d%d", &n, &m); scld(P);
    for(int i = 0; i <= n + 1; ++ i) g[i].clear();
    while(m --)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].pb(mp(y - x + 1, z));
    }
    // DoSuf
    for(int k = 0; k < (1 << 16); ++ k) dp[n + 1][k] = 0;
    dp[n + 1][0] = 1;
    for(int i = n; i >= 1; -- i)
    {
        for(int k = 0; k < (1 << 16); ++ k)
            dp[i][k] = 0;
        for(int cur = 0; cur < 2; ++ cur)
            for(int k = 0; k < (1 << 16); ++ k)
            {
                if(dp[i + 1][k] == 0) continue;
                int now = (cur << 15) + (k >> 1);
                bool flag = true;
                for(pii p : g[i])
                    if(cnt[now >> (16 - p.fi)] != p.se)
                    {
                        flag = false;
                        break;
                    }
                if(flag) dp[i][now] += dp[i + 1][k];
                dp[i][now] = min(dp[i][now], inf);
            }
    }
    // DoPre
    for(int i = 1; i <= n; ++ i)
    {
        LL cal[2] = {0};
        for(int cur = 0; cur < 2; ++ cur)
            for(int k = 0; k < (1 << 16); ++ k)
            {
                if(dp[i + 1][k] == 0) continue;
                int now = (cur << 15) + (k >> 1);
                bool flag = true;
                for(pii p : g[i])
                    if(cnt[now >> (16 - p.fi)] != p.se)
                    {
                        flag = false;
                        break;
                    }
                if(flag) 
                {
                    cal[cur] += dp[i + 1][k];
                    cal[cur] = min(cal[cur], inf);
                }
            }
        //assert(cal[0] + cal[1] >= P);
        if(cal[0] >= P)
        {
            ans[i] = 0;
        }else
        {
            P -= cal[0];
            ans[i] = 1;
        }
        for(pii p : g[i])
        {
            //assert(p.se >= 0);
            if(p.fi > 1) g[i + 1].pb(mp(p.fi - 1, p.se - ans[i]));
        }
    }
}

int main()
{
    cnt[0] = 0; cnt[1] = 1;
    for(int i = 2; i < (1 << 16); ++ i)
        cnt[i] = cnt[i >> 1] + (i & 1);
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        solve(); prcas;
        for(int i = 1; i <= n; ++ i)
            putchar(48 + ans[i]);
        puts("");
    }
    return 0;
}