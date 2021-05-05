/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-04
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

char s[55][55];

bool solve()
{
    int n; scd(n);
    vector<pii> col; col.clear();
    int ro = 0, co = 0;
    for(int i = 1; i <= n; ++ i) scs(s[i] + 1);
    for(int i = 1; i <= n; ++ i)
    {
        vi rec; rec.clear();
        for(int j = 1; j <= n; ++ j)
            if(s[i][j] == 'X') rec.pb(j);
        if(rec.size() <= 0 || rec.size() > 2) return false;
        if(rec.size() == 1)
        {
            if(co > 0) return false;
            ro = i; co = rec[0];
            continue;
        }
        col.pb(mp(rec[0], rec[1]));
    }
    sort(col.begin(), col.end());
    for(int i = 1; i < n; i += 2)
        if(col[i - 1] != col[i]) return false;
    col.clear(); ro = co = 0;
    for(int i = 1; i <= n; ++ i)
    {
        vi rec; rec.clear();
        for(int j = 1; j <= n; ++ j)
            if(s[j][i] == 'X') rec.pb(j);
        if(rec.size() <= 0 || rec.size() > 2) return false;
        if(rec.size() == 1)
        {
            if(co > 0) return false;
            ro = i; co = rec[0];
            continue;
        }
        col.pb(mp(rec[0], rec[1]));
    }
    sort(col.begin(), col.end());
    for(int i = 1; i < n; i += 2)
        if(col[i - 1] != col[i]) return false;
    return true;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        bool ans = solve();
        prcas; puts(ans ? "POSSIBLE" : "IMPOSSIBLE");
    }
    return 0;
}
