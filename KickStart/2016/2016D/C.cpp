/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-06-01
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

const int mod = 1e9 + 7;
mt19937 rnd(19260817);
map<int, int> cnt;
int n, m, dp[4005];
int val[26];
char s[4005];

void solve(int cas)
{
    for(int i = 0; i < 26; ++ i) val[i] = rnd() % mod;
    scanf("%d%d", &n, &m); cnt.clear();
    while(n --)
    {
        scs(s + 1); int l = strlen(s + 1);
        int v = 0;
        for(int i = 1; i <= l; ++ i)
            (v += val[s[i] - 'a']) %= mod;
        cnt[v] ++;
    }
    prcas;
    for(int sc = 1; sc <= m; ++ sc)
    {
        scs(s + 1); int k = strlen(s + 1);
        dp[0] = 1;
        for(int i = 1; i <= k; ++ i)
        {
            dp[i] = 0; int su = 0;
            for(int j = i; j > max(0, i - 20); -- j)
            {
                (su += val[s[j] - 'a']) %= mod;
                int c = 0;
                if(cnt.find(su) != cnt.end()) c = cnt[su];
                (dp[i] += 1ll * dp[j - 1] * c % mod) %= mod;
            }
        }
        printf("%d%c", dp[k], sc == m ? '\n' : ' ');
    }
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
        solve(cas);
    return 0;
}