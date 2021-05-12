/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-07
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
typedef pair<double, double> pdd;

const double inf = 1e18;
const double G = 0.001;
pdd poi[15];
vector<pdd> v;
double P, H;
int n; 

bool check(double r) //ax(P-x), a >= 0
{
    double step = r * G;
    for(int mask = 0; mask < (1 << n); ++ mask)
    {
        double lg = 0, rg = (H - r) / (P * P * 0.25);
        for(int i = 1; i <= n; ++ i)
        {
            int f = (mask >> (i - 1)) & 1;
            double x = poi[i].fi, y = poi[i].se;

            // f = 0, low; f = 1, up
            for(double c = max(0.0, x - r); c <= min(P, x + r); c += step)
            {   
                double d = sqrt(sqr(r) - sqr(c - x));
                if(f == 0)
                    rg = min(rg, (y - d) / (c * (P - c)));
                else
                    lg = max(lg, (y + d) / (c * (P - c)));
            }
            if(lg > rg) break;
        }
        if(lg <= rg) return true;
    }
    return false;
}

double solve()
{
    scanf("%d%lf%lf",  &n, &P, &H);
    for(int i = 1; i <= n; ++ i) scanf("%lf%lf", &poi[i].fi, &poi[i].se);
    sort(poi + 1, poi + n + 1);
    double l = 0, r = H;
    int cnt = 100;
    while(cnt --)
    {
        double mid = (l + r) * 0.5;
        if(check(mid)) l = mid; else r = mid;
    }
    return l;
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