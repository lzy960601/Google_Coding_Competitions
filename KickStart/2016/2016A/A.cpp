/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-19
File: A.cpp
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

int cnt[26], n;
char a[30];

void solve(int cas)
{
    string ans = "";
    int ma = 0;
    cin >> n;
    while(n --)
    {
        for(int i = 0; i < 26; ++ i) cnt[i] = 0;
        string s = "";
        cin.getline(a, 30);
        while(strlen(a) <= 0) cin.getline(a, 30);
        int l = strlen(a);
        for(int i = 0; i < l; ++ i) s += a[i];
        int num = 0;
        for(char c : s)
        {
            if(c < 'A' || c > 'Z') continue;
            int k = c - 'A';
            if(cnt[k] == 0) ++ num;
            ++ cnt[k];
        }
        if(num > ma || (num == ma && s < ans)) { ma = num; ans = s; }
    }
    prcas; cout << ans << endl;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
        solve(cas);
    return 0;
}