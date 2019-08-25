/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-08-25
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

#define IN freopen("sample.in", "r", stdin)
#define OUT freopen("sample.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-x))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;
#define ll long long

bool v1[1000005], v2[1000005];
ll Prime(ll a,ll b){
    b ++;
    if(a > b) return 0ll;
    for(ll i=0;i*i<b;i++)v1[i]=true;
    for(ll i=0;i<b-a;i++)v2[i]=true;
 
    for(ll i=2;i*i<b;i++){
        if(v1[i]){
            for(ll j=2*i;j*j<b;j+=i)v1[j]=false; //筛[2,b)
            for(ll j=max(2LL,(a+i-1)/i)*i;j<b;j+=i)v2[j-a]=false; //筛[a,b)
            //2LL是2的长整数形式
            //((a+i-1)/i)*i是符合>=a最小是i倍数的数
        }
    }
    ll k=0;
    for(ll i=0;i<b-a;i++){
        if(v2[i])k++;
    }
    if(a <= 2 && b > 2) k --;
    if(a <= 1 && b > 1) k --;
    //printf("%lld - %lld : %lld\n", a, b, k);
    return k;
}

LL l, r;
int T;

LL getans(LL x, LL y)
{
    LL a1 = Prime(x, y);
    LL a2 = Prime((x + 3) >> 2, y >> 2);
    LL a3 = ((y + 2) >> 2) - ((x + 1) >> 2);
    LL ans = a1 + a2 + a3;
    //printf("%lld %lld %lld\n", a1, a2, a3);
    if(x <= 1 && y >= 1) ans ++;
    if(x <= 4 && y >= 4) ans ++;
    if(x <= 8 && y >= 8) ans ++;
    return ans;
}

int main()
{   
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%lld%lld", &l, &r);
        prcas; printf("%lld\n", getans(l, r));
    }
    return 0;
}
