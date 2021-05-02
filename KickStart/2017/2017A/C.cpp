/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-20
File: C.cpp
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

#define IN freopen("C.in", "r", stdin)
#define OUT freopen("C.out", "w", stdout)
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

const int inf = 5e8;

struct ball
{
    int c[3], r;
    void read() { scanf("%d%d%d%d", &c[0], &c[1], &c[2], &r); }
};
int n;

int cal(vector<ball> &V)
{
    if(V.size() <= 0) return 0;
    int minb[3] = {inf, inf, inf}, maxb[3] = {-inf, -inf, -inf};
    for(int d = 0; d < 3; ++ d)
    {
        for(ball b : V)
        {
            minb[d] = min(minb[d], b.c[d] - b.r);
            maxb[d] = max(maxb[d], b.c[d] + b.r);
        }
    }
    int ret = -inf;
    for(int d = 0; d < 3; ++ d) ret = max(ret, maxb[d] - minb[d]);
    return ret;
}

int getans(vector<ball> &V, int tar[], int D)
{
    vector<ball> notcover; notcover.clear();
    for(ball b : V)
    {
        bool flag = true;
        for(int d = 0; d < 3; ++ d)
            if(tar[d] > b.c[d] - b.r || tar[d] + D < b.c[d] + b.r) { flag = false; break; }
        if(!flag) notcover.pb(b);
    }
    return cal(notcover) <= D;
}

vector<ball> balls;

int solve()
{
    scd(n); balls.clear();
    for(int i = 1; i <= n; ++ i) 
    {
        ball tmp; tmp.read();
        balls.pb(tmp);
    }
    int minb[3] = {inf, inf, inf}, maxb[3] = {-inf, -inf, -inf};
    for(int d = 0; d < 3; ++ d)
    {
        for(ball b : balls)
        {
            minb[d] = min(minb[d], b.c[d] - b.r);
            maxb[d] = max(maxb[d], b.c[d] + b.r);
        }
    }
    int tar[3] = {inf, inf, inf}, ans = inf, oneD = -inf;
    for(int d = 0; d < 3; ++ d) oneD = max(oneD, maxb[d] - minb[d]);
    int co[3];
    for(co[0] = 0; co[0] <= 1; ++ co[0])
    for(co[1] = 0; co[1] <= 1; ++ co[1])
    for(co[2] = 0; co[2] <= 1; ++ co[2])
    {
        int l = 0, r = oneD;
        while(r - l > 1)
        {
            int mid = (l + r) >> 1;
            for(int d = 0; d < 3; ++ d)
                if(co[d] == 0) tar[d] = minb[d]; else tar[d] = maxb[d] - mid;
            if(getans(balls, tar, mid)) r = mid; else l = mid;    
        }
        for(int d = 0; d < 3; ++ d)
                if(co[d] == 0) tar[d] = minb[d]; else tar[d] = maxb[d] - l;
        while(!getans(balls, tar, l)) 
        {
            ++ l;
            for(int d = 0; d < 3; ++ d)
                if(co[d] == 0) tar[d] = minb[d]; else tar[d] = maxb[d] - l;
        }
        ans = min(ans, l);
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