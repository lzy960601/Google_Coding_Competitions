/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-04-04
File: C.cpp
*****************************************/
  
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

struct node
{
    int s, t, pos;
    void read(int p){ pos = p; scanf("%d%d", &s, &t); }
    bool operator < (const struct node& p) const
    { return s < p.s; }
}s[1005];
char c[1005];
int T, n;

bool solve()
{
    int a = 0, b = 0;
    for(int i = 1; i <= n; ++ i)
    {
        if(a <= s[i].s) { a = s[i].t; c[s[i].pos] = 'C'; continue; }
        if(b <= s[i].s) { b = s[i].t; c[s[i].pos] = 'J'; continue; }
        return false;
    }
    return true;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scd(n);
        for(int i = 1; i <= n; ++ i) s[i].read(i);
        sort(s + 1, s + n + 1);
        prcas;
        if(!solve()) puts("IMPOSSIBLE"); else 
        { for(int i = 1; i <= n; ++ i) putchar(c[i]); puts(""); }
    }
    return 0;
}
