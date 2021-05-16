/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-04-10
File: C.cpp
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

__int128 cc[125][125];

int N, Q, pos[125];
struct answer
{
    char s[125];
    int sc;
    void read(){ scanf("%s%d", s + 1, &sc); }
    void reverse(int Q)
    {
        sc = Q - sc;
        for(int i = 1; i <= Q; ++ i)
            if(s[i] == 'T') s[i] = 'F'; else s[i] = 'T';
    }
}a[4];

void read()
{
    scanf("%d%d", &N, &Q);
    for(int i = 0; i < N; ++ i)
    {
        a[i].read();
        if((a[i].sc << 1) < Q) a[i].reverse(Q);
    }
}

bool cmp(answer x, answer y) { return x.sc > y.sc; }

__int128 gcd(__int128 x, __int128 y)
{
    if(x == 0) return y;
    if(y == 0) return x;
    return gcd(y, x % y);
}

char rev(char ch) { return ch == 'F' ? 'T' : 'F'; }

int rp[4] = {0, 0, 0, 1};

void print(__int128 x)
{
    char t[45];
    int cnt = 0;
    while(x > 0)
    {
        t[++ cnt] = x % 10;
        x /= 10;
    }
    for(int i = cnt; i >= 1; -- i) putchar(t[i] + '0');
}

void solve(int cas)
{
    sort(a, a + N, cmp);
    if(N <= 2) { prcas; printf("%s %d/%d\n", a[0].s + 1, a[0].sc, 1); return; }
    int se[4] = {0}, c[4] = {0}; // 012, 01, 02, 12
    __int128 ex[16] = {0}, allcase = 0;
    for(int i = 1; i <= Q; ++ i)
    {
        if(a[0].s[i] == a[1].s[i] && a[0].s[i] != a[2].s[i]) { ++ se[1]; pos[i] = 1; continue; } 
        if(a[2].s[i] == a[0].s[i] && a[2].s[i] != a[1].s[i]) { ++ se[2]; pos[i] = 2; continue; }
        if(a[1].s[i] == a[2].s[i] && a[1].s[i] != a[0].s[i]) { ++ se[3]; pos[i] = 3; continue; }
        if(a[0].s[i] == a[1].s[i] && a[1].s[i] == a[2].s[i]) { ++ se[0]; pos[i] = 0; continue; }
        assert(false);
    }
    for(c[0] = 0; c[0] <= se[0]; ++ c[0])
    {
        int s0 = a[0].sc - c[0];
        int s1 = a[1].sc - c[0];
        int s2 = a[2].sc - c[0];
        if(min(s0, min(s1, s2)) < 0) break;
        int s = (s0 + s1 + s2) - (se[1] + se[2] + se[3]); // c[1] + c[2] + c[3]
        if(s < 0) continue;
        if(s + se[3] < s0 || ((s + se[3] - s0) & 1)) continue; else c[3] = (s + se[3] - s0) >> 1;
        if(s + se[2] < s1 || ((s + se[2] - s1) & 1)) continue; else c[2] = (s + se[2] - s1) >> 1;
        if(s + se[1] < s2 || ((s + se[1] - s2) & 1)) continue; else c[1] = (s + se[1] - s2) >> 1;
        if(c[1] > se[1] || c[2] > se[2] || c[3] > se[3]) continue;
        
        // assert
        for(int k = 0; k < 4; ++ k) assert(c[k] >= 0 && c[k] <= se[k]);
        assert(c[0] + c[1] + c[2] + se[3] - c[3] == a[0].sc);
        assert(c[0] + c[1] + c[3] + se[2] - c[2] == a[1].sc);
        assert(c[0] + c[2] + c[3] + se[1] - c[1] == a[2].sc);

        __int128 cases = 1; for(int k = 0; k < 4; ++ k) cases *= cc[se[k]][c[k]];
        for(int state = 0; state < 16; ++ state)
        {
            int score = 0;
            for(int k = 0; k < 4; ++ k)
                if((state >> k) & 1) score += c[k]; else score += se[k] - c[k];
            ex[state] += cases * score;
        }
        
        allcase += cases;
    }
    int st = -1;
    for(int i = 0; i < 16; ++ i)
        if(st < 0 || ex[i] > ex[st]) st = i;

    // print
    prcas; __int128 g = gcd(ex[st], allcase);
    for(int i = 1; i <= Q; ++ i)
    {
        int p = pos[i], f = (st >> p) & 1;
        if(f) putchar(a[rp[p]].s[i]); else putchar(rev(a[rp[p]].s[i]));
    }
    putchar(' '); print(ex[st] / g); putchar('/'); print(allcase / g); puts("");
}

//FFFTFTTTFFFFTFTFFTFTTTTTTTFFFFTTTFTTTTFFTFTTTTTFFFTFTFTFFFFTFFTTFTFTFTTTTTFFTFFFFFFFFTTFTTTTTTFTTTTFFFFTFTFTTFTFFFFTTTFT 189154508532118369075350624633  / 2901503505434414233388602018
//FFFTFTTTFFFFTFTFFTFTTTTTTTFFFFTTTFTTTTFFTFTTTTTFFFTFTFTFFFFTFFTTFTFTFTTTTTFFTFFFFFFFFTTFTTTTTTFTTTTFFFFTFTFTTFTFFFFTTTFT 2510647623230865750734078356875 / 107355629701073326635378274666

int main()
{	
    cc[0][0] = 1;
    for(int i = 1; i <= 120; ++ i)
    {
        cc[i][0] = cc[i][i] = 1;
        for(int j = 1; j < i; ++ j)
            cc[i][j] = cc[i - 1][j] + cc[i - 1][j - 1]; 
    }
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        read();
        solve(cas);
    }
    return 0;
}
