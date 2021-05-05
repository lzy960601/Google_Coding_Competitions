/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-04
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

char s[55];
int a[55], b[55], c[55];

void solve(int cas)
{
    scs(s + 1); int n = strlen(s + 1), cnt = 0;
    for(int i = 1; i <= n; ++ i) a[i] = s[i] - 65;
    b[0] = b[n + 1] = 0;
    for(b[1] = 0; b[1] <= 25; ++ b[1])
    {
        for(int i = 2; i <= n; ++ i)
            b[i] = (26 + a[i - 1] - b[i - 2]) % 26;
        bool flag = true;
        for(int i = 1; i <= n; ++ i)
            if((b[i - 1] + b[i + 1]) % 26 != a[i]) { flag = false; break; }
        if(flag)
        {
            ++ cnt;
            if(cnt > 1) break;
            for(int i = 1; i <= n; ++ i) c[i] = b[i];
        }
    }
    prcas;
    if(cnt > 1) puts("AMBIGUOUS");
    else
    {
        for(int i = 1; i <= n; ++ i) putchar(c[i] + 65);
        puts("");
    }
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        solve(cas);
    }
    return 0;
}