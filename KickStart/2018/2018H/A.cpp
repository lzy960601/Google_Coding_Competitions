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

int T, n, m, o;
struct Trie
{
    int dep, leaf, son[2];
    void clear(){dep = son[0] = son[1] = leaf = 0;}
}tr[5005];
char s[55];

LL cal(int rt)
{
    if(tr[rt].leaf == 1) return 1ll << (n - tr[rt].dep);
    LL sum = 0;
    for(int i = 0; i < 2; ++ i)
        if(tr[rt].son[i] > 0) sum += cal(tr[rt].son[i]);
    return sum;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &m); tr[o = 0].clear();
        LL ans = 1ll << n;
        while(m --)
        {
            scs(s + 1); int len = strlen(s + 1), now = 0;
            for(int i = 1; i <= len; ++ i)
            {
                int v = (s[i] == 'B' ? 1 : 0);
                if(tr[now].son[v] == 0)
                {
                    tr[now].son[v] = ++ o;
                    tr[o].clear();
                    tr[o].dep = tr[now].dep + 1;
                }
                now = tr[now].son[v];
            }
            tr[now].leaf = 1;
        }
        prcas; printf("%lld\n", ans - cal(0));
    }
    return 0;
}
