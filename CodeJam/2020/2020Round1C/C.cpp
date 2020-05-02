/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-05-02
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

const int maxn = 10005;
LL a[maxn];
int n, D, T;
int maxA[55];

mt19937 gen(time(0));

inline LL gcd(LL x, LL y)
{
    if(x == 0) return y;
    if(y == 0) return x;
    return gcd(y, x % y);
}

bool check(int id, LL d)
{
    if(id <= 0) return true;
    LL sum = 0;
    for(int i = 1; i <= n; ++ i) sum += a[i] * d / a[id];
    return sum >= D;
}

int find_maxA(int d)
{
    int l = 1, r = n;
    while(r - l > 1)
    {
        int mid = (l + r) >> 1;
        if(check(mid, d)) l = mid; else r = mid;
    }
    while(!check(r, d)) -- r;
    return r;
}

map< pll, pii > rec;

int solve()
{
    int ans = D; rec.clear(); maxA[0] = 0;
    for(int i = 1; i <= D; ++ i) maxA[i] = find_maxA(i);
    int d_id = 0;
    for(int base = 1; base <= n; ++ base)
    {
        while(d_id <= D && maxA[d_id] < base) ++ d_id;
        for(int d = d_id; d <= D; ++ d)
        {
            LL g = gcd(a[base], d);
            LL x = a[base] / g, y = d / g;
            pii re = rec[mp(x, y)];
            if(re.fi + d <= D) { re.fi += d; re.se ++; }
            rec[mp(x, y)] = re;
            ans = min(ans, D - re.se);
        }
    }
    return ans;
}

int brute_force()
{
    map<LL, int> cnt; cnt.clear();
    if(D == 2)
    {
        for(int i = n; i >= 1; -- i)
        {
            cnt[a[i]] ++;
            if(cnt[a[i]] >= 2) return 0;
        }
        return 1;
    }
    if(D == 3)
    {
        for(int i = n; i >= 1; -- i)
        {
            cnt[a[i]] ++;
            if(cnt[a[i]] >= 3) return 0;
        }
        for(int i = n; i >= 1; -- i)
            if(cnt[a[i] << 1] > 0) return 1;
        for(int i = n; i >= 1; -- i)
            if(a[i] < a[n] && cnt[a[i]] >= 2) return 1;
        return 2;
    }
    return 0;
}

void TEST()
{
    for(int cas = 1; cas <= T; ++ cas)
    {
        n = gen() % 10 + 1; D = gen() % 2 + 2;
        for(int i = 1; i <= n; ++ i) a[i] = gen() % 1000 + 1;
        sort(a + 1, a + n + 1);
        int a1 = solve(), a2 = brute_force();
        if(a1 != a2)
        {
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << n << " " << D << endl;
            for(int i = 1; i <= n; ++ i) printf("%lld ", a[i]);
            puts("");
            printf("solve:(%d) brute_force:(%d)\n", a1, a2);
        }
    }
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &D);
        for(int i = 1; i <= n; ++ i) scld(a[i]);
        sort(a + 1, a + n + 1);
        prcas; printf("%d\n", solve());
    }
    return 0;
}
