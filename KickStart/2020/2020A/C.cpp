/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-03-22
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

const int maxn = 100005;
int T, a[maxn], n, K;

bool check(int c, int p)
{
    int ans = 0;
    for(int i = 2; i <= n; ++ i)
    {
        int cha = a[i] - a[i - 1];
        ans += (cha + c - 1) / c - 1;
        if(ans > p) return false;
    }
    return true;
}

int main()
{
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &K);
        for(int i = 1; i <= n; ++ i) scd(a[i]);
        int l = 1, r = 1e9;
        while(r - l > 1)
        {
            int mid = (l + r) >> 1;
            if(check(mid, K)) r = mid; else l = mid;
        }
        while(!check(l, K)) ++ l;
        prcas; printf("%d\n", l);
    }
    return 0;
}
