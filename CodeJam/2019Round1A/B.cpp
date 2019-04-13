/*****************************
Author : lizi
Email  : zyli@smail.nju.edu.cn
*****************************/

#include<bits/stdc++.h>
using namespace std;

const double eps=1e-8;
const double pi=3.1415926535897932384626;
const double eln=2.718284590452353602874;
#define IN freopen("tmp.in", "r", stdin);
#define OU freopen("tmp.ou", "w", stdout);
#define mp make_pair
#define pb push_back
#define pr1(x) printf("Case %d: ", x);
#define pn1(x) printf("Case %d:\n",x);
#define pr2(x) printf("Case #%d: ", x);
#define pn2(x) printf("Case #%d:\n",x);
#define sqr(x) (x)*(x)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

int exgcd(int a,int b,int &x,int &y)
{
	int d;
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

int inv(LL p, LL q)
{
    int x, y;
    exgcd(q, p, x, y);
    return y;
}

//n个方程：x=a[i](mod m[i]) (0<=i<n)
LL china(int n, LL *a, LL *m)
{
    LL M = 1, ret = 0;
    for(int i = 0; i < n; i ++) M *= m[i];
    for(int i = 0; i < n; i ++)
    {
        LL w = M / m[i];
        ret = (ret + w * inv(w, m[i]) * a[i]) % M;
    }
    return (ret + M) % M;
}

int T, lun, maxm, zs[] = {4, 3, 5, 7, 11, 13, 17};
LL a[10], m[10];

int inter(int p)
{
    for(int i = 0; i < 18; ++ i) printf("%d%c", p, (i == 17 ? '\n' : ' '));
    fflush(stdout);
    int x, sum = 0;
    for(int i = 0; i < 18; ++ i) 
    {
        scanf("%d", &x);
        sum = (sum + x) % p;
    }
    return sum;
}

void judge(LL ans)
{
    printf("%lld\n", ans); fflush(stdout);
    int p; scanf("%d", &p);
    if(p < 0) exit(1); else return;
}

int main()
{
    scanf("%d%d%d", &T, &lun, &maxm);
    for(int cas = 1; cas <= T; ++ cas)
    {
        //scanf("%d%d", &lun, &maxm);
        for(int i = 0; i < 7; ++ i)
        {
            m[i] = zs[i];
            a[i] = inter(zs[i]);
        }
        judge(china(7, a, m));
    }
    return 0;
}
