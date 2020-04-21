/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-04-20
File: A.cpp
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

#define IN freopen("A.in", "r", stdin)
#define OUT freopen("A.out", "w", stdout)
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

int T, nA, nB, k;
LL A, B;
int usea[32], useb[32], f[32];

bool solve()
{
    for(int i = 0; i <= 31; ++ i) usea[i] = useb[i] = f[i] = 0;
    if((A + B) % 2 == 0) return false;
    k = 0; while( (1ll << (k + 1)) - 1 < A + B ) ++ k;
    LL sum = A + B;
    for(int i = k; i >= 0; -- i)
    {
        LL t = 1ll << i;
        if(sum == 0) return false;
        if(sum > 0) { f[i] = 1; sum -= t; } else { f[i] = -1; sum += t; }
    }
    if(sum != 0) return false;
    for(int i = 0; i <= k; ++ i)
    {
        if((A + B) % 2 == 0) return false;
        if(A & 1) { usea[i] = f[i]; A -= f[i]; }
        if(B & 1) { useb[i] = f[i]; B -= f[i]; }
        A >>= 1; B >>= 1;
    }
    return A + B == 0;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%lld%lld", &A, &B);
        if(A < 0) { nA = -1; A = -A; } else nA = 1;
        if(B < 0) { nB = -1; B = -B; } else nB = 1;
        prcas; 
        if(!solve()) { puts("IMPOSSIBLE"); continue; }
        for(int i = 0; i <= k; ++ i)
        {
            usea[i] *= nA; useb[i] *= nB;
            if(usea[i] != 0) putchar(usea[i] > 0 ? 'E' : 'W');
            if(useb[i] != 0) putchar(useb[i] > 0 ? 'N' : 'S');
        }
        puts("");
    }
    return 0;
}
