/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-16
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

const int maxn = 105;
const double inf = 1e18;
double dis[maxn][maxn];
int n, m, P;

struct Matrix
{
    int o;
    double a[maxn][maxn];

    void init0()
    {
        for(int i = 0; i < o; ++ i)
            for(int j = 0; j < o; ++ j)
                a[i][j] = 0;
    }

    void init1()
    {
        init0();
        for(int i = 0; i < o; ++ i) a[i][i] = 1;
    }
}I;

Matrix multi(Matrix A, Matrix B)
{
    assert(A.o == B.o);
    int o = A.o;
    Matrix C; C.o = o; C.init0();
    for(int i = 0; i < o; ++ i)
        for(int k = 0; k < o; ++ k)
        {
            if(A.a[i][k] < eps) continue;
            for(int j = 0; j < o; ++ j)
                C.a[i][j] += A.a[i][k] * B.a[k][j];
        }
    return C;
}

Matrix add(Matrix A, Matrix B)
{
    assert(A.o == B.o);
    int o = A.o;
    Matrix C; C.o = o; C.init0();
    for(int i = 0; i < o; ++ i)
        for(int j = 0; j < o; ++ j)
            C.a[i][j] = A.a[i][j] + B.a[i][j];
    return C;
}

void powSUM(Matrix &A, int y, Matrix &sum, Matrix &val) // [1, y]
{
    if(y == 1) { sum = val = A; return; }
    powSUM(A, y >> 1, sum, val);
    sum = add(sum, multi(sum, val));
    val = multi(val, val);
    if(y & 1)
    {
        val = multi(val, A);
        sum = add(sum, val);
    }
}

double solve()
{
    scanf("%d%d%d", &n, &m, &P);
    I.o = n; I.init1();
    for(int i = 0; i < n; ++ i)
        for(int j = 0; j < n; ++ j)
            if(i == j) dis[i][j] = 0; else dis[i][j] = inf;
    while(m --)
    {
        int x, y; double z;
        scanf("%d%d%lf", &x, &y, &z);
        -- x; -- y;
        dis[x][y] = dis[y][x] = min(dis[x][y], z);
    }
    for(int k = 0; k < n; ++ k)
        for(int i = 0; i < n; ++ i)
            for(int j = 0; j < n; ++ j)
                dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
    Matrix T, D;
    T.o = D.o = n;
    double con = 1.0 / (double)(n - 1);
    for(int i = 0; i < n; ++ i)
        for(int j = 0; j < n; ++ j)
            if(i != j)
            {
                T.a[i][j] = con;
                D.a[i][j] = dis[i][j] * con;
            }else T.a[i][j] = D.a[i][j] = 0;
    Matrix bg; bg.o = n; bg.init0();
    bg.a[0][0] = 1.0;
    Matrix sum, val; sum.o = val.o = n; sum.init0(); val.init0();
    if(P > 1) powSUM(T, P - 1, sum, val);
    Matrix ret = multi(multi(bg, add(I, sum)), D);
    double ans = 0;
    for(int i = 0; i < n; ++ i) ans += ret.a[0][i];
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