/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-03
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

vector<pair<double, double>> X, Y;

inline double aabs(double v) { return v < 0 ? -v : v; }

double cal(vector<pair<double, double>> &V)
{
    int id = 0;
    double sum = 0, pre = 0;
    for(pair<double, double> p : V) sum += p.se;
    for(unsigned int i = 0; i < V.size(); ++ i)
    {
        double suf = sum - pre - V[i].se;
        if(pre + V[i].se >= suf && suf + V[i].se >= pre) { id = i; break; }
        pre += V[i].se;
    }
    double ret = 0;
    for(unsigned int i = 0; i < V.size(); ++ i)
        ret += aabs(V[i].fi - V[id].fi) * V[i].se;
    return ret;
}

double solve()
{
    int n; scd(n);
    X.clear(); Y.clear();
    for(int i = 1; i <= n; ++ i)
    {
        double x, y, w;
        scanf("%lf%lf%lf", &x, &y, &w);
        double nx = (x + y) * 0.5;
        double ny = (x - y) * 0.5;
        X.pb(mp(nx, w)); Y.pb(mp(ny, w));
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    return cal(X) + cal(Y);
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