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

const int maxn = 200005;

char s[maxn];
int n, T, m, cnt[maxn][26];

int main()
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &m);
        scanf("%s", s + 1);
        for(int i = 1; i <= n; ++ i)
        {
            for(int k = 0; k < 26; ++ k) cnt[i][k] = cnt[i - 1][k];
            cnt[i][s[i] - 65] ++;
        }
        int ans = 0;
        while(m --)
        {
            int l, r, sum = 0; scanf("%d%d", &l, &r);
            for(int i = 0; i < 26; ++ i) if((cnt[r][i] - cnt[l - 1][i]) & 1) sum ++;
            ans += (sum <= 1);
        }
        prr(cas); printf("%d\n", ans);
    }
    return 0;
}
