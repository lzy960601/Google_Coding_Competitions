/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-11-15
File: D.cpp
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

#define IN freopen("D.in", "r", stdin)
#define OUT freopen("D.out", "w", stdout)
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

int dis[26][26], T, n, m;
string s[50005];

void solve(int cas)
{
    cin >> n >> m;
    for(int i = 0; i < 26; ++ i)
        for(int j = 0; j < 26; ++ j)
            dis[i][j] = 100;
    for(int i = 0; i < 26; ++ i) dis[i][i] = 0;
    for(int i = 1; i <= n; ++ i)
    {
        cin >> s[i];
        int len = s[i].length();
        for(int j = 0; j + 1 < len; ++ j)
            for(int k = j + 1; k < len; ++ k)
            {
                int x = s[i][j] - 'A', y = s[i][k] - 'A';
                dis[x][y] = dis[y][x] = min(dis[x][y], 1);
            }
    }
    for(int k = 0; k < 26; ++ k)
        for(int i = 0; i < 26; ++ i)
            for(int j = 0; j < 26; ++ j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    cout << "Case #" << cas << ":";
    while(m --)
    {
        int x, y;
        cin >> x >> y;
        cout << " ";
        if(x == y)
        {
            cout << 1;
            continue;
        }
        int d = 100;
        for(int i = 0; i < s[x].length(); ++ i)
            for(int j = 0; j < s[y].length(); ++ j)
                d = min(d, dis[s[x][i] - 'A'][s[y][j] - 'A'] + 2);
        if(d >= 100) cout << -1; else cout << d;
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> T;
    for(int cas = 1; cas <= T; ++ cas) solve(cas);
    return 0;
}
