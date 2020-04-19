/*****************************************
Author: lizi
Email: zyli@smail.nju.edu.cn
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 105;
struct stone
{
    int s, e, l;
    void read(){scanf("%d%d%d", &s, &e, &l);}
    bool operator < (const struct stone &p) const {return p.l * s < l * p.s;}
}s[maxn];
int n, T, m, dp[10005];

int main()
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d", &n); m = 0;
        for(int i = 1; i <= n; ++ i) s[i].read(), m += s[i].s;
        sort(s + 1, s + n + 1);
        for(int i = 0; i <= m; ++ i) dp[i] = 0;
        for(int i = 1; i <= n; ++ i)
            for(int k = m; k >= s[i].s; -- k)
                dp[k] = max(dp[k], dp[k - s[i].s] + max(0, s[i].e - s[i].l * (k - s[i].s)));
        int ans = 0;
        for(int i = 0; i <= m; ++ i) ans = max(ans, dp[i]);
        prr(cas); printf("%d\n", ans);
    }
    return 0;
}
