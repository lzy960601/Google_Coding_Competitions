/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-05-26
File: B.cpp
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
const double eln = 2.718281828459045235360287471352;

#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", \
    __func__, ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif

#define LL long long
#define IN freopen("sample.in", "r", stdin)
#define OUT freopen("sample.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas(x) printf("Case #%d: ", x)
#define pncas(x) printf("Case #%d:\n", x)
#define lowbit(x) (x & (-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

const int maxn = 305;
int len[maxn][maxn], st_ma[10][maxn], st_mi[10][maxn], lo[maxn];
int n, T, m, lim;
int a[maxn], le[maxn], ri[maxn];
stack<int> s;

int find(int l, int r)
{
    int t = lo[r - l + 1];
    int ma = max(st_ma[t][l], st_ma[t][r - (1 << t) + 1]);
    int mi = min(st_mi[t][l], st_mi[t][r - (1 << t) + 1]);
    return ma - mi;
}

int main()
{
    lo[1] = 0; for(int i = 2; i <= 300; ++ i) lo[i] = lo[i >> 1] + 1;
  	scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scd(n); scd(m); scd(lim);
        for(int i = 1; i <= n; ++ i)
        {
            for(int j = 1; j <= m; ++ j)
            {
                int x; scd(x);
                st_ma[0][j] = st_mi[0][j] = x;
            }
            for(int k = 1; (1 << k) <= m; ++ k)
                for(int u = 1; u + (1 << k) - 1 <= m; ++ u)
                {
                    st_ma[k][u] = max(st_ma[k - 1][u], st_ma[k - 1][u + (1 << (k - 1))]);
                    st_mi[k][u] = min(st_mi[k - 1][u], st_mi[k - 1][u + (1 << (k - 1))]);
                }
            for(int j = 1; j <= m; ++ j)
            {
                int l = j, r = m;
                while(r - l > 1)
                {
                    int mid = (l + r) >> 1;
                    if(find(j, mid) <= lim) l = mid; else r = mid; 
                }
                while(l <= m && find(j, l) <= lim) ++ l;
                len[i][j] = l - j;
            }
        }
        int ans = 0;
        for(int j = 1; j <= m; ++ j)
        {
            for(int i = 1; i <= n; ++ i) a[i] = len[i][j];
            a[0] = a[n + 1] = 0;
            // left
            while(!s.empty()) s.pop();
            s.push(0);
            for(int i = 1; i <= n; ++ i)
            {
                while(a[s.top()] >= a[i]) s.pop();
                le[i] = s.top(); s.push(i);
            }
            // right
            while(!s.empty()) s.pop();
            s.push(n + 1);
            for(int i = n; i >= 1; -- i)
            {
                while(a[s.top()] >= a[i]) s.pop();
                ri[i] = s.top(); s.push(i);
            }
            for(int i = 1; i <= n; ++ i) ans = max(ans, a[i] * (ri[i] - le[i] - 1));
        }
        prcas(cas); printf("%d\n", ans);
    }
    return 0;
}
