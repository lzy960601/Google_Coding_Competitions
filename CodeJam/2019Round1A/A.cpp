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

int T, n, m;
bool flag;
vector<pii> ans, a2x, a3x;
vector<pii> a34 = {mp(1,2), mp(2, 4), mp(3, 2), mp(1, 3), mp(2, 1), mp(3, 3), mp(1, 4), mp(3, 1), mp(2, 3), mp(1, 1), mp(3, 4), mp(2, 2)};
vector<pii> a44 = {mp(1,2), mp(2, 4), mp(3, 2), mp(1, 3), mp(4, 4), mp(2, 1), mp(3, 3), mp(1, 4), mp(4, 3), mp(3, 1), mp(2, 3), mp(4, 2), mp(1, 1), mp(3, 4), mp(4, 1), mp(2, 2)};

void pri(vector<pii> aa)
{
    for(pii p : aa)
    {
        int x = p.fi, y = p.se;
        if(flag) swap(x, y);
        printf("%d %d\n", x, y);
    }
}

int main()
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &m); flag = false; ans.clear(); a2x.clear(); a3x.clear();
        pr2(cas); if(n > m) {flag = true; swap(n, m);}
        if((n <= 3 && m <= 3) || n <= 1 || (m + n == 6 && m * n == 8)) {puts("IMPOSSIBLE"); continue;}
        puts("POSSIBLE");
        if(n == 3 && m == 4) {pri(a34); continue;}
        if(n == 4 && m == 4) {pri(a44); continue;}
        // 2 * x
        for(int i = 1; i <= m - 3; i ++) {a2x.pb(mp(1, i)); a2x.pb(mp(2, i + 3));} 
        a2x.pb(mp(1, m - 2)); a2x.pb(mp(2, 1)); a2x.pb(mp(1, m - 1)); a2x.pb(mp(2, 2)); a2x.pb(mp(1, m));a2x.pb(mp(2, 3));
        // 3 * x
        for(int i = 1; i <= m - 2; i ++) {a3x.pb(mp(1, i)); a3x.pb(mp(2, i + 2)); a3x.pb(mp(3, i));}
        a3x.pb(mp(1, m - 1)); a3x.pb(mp(2, 1)); a3x.pb(mp(3, m - 1)); a3x.pb(mp(1, m)); a3x.pb(mp(2, 2)); a3x.pb(mp(3, m));
        // Solve
        int bg = 0;
        if(n & 1)
        {
            for(pii p : a3x) ans.pb(mp(p.fi + bg, p.se));
            bg = 3;
        }
        for(; bg < n; bg += 2)
            for(pii p : a2x) ans.pb(mp(p.fi + bg, p.se));
        pri(ans);
    }
    return 0;
}
