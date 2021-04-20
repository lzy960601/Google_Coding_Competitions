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

typedef unsigned long long ULL;
typedef unsigned int UInt;
const UInt base1[] = { 2, 7, 61, 0 };
const UInt base2[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022, 0 };
const UInt prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53 };
inline ULL add(ULL a, ULL b, ULL mod){
	return a + b - (a + b >= mod ? mod : 0);
}
ULL mul(ULL a, ULL b, ULL mod){
	ULL ret = 0;
	for (ULL t = a; b; b >>= 1){
		if (b & 1)ret = add(ret, t, mod);
		t <<= 1;
		if (t >= mod)t -= mod;
	}
	return ret;
}
ULL power(ULL a, ULL b, ULL mod){
	ULL ret = 1;
	for (ULL t = a; b; b >>= 1){
		if (b & 1)ret = mul(ret, t, mod);
		t = mul(t, t, mod);
	}
	return ret;
}
//n为小于2^63的非1奇数，正确性100%
bool millerRabin(ULL n)
{
	int s = 0;
	ULL r = n;
	for (r--; !(r & 1); r >>= 1)s++;
	for (const UInt *base = base2; *base; base++){
		ULL t = power(*base % n, r, n);
		if (t == 0 || t == 1 || t == n - 1)continue;
		for (int j = 1; j < s; j++){
			t = mul(t, t, n);
			if (t == 1)return false;
			if (t == n - 1)break;
		}
		if (t != n - 1)return false;
	}
	return true;
}
bool checkPrime(ULL n)
{
	if (n == 1)return false;
	for (int i = 0; i < sizeof(prime) / sizeof(int); i++){
		if (n % prime[i] == 0)return n == prime[i];
	}
	return millerRabin(n);
}

LL solve()
{
    LL n; scld(n);
    if(n < 10) return 6;
    if(n < 14) return 10;
    if(n < 21) return 15;
    LL t = sqrt(n);
    if(t * t > n) -- t;
    LL t1 = t, t2 = t;
    while(!checkPrime(t2)) -- t2;
    t1 = t2 - 1;
    while(!checkPrime(t1)) -- t1;
    ++ t;
    while(!checkPrime(t)) ++ t;
    if(t2 * t <= n) return t2 * t;
    return t1 * t2;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        LL ans = solve();
        prcas; printf("%lld\n", ans);
    }
    return 0;
}