/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2022-10-05
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

struct Fabric
{
    string C;
    int D, U;
    void read() { cin >> C >> D >> U; }
}a[1005], b[1005];

bool cmp1(Fabric &x, Fabric &y)
{ return x.C == y.C ? x.U < y.U : x.C < y.C; }

bool cmp2(Fabric &x, Fabric &y)
{ return x.D == y.D ? x.U < y.U : x.D < y.D; }

int N;

int solve()
{
    cin >> N;
    for(int i = 1; i <= N; ++ i)
    {
        a[i].read();
        b[i] = a[i];
    }
    sort(a + 1, a + N + 1, cmp1);
    sort(b + 1, b + N + 1, cmp2);
    int ans = 0;
    for(int i = 1; i <= N; ++ i)
        if(a[i].U == b[i].U) ++ ans;
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