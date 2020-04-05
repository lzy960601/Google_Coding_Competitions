/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-03-22
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

int T, n, m, nc, ans;
struct node
{
    int cnt;
    int nxt[26];
    void clear(){cnt = 0; for(int i = 0; i < 26; ++ i) nxt[i] = -1;}
}tr[2000005];
char s[2000005];

int DFS(int u, int d)
{
    if(tr[u].cnt < m) return 0;
    int sum = 0;
    for(int i = 0; i < 26; ++ i)
    {
        int k = tr[u].nxt[i];
        if(k < 0) continue;
        sum += DFS(k, d + 1);
    }
    tr[u].cnt -= sum;
    sum += (tr[u].cnt / m) * m;
    ans += (tr[u].cnt / m) * d;
    return sum;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &m); nc = ans = 0; tr[0].clear();
        for(int p = 1; p <= n; ++ p)
        {
            scs(s + 1);
            int len = strlen(s + 1), cur = 0;
            for(int i = 1; i <= len; ++ i)
            {
                int v = s[i] - 65;
                tr[cur].cnt ++;
                if(tr[cur].nxt[v] < 0)
                {
                    tr[++ nc].clear();
                    tr[cur].nxt[v] = nc;
                }
                cur = tr[cur].nxt[v];
            }
            tr[cur].cnt ++;
        }
        DFS(0, 0);
        prcas; printf("%d\n", ans);
    }
    return 0;
}
