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

const int maxn = 1050;
int T, n, m;
char c;

struct lisanhua
{
    int lsh[maxn], ls[maxn], lsc, cnt;
    void init() {cnt = 0; lsc = 0;}
    void add(int p) {lsh[++ cnt] = p;}
    int get(int pos) {return ls[pos];}
    void doit()
    {
        sort(lsh + 1, lsh + cnt + 1);
        ls[lsc = 1] = lsh[1];
        for(int i = 2; i <= cnt; ++ i) 
            if(lsh[i] != lsh[i - 1]) ls[++ lsc] = lsh[i];
    }
    int find(int val) {return lower_bound(ls + 1, ls + lsc + 1, val) - ls;}
}xx, yy;

struct person
{
    int x, y;
    char c;
    void read() {scanf("%d%d %c", &x, &y, &c);}
}a[maxn];

int sum[maxn][maxn];

int main()
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &m);
        xx.init(); yy.init();
        for(int i = 1; i <= n; ++ i) a[i].read();
        xx.add(0); yy.add(0); xx.add(m); yy.add(m);
        for(int i = 1; i <= n; ++ i) 
        {
            //xx.add(a[i].x); yy.add(a[i].y);
            if(a[i].c == 'N') yy.add(a[i].y + 1);
            if(a[i].c == 'S') yy.add(a[i].y - 1);
            if(a[i].c == 'E') xx.add(a[i].x + 1);
            if(a[i].c == 'W') xx.add(a[i].x - 1);
        }
        xx.doit(); yy.doit();
        for(int i = 0; i <= xx.lsc; ++ i)
            for(int j = 0; j <= yy.lsc; ++ j)
                sum[i][j] = 0;
        for(int i = 1; i <= n; ++ i)
        {
            int u = yy.find(a[i].y), d = yy.find(a[i].y), l = xx.find(a[i].x), r = xx.find(a[i].x);
            //sum[l][d] ++; sum[r + 1][d] --; sum[l][u + 1] --; sum[r + 1][u + 1] ++;
            if(a[i].c == 'N')
            {
                d = yy.find(a[i].y + 1);
                u = yy.lsc; l = 1; r = xx.lsc;
            }
            if(a[i].c == 'S')
            {
                u = yy.find(a[i].y - 1);
                d = 1; l = 1; r = xx.lsc;
            }
            if(a[i].c == 'E')
            {
                l = xx.find(a[i].x + 1);
                r = xx.lsc; d = 1; u = yy.lsc;
            }
            if(a[i].c == 'W')
            {
                r = xx.find(a[i].x - 1);
                l = 1; d = 1; u = yy.lsc;
            }
            //printf("%d %d %c %d %d %d %d\n", a[i].x, a[i].y, a[i].c, l, d, r, u);
            sum[l][d] ++; sum[r + 1][d] --; sum[l][u + 1] --; sum[r + 1][u + 1] ++;
        }
        for(int i = 1; i <= xx.lsc; ++ i)
            for(int j = 1; j <= yy.lsc; ++ j)
                sum[i][j] += sum[i - 1][j];
        for(int i = 1; i <= xx.lsc; ++ i)
            for(int j = 1; j <= yy.lsc; ++ j)
                sum[i][j] += sum[i][j - 1];
        int cnt = 0, ax = xx.lsc + 1, ay = yy.lsc + 1;
        for(int i = 1; i <= xx.lsc; ++ i)
            for(int j = 1; j <= yy.lsc; ++ j)
                if(sum[i][j] > cnt) {cnt = sum[i][j]; ax = i; ay = j;}
        prr(cas); printf("%d %d\n", xx.get(ax), yy.get(ay));
    }
    return 0;
}
