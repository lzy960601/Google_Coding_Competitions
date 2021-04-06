/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-03-09
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

mt19937 gen(20200309);

set<LL> s[55];
char a[55], b[55];
int T, n, val[26];

int main()
{	
    for(int i = 0; i < 26; ++ i) val[i] = gen() % (int)(1e9 + 7);
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scd(n);
        for(int i = 1; i <= n; ++ i) s[i].clear();
        scs(a + 1); scs(b + 1);
        for(int len = 1; len <= n; ++ len)
            for(int i = 1; i + len - 1 <= n; ++ i)
            {
                LL tmp = 0;
                for(int j = i; j <= i + len - 1; ++ j)
                    tmp += val[b[j] - 65];
                s[len].insert(tmp);
            }
        int ans = 0;
        for(int len = 1; len <= n; ++ len)
            for(int i = 1; i + len - 1 <= n; ++ i)
            {
                LL tmp = 0;
                for(int j = i; j <= i + len - 1; ++ j)
                    tmp += val[a[j] - 65];
                if(s[len].find(tmp) != s[len].end()) ans ++;
            }
        prcas; printf("%d\n", ans);
    }
    return 0;
}
