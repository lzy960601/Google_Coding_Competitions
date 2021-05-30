/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-29
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

const int maxn = 10005;
int cnt, n, ind[maxn];
char s[105];
map<string, int> m;
vi g[maxn];

int getid(string t)
{
    if(m.find(t) != m.end())
        return m[t];
    ++ cnt; 
    g[cnt].clear(); ind[cnt] = 0;
    return m[t] = cnt;
}

queue<int> q;

bool solve()
{
    scd(n); cnt = 0; m.clear();
    getid("");
    while(n --)
    {
        scs(s + 1);
        int k = strlen(s + 1);
        string now = "";
        int x = 0, y = -1;
        for(int i = 1; i <= k; ++ i)
        {
            if(s[i] == '=')
            {
                x = getid(now);
                now = "";
                continue;
            }
            if(s[i] == '(' && s[i + 1] == ')')
            {
                g[1].pb(x); ++ ind[x];
                break;
            }
            if(s[i] == '(')
            {
                y = 0; now = "";
                continue;
            }
            if(s[i] == ',' || s[i] == ')')
            {
                y = getid(now); 
                now = "";
                g[y].pb(x); ++ ind[x];
                continue;
            }
            now += s[i];
        }
    }
    while(!q.empty()) q.pop();
    int root = getid("");
    assert(ind[root] == 0);
    q.push(root);
    int all = 0;
    while(!q.empty())
    {
        int p = q.front(); q.pop();
        ++ all;
        for(int x : g[p])
        {
            ind[x] --;
            if(ind[x] == 0) q.push(x);
        }
    }
    return all >= cnt;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        bool ans = solve();
        prcas; puts(ans ? "GOOD" : "BAD");
    }
    return 0;
}