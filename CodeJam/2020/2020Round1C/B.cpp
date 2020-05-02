/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-05-02
File: B.cpp
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

#define IN freopen("B.in", "r", stdin)
#define OUT freopen("B.out", "w", stdout)
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

char s[10005][20];
int len[10005], cnt[10], c;
const int n = 10000;

char ans[10], sto[10];
int m[26];
vector< pii > tmp;

void solve()
{
    for(int i = 0; i < 26; ++ i) m[i] = -1;
    c = 0; tmp.clear();
    for(int i = 0; i < 10; ++ i) cnt[i] = 0;
    for(int i = 1; i <= n; ++ i)
    {
        int x; scd(x);
        scs(s[i] + 1); len[i] = strlen(s[i] + 1);
        for(int k = 1; k <= len[i]; ++ k)
        {
            char cc = s[i][k];
            if(m[cc - 'A'] < 0)
            {
                m[cc - 'A'] = c; sto[c] = cc;
                ++ c;
            }
        }
        cnt[m[s[i][1] - 'A']] ++;
    }
    for(int i = 0; i < 10; ++ i)
    {
        if(cnt[i] == 0) ans[0] = sto[i];
        cnt[i] = 0;
    }
    for(int i = 1; i <= n; ++ i)
        for(int k = 1; k <= 1; ++ k)
            cnt[ m[s[i][k] - 'A'] ] ++;
    for(int i = 0; i < 10; ++ i) tmp.pb(mp(cnt[i], i));
    sort(tmp.begin(), tmp.end());
    c = 9;
    for(pii p : tmp)
    {
        if(sto[p.se] == ans[0]) continue;
        ans[c --] = sto[p.se];
    }
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int u; scd(u);
        prcas; solve();
        for(int i = 0; i < 10; ++ i) putchar(ans[i]);
        puts("");
    }
    return 0;
}
