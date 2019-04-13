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

char s[55];
struct node
{
    int sum, val, fat;
    map<int, int> mp;
    void clear(){sum = val = fat = 0; mp.clear();}
}tr[50005];
int T, n, nodes;

int DFS(int now)
{
    int ret = 0;
    for(int i = 1; i <= 26; ++ i)
    {
        if(tr[now].mp[i] == 0) continue;
        int nxt = tr[now].mp[i];
        if(tr[nxt].sum >= 2)
        {
            int s = DFS(nxt);
            ret += s; tr[now].sum -= s;
        }
    }
    if(tr[now].sum >= 2 && now > 0) {ret += 2; tr[now].sum -= 2;}
    //tr[now].sum -= ret;
    //printf("%d %d %d\n", now, tr[now].val, ret);
    return ret;
}

int main()
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        tr[0].clear(); nodes = 0; tr[0].fat = -1;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i)
        {
            scanf("%s", s + 1);
            int len = strlen(s + 1);
            int now = 0;
            for(int i = len; i >= 1; i --)
            {
                int tmp = s[i] - 64;
                if(tr[now].mp[tmp] == 0) {tr[now].mp[tmp] = ++ nodes; tr[nodes].clear(); tr[nodes].fat = now; tr[nodes].val = tmp;}
                now = tr[now].mp[tmp];
            }
            while(now >= 0) {tr[now].sum ++; now = tr[now].fat;}
        }
        pr2(cas); printf("%d\n", DFS(0));
    }
    return 0;
}
