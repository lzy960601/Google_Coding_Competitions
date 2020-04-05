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

char s[50005];
int T, n;

int main()
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d", &n);
        scanf("%s", s + 1);
        pr2(cas);
        for(int i = 1; i <= 2 * n - 2; ++ i)
            putchar(s[i] == 'E' ? 'S' : 'E');
        puts("");
    }
    return 0;
}
