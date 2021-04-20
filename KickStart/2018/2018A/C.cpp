/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-19
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

const int mod = 1e9 + 7;
const int base = 499;
const int limit = 300;
const int maxn = 1000005;
const int maxm = 100005;    
int ss[maxm], a[maxn], n, bas[27], L;
unordered_map<int, int> rec[limit + 5];
char s[maxm];
vector<pii> longWord;

void gen()
{
    char s1, s2;
    int A, B, C, D;
    char c = getchar();
    while(c < 'a' || c > 'z') c = getchar();
    s1 = c; c = getchar();
    while(c < 'a' || c > 'z') c = getchar();
    s2 = c;
    scanf("%d%d%d%d%d", &n, &A, &B, &C, &D);
    a[1] = s1; a[2] = s2;
    for(int i = 3; i <= n; ++ i)
        a[i] = (1ll * a[i - 1] * A + 1ll * a[i - 2] * B + C) % D;
    a[1] -= 96; a[2] -= 96;
    for(int i = 3; i <= n; ++ i) a[i] = (a[i] % 26) + 1;
}

LL solve()
{
    LL ans = 0;
    for(int i = 1; i <= limit; ++ i) rec[i].clear();
    scanf("%d", &L); longWord.clear();
    while(L --)
    {
        scs(s + 1);
        int l = strlen(s + 1), h = 0;
        for(int i = 1; i <= l; ++ i) ss[i] = s[i] - 96;
        if(l == 1) h = ss[1];
        else
        {
            h = ss[1] + base * ss[l];
            for(int i = 2; i < l; ++ i)
                (h += bas[ss[i]]) %= mod;
        }
        if(l <= limit) rec[l][h] ++;
        else longWord.pb(mp(l, h));
    }
    gen();

    // Count for short
    for(int len = 1; len <= 2; ++ len)
    {
        if(rec[len].size() <= 0) continue;
        for(int i = 1; i + len - 1 <= n; ++ i)
        {
            int h = a[i];
            if(len == 2) h += base * a[i + 1];
            if(rec[len].find(h) != rec[len].end())
            {
                ans += rec[len][h];
                rec[len][h] = 0;
            }
        }
    }
    for(int len = 3; len <= limit; ++ len)
    {
        if(rec[len].size() <= 0) continue;
        int h1 = a[1] + base * a[len], h2 = 0, h = 0;
        for(int i = 2; i < len; ++ i)
            (h2 += bas[a[i]]) %= mod;
        h = (h1 + h2) % mod;
        if(rec[len].find(h) != rec[len].end())
        {
            ans += rec[len][h];
            rec[len][h] = 0;
        }
        for(int bg = 2; bg + len - 1 <= n; ++ bg)
        {
            h1 = a[bg] + base * a[bg + len - 1];
            (h2 += mod - bas[a[bg]]) %= mod;
            (h2 += bas[a[bg + len - 2]]) %= mod;
            h = (h1 + h2) % mod;
            if(rec[len].find(h) != rec[len].end())
            {
                ans += rec[len][h];
                rec[len][h] = 0;
            }
        }
    }

    // Count for long
    for(pii p : longWord)
    {
        int len = p.fi, th = p.se;
        int h1 = a[1] + base * a[len], h2 = 0, h = 0;
        for(int i = 2; i < len; ++ i)
            (h2 += bas[a[i]]) %= mod;
        h = (h1 + h2) % mod;
        if(h == th)
        {
            ans ++;
            continue;
        }
        for(int bg = 2; bg + len - 1 <= n; ++ bg)
        {
            h1 = a[bg] + base * a[bg + len - 1];
            (h2 += mod - bas[a[bg]]) %= mod;
            (h2 += bas[a[bg + len - 2]]) %= mod;
            h = (h1 + h2) % mod;
            if(h == th)
            {
                ans ++;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    bas[0] = base;
    for(int i = 1; i <= 26; ++ i) bas[i] = 1ll * base * bas[i - 1] % mod;
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        LL ans = solve();
        prcas; printf("%lld\n", ans);
    }
    return 0;
}