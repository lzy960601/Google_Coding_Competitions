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
#define pr1(x) printf("Case %d: ",x)
#define pn1(x) printf("Case %d:\n",x)
#define pr2(x) printf("Case #%d: ",x)
#define pn2(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 200005;
int st_c[20][maxn], st_d[20][maxn], T, n, k, lo[maxn], c[maxn], d[maxn];

int getmax(int a[], int x, int y) {return a[x] > a[y] ? x : y;}

int get(int a[], int st[][maxn], int x, int y)
{
    int t = lo[y - x + 1];
    return getmax(a, st[t][x], st[t][y - (1 << t) + 1]);
}

int findleft(int a[], int st[][maxn], int pos)
{
    int l = 1, r = pos;
    while(r - l > 1)
    {
        int mid = (l + r) >> 1;
        if(get(a, st, mid, pos) != pos) l = mid; else r = mid;
    }
    while(get(a, st, l, pos) != pos) ++ l;
    return l;
}

int findright(int a[], int st[][maxn], int pos)
{
    int l = pos, r = n;
    while(r - l > 1)
    {
        int mid = (l + r) >> 1;
        if(get(a, st, pos, mid) != pos) r = mid; else l = mid;
    }
    while(get(a, st, pos, r) != pos) -- r;
    return r;
}

int valleft(int a[], int st[][maxn], int le, int pos, int val)
{
    if(a[pos] > val) return pos + 1;
    int l = le, r = pos;
    while(r - l > 1)
    {
        int mid = (l + r) >> 1;
        if(a[get(a, st, mid, pos)] <= val) r = mid; else l = mid;
    }
    while(a[get(a, st, l, pos)] > val) ++ l;
    return l;
}

int valright(int a[], int st[][maxn], int ri, int pos, int val)
{
    if(a[pos] > val) return pos - 1;
    int l = pos, r = ri;
    while(r - l > 1)
    {
        int mid = (l + r) >> 1;
        if(a[get(a, st, pos, mid)] <= val) l = mid; else r = mid;
    }
    while(a[get(a, st, pos, r)] > val) -- r;
    return r;
}

int main()
{
    //IN;
    lo[1] = 0; for(int i = 2; i <= maxn - 5; ++ i) lo[i] = lo[i >> 1] + 1;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &k);
        LL ans = 0;
        for(int i = 1; i <= n; ++ i) scanf("%d", &c[i]), st_c[0][i] = i;
        for(int i = 1; i <= n; ++ i) scanf("%d", &d[i]), st_d[0][i] = i;
        for(int p = 1; (1 << p) <= n; ++ p)
            for(int i = 1; i + (1 << p) - 1 <= n; ++ i)
            {
                st_c[p][i] = getmax(c, st_c[p - 1][i], st_c[p - 1][i + (1 << (p - 1))]);
                st_d[p][i] = getmax(d, st_d[p - 1][i], st_d[p - 1][i + (1 << (p - 1))]);
            }
        for(int i = 1; i <= n; ++ i)
        {
            int l = findleft(c, st_c, i);
            int r = findright(c, st_c, i);
            int l1 = valleft(d, st_d, l, i, c[i] + k);
            int r1 = valright(d, st_d, r, i, c[i] + k);
            int l2 = valleft(d, st_d, l, i, c[i] - k - 1);
            int r2 = valright(d, st_d, r, i, c[i] - k - 1);
            //printf("i : %d l : %d r : %d\nl1 : %d r1 : %d l2 : %d r2 : %d\n", i, l, r, l1, r1, l2, r2);
            l1 = i - l1 + 1; r1 = r1 - i + 1;
            l2 = i - l2 + 1; r2 = r2 - i + 1;
            ans += 1ll * l1 * r1 - 1ll * l2 * r2;
        }
        pr2(cas); printf("%lld\n", ans);
    }
    return 0;
}
