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

char s[105], t[105];
int T, l;

int main()
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%s", s + 1);
        l = strlen(s + 1);
        for(int i = 1; i <= l; ++ i)
            if(s[i] == '4') {s[i] = '3'; t[i] = '1';} else t[i] = '0';
        int n = 1;
        pr2(cas); 
        while(s[n] == '0') ++ n; for(int i = n; i <= l; ++ i) putchar(s[i]);
        putchar(' ');
        n = 1; while(t[n] == '0') ++ n; for(int i = n; i <= l; ++ i) putchar(t[i]);
        puts("");
    }
    return 0;
}
