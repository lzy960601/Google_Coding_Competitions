/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2022-08-21
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

const int maxn = 100005;
const int mod = 1e9 + 7;
const int base = 31;
int n, p_hash[maxn], s_hash[maxn], po[maxn], iv[maxn];
char s[maxn];

int mi(int x, int y) {
    if(x == 0) return 0;
    int ret = 1;
    while(y > 0) {
        if(y & 1) ret = 1ll * x * ret % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ret;
}

int get_hash_p(int l, int r, int n) {
    if(l > r) return 0;
    int ret = (p_hash[r] - p_hash[l - 1] + mod) % mod;
    ret = 1ll * ret * iv[l - 1] % mod;
    return ret;
}

int get_hash_s(int l, int r, int n) {
    if(l > r) return 0;
    int ret = (s_hash[l] - s_hash[r + 1] + mod) % mod;
    ret = 1ll * ret * iv[n - r] % mod;
    return ret;
}

string solve()
{
    string ans = "";
    scd(n); scs(s + 1);
    if(n <= 2) {
        ans += s[1];
        return ans;
    }
    p_hash[0] = 0; 
    for(int i = 1; i <= n; ++ i) {
        int v = s[i] - 'a' + 1;
        p_hash[i] = (p_hash[i - 1] + (1ll * po[i] * v % mod)) % mod;
    }
    s_hash[n + 1] = 0; 
    for(int i = n; i >= 1; -- i) {
        int v = s[i] - 'a' + 1;
        s_hash[i] = (s_hash[i + 1] + (1ll * po[n - i + 1] * v % mod)) % mod;
    }
    for(int i = 1; i < n - 1; ++ i) {
        int m = n + i, l1, l2, r1, r2;
        if(m & 1) {
            int mid = (m + 1) >> 1;
            l2 = mid + 1; r2 = n;
            l1 = mid - (r2 - l2 + 1); r1 = mid - 1;
        } else {
            int mid = m >> 1;
            l2 = mid + 1; r2 = n;
            l1 = mid - (r2 - l2); r1 = mid;
        }
        int h1 = get_hash_p(l1, r1, n);
        int h2 = get_hash_s(l2, r2, n);
        int p1 = get_hash_p(1, l1 - 1, n);
        int s1 = get_hash_s(1, l1 - 1, n);
        if(h1 != h2 || p1 != s1) continue;
        for(int i = l1 - 1; i >= 1; -- i) ans += s[i];
        return ans;
    }
    int idx = n;
    int w1 = get_hash_p(1, n - 1, n);
    int w2 = get_hash_s(1, n - 1, n);
    if(w1 == w2) idx = n - 1;
    // worst
    for(int i = idx; i >= 1; -- i) ans += s[i];
    return ans;
}

int main()
{
    po[0] = 1; for(int i = 1; i <= 100000; ++ i) po[i] = 1ll * po[i - 1] * base % mod;
    iv[100000] = mi(po[100000], mod - 2); for(int i = 100000; i >= 1; -- i) iv[i - 1] = 1ll * iv[i] * base % mod;
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        string ans = solve();
        prcas; printf("%s\n", ans.c_str());
    }
    return 0;
}