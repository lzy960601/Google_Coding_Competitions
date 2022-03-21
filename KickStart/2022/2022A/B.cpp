/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2022-03-20
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

const int maxn = 200005;
char s[maxn];

void solve(int cas)
{
    scs(s + 1); int n = strlen(s + 1);
    prcas;
    if(n == 1 && s[1] == '0') { puts("90"); return; }
    int sum = 0;
    for(int i = 1; i <= n; ++ i) sum += (s[i] - '0');
    int nnn = (9 - (sum % 9)) % 9;
    if(nnn == 0)
    {
        putchar(s[1]);
        putchar('0');
        for(int i = 2; i <= n; ++ i) putchar(s[i]);
        puts("");
        return;
    }
    bool flag = true;
    for(int i = 1; i <= n; ++ i)
    {
        int v = s[i] - '0';
        if(v > nnn && flag)
        {
            putchar(nnn + '0');
            flag = false;
        }
        putchar(s[i]);
    }
    if(flag) putchar(nnn + '0');
    puts("");
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