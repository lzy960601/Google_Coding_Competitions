/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-03
File: C.cpp
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
const int base = 31;
const LL cut = 100;
LL L, N, K, mul[cut + 5];
int T;

struct STR
{
    int v[cut + 5];
    void clear() { for(int i = 0; i <= 100; ++ i) v[i] = 0; }
    void add(int pos, int val)
    {
        v[pos] = val;
    }
    bool checkodd(int pos, int len)
    {
        int mid = (len + 1) >> 1;
        int l = mid, r = mid;
        while(l > 0 && r <= pos)
        {
            if(v[l] != v[r]) return false;
            -- l; ++ r;
        }
        return true;
    }
    bool checkeven(int pos, int len)
    {
        int mid = (len + 1) >> 1;
        int l = mid, r = mid + 1;
        while(l > 0 && r <= pos)
        {
            if(v[l] != v[r]) return false;
            -- l; ++ r;
        }
        return true;
    }
    bool check(int pos, int len)
    {
        if(len & 1) return checkodd(pos, len);
        else return checkeven(pos, len);
    }
}s;

LL solve1(LL k)
{
    s.clear();
    for(int pos = 1; pos <= N; ++ pos)
    {
        bool flag = true;
        for(int c = 1; c <= L; ++ c)
        {
            s.add(pos, c); LL sum = 0;
            if(s.check(pos, pos))
            {
                -- k;
                if(k == 0) return pos;
            }
            for(int len = pos + 1; len <= N; ++ len)
            {
                int d = (len + 1) >> 1;
                if(d <= pos)
                {
                    if(s.check(pos, len)) ++ sum;
                }
                else 
                {
                    sum += mul[d - pos];
                }
                if(sum >= k) break;
            }
            if(sum >= k) { flag = false; break; } else k -= sum;
        }
        if(flag) return 0;
    }
    return 0;
}

LL solve2(LL k)
{
    LL val = cut - (N & 1);
    LL add = N - val;
    N = val;
    return solve1(k - add) + add;
}

LL solve()
{
    scanf("%lld%lld%lld", &L, &N, &K);
    if(K <= N) return K;
    if(L == 1) return 0;
    mul[0] = 1; for(int i = 1; i <= (cut + 1) >> 1; ++ i) mul[i] = mul[i - 1] * L;
    if(N <= cut) return solve1(K); else return solve2(K);
    return 0;
}

int main()
{
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        LL ans = solve();
        prcas; printf("%lld\n", ans);
    }
    return 0;
}
