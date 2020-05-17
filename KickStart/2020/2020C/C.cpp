/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-04-19
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

const int mod = 1e9;
pii dir[4] = { mp(1, 0), mp(0, 1), mp(mod - 1, 0), mp(0, mod - 1) };
int getdir(char c)
{
    if(c == 'E') return 0;
    if(c == 'S') return 1;
    if(c == 'W') return 2;
    if(c == 'N') return 3;
    assert(0);
    return -1;
}

char s[20005];
int T, n, cnt;

struct node
{
    int xs, sx, sy;
}a[20005];

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scs(s + 1); n = strlen(s + 1);
        a[0] = {0, 0, 0};
        s[++ n] = ')'; a[cnt = 1] = {1, 0, 0};
        for(int i = 1; i <= n; ++ i)
        {
            char c = s[i];
            if(c == ')')
            {
                (a[cnt - 1].sx += 1ll * a[cnt].xs * a[cnt].sx % mod) %= mod;
                (a[cnt - 1].sy += 1ll * a[cnt].xs * a[cnt].sy % mod) %= mod;
                -- cnt; continue;
            }
            if(c >= '1' && c <= '9')
            {
                a[++ cnt] = {c - 48, 0, 0};
                ++ i; continue;
            }
            int d = getdir(c);
            (a[cnt].sx += dir[d].fi) %= mod;
            (a[cnt].sy += dir[d].se) %= mod;
        }
        prcas; printf("%d %d\n", a[0].sx + 1, a[0].sy + 1);
    }
    return 0;
}
