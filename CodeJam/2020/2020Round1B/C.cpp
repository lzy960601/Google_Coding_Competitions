/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-04-21
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

int S, R, T, n;

void pri(vi &u)
{
    for(int p : u) printf("%d ", p);
    puts("");
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &R, &S);
        prcas; int cnt = (R * (S - 1) + 1) >> 1;
        printf("%d\n", cnt);
        vi ori; ori.clear(); n = S * R;
        for(int i = 1; i <= S; ++ i)
            for(int j = 1; j <= R; ++ j) ori.pb(j);
        while(cnt --)
        {
            vi nxt; nxt.clear();
            vi A, B; A.clear(); B.clear();
            int k = 0, r = ori[0];
            while(ori[k] == r && k < n) A.pb(ori[k ++]);
            ++ r; if(r == R + 1) r = 1;
            while(ori[k] == r && k < n) A.pb(ori[k ++]);
            -- r; if(r == 0) r = R;
            while(ori[k] != r && k < n) B.pb(ori[k ++]);
            while(ori[k] == r && k < n) B.pb(ori[k ++]);
            if(k == n)
            {
                k = 0;
                while(ori[k] == R) ++ k;
                printf("%d %d\n", k, n - k);
                for(int i = k; i < n; ++ i) nxt.pb(ori[i]);
                for(int i = 0; i < k; ++ i) nxt.pb(ori[i]);
                ori = nxt;
            }else
            {
                for(int v : B) nxt.pb(v);
                for(int v : A) nxt.pb(v);
                for(int i = k; i < n; ++ i) nxt.pb(ori[i]);
                ori = nxt;
                printf("%d %d\n", (int)A.size(), (int)B.size());
            }
        }
        //pri(ori);
    }
    return 0;
}
