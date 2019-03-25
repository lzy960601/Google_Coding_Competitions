/*****************************************
Author: lizi
Email: lzy960601@outlook.com
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

const int maxn=100005;
int a[maxn], sum[maxn];
int n, T, k;

int main()
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = 1e9 + 7;
        scanf("%d%d", &n, &k); 
        for(int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        sum[0] = 0;
        for(int i = 1; i <= n; ++ i) sum[i] = a[i] + sum[i - 1];
        for(int i = k; i <= n; ++ i)
        {
            int val = a[i] * k - sum[i] + sum[i - k];
            ans = min(ans, val);
        }
        prr(cas); printf("%d\n", ans);
    }
    return 0;
}
