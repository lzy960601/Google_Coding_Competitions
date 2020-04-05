/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-04-04
File: D.cpp
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

#define IN freopen("D.in", "r", stdin)
#define OUT freopen("D.out", "w", stdout)
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

int T, B;
queue< pii > pos;
pii mark[3];
int same[105], type[105], ans[105];

int query(int p)
{
    printf("%d\n", p);
    fflush(stdout);
    int x; scd(x);
    return x;
}

int gen_ans()
{
    if(mark[1].fi > 0) mark[1].se = query(mark[1].fi);
    if(mark[2].fi > 0) mark[2].se = query(mark[2].fi);
    for(int i = 1; i <= (B + 1) >> 1; ++ i)
    {
        int ano = B + 1 - i;
        if(type[i] == 1)
        {
            if(same[i] > 0) ans[i] = ans[ano] = mark[1].se;
            if(same[i] < 0) ans[i] = ans[ano] = mark[1].se ^ 1;
        }else
        {
            if(same[i] > 0) { ans[i] = mark[2].se; ans[ano] = mark[2].se ^ 1; }
            if(same[i] < 0) { ans[i] = mark[2].se ^ 1; ans[ano] = mark[2].se; }
        }
    }
    for(int i = 1; i <= B; ++ i) putchar(48 + ans[i]);
    puts(""); fflush(stdout);
    char c = getchar(); while(c != 'Y' && c != 'N') c = getchar();
    if(c == 'Y') return 1; else return -1;
}

int main()
{
    scanf("%d%d", &T, &B);
    while(T --)
    {
        while(!pos.empty()) pos.pop();
        mark[1] = mark[2] = mp(0, 0);
        for(int i = 1; i <= B; ++ i) same[i] = type[i] = 0;
        for(int i = 1; i <= (B + 1) >> 1; ++ i) pos.push(mp(i, B + 1 - i));
        while(!pos.empty())
        {
            if(mark[1].fi == 0) query(1); else mark[1].se = query(mark[1].fi);
            if(mark[2].fi == 0) query(1); else mark[2].se = query(mark[2].fi);
            for(int pair_num = 1; pair_num <= 4; ++ pair_num)
            {
                if(pos.empty()) {query(1); query(1); continue;}
                pii now = pos.front(); pos.pop();
                int x = now.fi, y = now.se;
                int ax = query(x), ay = query(y);
                if(ax == ay)
                {
                    type[x] = type[y] = 1;
                    if(mark[1].fi == 0) { mark[1].fi = x; mark[1].se = ax; }
                    if(ax == mark[1].se) same[x] = same[y] = 1; else same[x] = same[y] = -1;
                }else
                {
                    type[x] = type[y] = 2;
                    if(mark[2].fi == 0) { mark[2].fi = x; mark[2].se = ax; }
                    if(ax == mark[2].se) same[x] = same[y] = 1; else same[x] = same[y] = -1;
                }
            }
        }
        if(gen_ans() < 0) return -1;
    }
    return 0;
}
