/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-03-20
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

#define IN freopen("B.in", "r", stdin)
#define OUT freopen("B.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-(x)))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

const int maxn = 100005;
int p[maxn], h[maxn], x[maxn], y[maxn];
bool can[maxn];
int n, m, T, V;
pii s[maxn], t[maxn];

void gen(int a[], int k)
{
    int v1, v2, A, B, C, M;
    scanf("%d%d%d%d%d%d", &v1, &v2, &A, &B, &C, &M);
    a[0] = 0; a[1] = v1; a[2] = v2;
    for(int i = 3; i <= k; ++ i) a[i] = (1ll * A * a[i - 1] + 1ll * B * a[i - 2] + 1ll * C) % M + 1;
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++ i) can[i] = false;
        gen(p, n); gen(h, n); gen(x, m); gen(y, m);
        for(int i = 0; i <= n; ++ i) s[i] = mp(p[i], h[i]);
        for(int i = 0; i <= m; ++ i) t[i] = mp(x[i], y[i]);
        sort(s + 1, s + n + 1); sort(t + 1, t + m + 1);
        V = -1e9;
        for(int i = 1, id = 1; i <= m; ++ i)
        {
            while(id <= n && s[id].fi <= t[i].fi) { V = max(V, s[id].fi + s[id].se); ++ id; }
            if(V >= t[i].fi + t[i].se) can[i] = true;
        }
        V = -1e9;
        for(int i = m, id = n; i >= 1; -- i)
        {
            while(id > 0 && s[id].fi >= t[i].fi) { V = max(V, s[id].se - s[id].fi); -- id; }
            if(V >= t[i].se - t[i].fi) can[i] = true;
        }
        int ans = 0;
        for(int i = 1; i <= m; ++ i) if(can[i]) ++ ans;
        prcas; printf("%d\n", ans);
    }
    return 0;
}
