/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-07
File: B.cpp
*****************************************/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")  
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
const int maxm = 10005;
const int inf = 1e9 + 7;
int cnt[maxn][2], n, m, p, suf[maxn], T;
struct Trie
{
    int nc, son[maxm][2], val[maxm], dep[maxm];
    void clear(){ nc = 0; son[0][0] = son[0][1] = -1; val[0] = inf; dep[0] = 0;}
    void insert(char s[])
    {
        int now = 0;
        for(int i = 1; i <= p; ++ i)
        {
            int v = s[i] - 48;
            if(son[now][v] < 0)
            {
                ++ nc; dep[nc] = dep[now] + 1;
                son[now][v] = nc;
                son[nc][0] = son[nc][1] = -1; 
                val[nc] = inf;
            }
            now = son[now][v];
        }
    }
    void cal(int o)
    {
        if(dep[o] == p) return;
        for(int i = 0; i < 2; ++ i)
        {
            if(son[o][i] > 0) cal(son[o][i]);
            if(son[o][i] < 0) val[o] = min(val[o], cnt[dep[o] + 1][i ^ 1] + suf[dep[o] + 2]);
            else val[o] = min(val[o], cnt[dep[o] + 1][i ^ 1] + val[son[o][i]]);
        }
    }
    int getans(){ return val[0]; }
}tr;

char s[maxn];

int solve()
{
    tr.clear();
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 0; i <= p; ++ i)
        cnt[i][0] = cnt[i][1] = suf[i] = 0;
    suf[p + 1] = 0;
    while(n --)
    {
        scs(s + 1);
        for(int i = 1; i <= p; ++ i)
            cnt[i][s[i] - 48] ++;
    }
    for(int i = p; i >= 1; -- i)
        suf[i] = suf[i + 1] + min(cnt[i][0], cnt[i][1]);
    while(m --)
    {
        scs(s + 1);
        tr.insert(s);
    }
    tr.cal(0);
    return tr.getans();
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; printf("%d\n", ans);
    }
    return 0;
}
