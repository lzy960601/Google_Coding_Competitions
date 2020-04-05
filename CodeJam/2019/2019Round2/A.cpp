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
 
const int maxn = 305;
pii a[maxn];
map<pii, int> m;
int n, T, cnt;

int gcd(int x, int y)
{
    if(y == 0) return x;
    if(x == 0) return y;
    return gcd(y, x % y);
}

int abs(int x) {return x < 0 ? -x : x;}

int main()
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d", &n); cnt = 0; m.clear();
        for(int i = 1; i <= n; ++ i)
        {
            int x, y; scanf("%d%d", &x, &y);
            a[i] = mp(x, y);
        }
        for(int i = 1; i <= n; ++ i)
            for(int j = i + 1; j <= n; ++ j)
            {
                if(a[i].fi >= a[j].fi && a[i].se >= a[j].se) continue;
                if(a[i].fi <= a[j].fi && a[i].se <= a[j].se) continue;
                int fir = abs(a[i].fi - a[j].fi);
                int sec = abs(a[i].se - a[j].se);
                if(sec == 0) fir = 1;
                if(fir == 0) sec = 1;
                int g = gcd(fir, sec); fir /= g; sec /= g;
                pii tmp = mp(fir, sec);
                if(m[tmp] == 0) m[tmp] = ++ cnt;
            }
        prr(cas); printf("%d\n", cnt + 1);
    }
    return 0;
}
