/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-10
File: A.cpp
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

const int maxn = 105;
char s[maxn][205];
int t[205];
int n;

void add(int A[], int w)
{
    for(int i = w; i >= 1; -- i)
    {
        if(i == w) A[i] += 1;
        A[i - 1] += A[i] / 10;
        A[i] %= 10;
    }
}

int solve()
{
    scd(n);
    for(int i = 1; i <= n; ++ i) scs(s[i] + 1);
    int ans = 0;
    for(int i = 2; i <= n; ++ i)
    {
        int l1 = strlen(s[i - 1] + 1);
        int l2 = strlen(s[i] + 1);
        if(l2 > l1) continue;
        int flag = 0;
        for(int k = 1; k <= l2; ++ k)
        {
            if(s[i - 1][k] > s[i][k]) { flag = -1; break; }
            if(s[i - 1][k] < s[i][k]) { flag = 1; break; }
        }
        if(flag < 0)
        {
            int tmp = l1 - l2 + 1;
            ans += tmp;
            for(int k = 1; k <= tmp; ++ k) s[i][l2 + k] = '0';
            s[i][l2 + tmp + 1] = 0;
        }
        if(flag == 0)
        {
            if(l1 == l2)
            {
                s[i][l2 + 1] = '0';
                s[i][l2 + 2] = 0;
                ans += 1;
                continue;
            }
            t[0] = 0;
            for(int k = l2 + 1; k <= l1; ++ k)
                t[k - l2] = s[i - 1][k] - '0';
            add(t, l1 - l2);
            int base = l2 + 1;
            if(t[0] > 0)
                for(int k = 0; k <= l1 - l2; ++ k)
                    s[i][base ++] = '0';
            else
                for(int k = 1; k <= l1 - l2; ++ k)
                    s[i][base ++] = t[k] + '0';
            s[i][base] = 0;
            ans += l1 - l2;
            if(t[0] > 0) ++ ans;
        }
        if(flag > 0)
        {
            if(l1 == l2) continue;
            for(int k = l2 + 1; k <= l1; ++ k)
                s[i][k] = s[i - 1][k];
            s[i][l1 + 1] = 0;
            ans += l1 - l2;
        }
    }
    return ans;
}

int main()
{	
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; printf("%d\n", ans);
    }
    return 0;
}
