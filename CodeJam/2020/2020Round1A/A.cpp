/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-04-11
File: A.cpp
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

#define IN freopen("A.in", "r", stdin)
#define OUT freopen("A.out", "w", stdout)
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

string pre, suf, mid;
int havepre, havesuf;
int T, n;
string s[55];

bool solve()
{
    for(int i = 1; i <= n; ++ i)
    {
        int bg = 0, ed = s[i].length() - 1;
        if(!havepre)
        {
            while(s[i][bg] != '*') pre += s[i][bg ++];
            if(bg > 0) havepre = 1;
        }else
        {
            while(s[i][bg] != '*') 
            {
                if(bg < pre.length() && s[i][bg] != pre[bg]) return false;
                if(bg >= pre.length()) pre += s[i][bg];
                ++ bg;
            }
        }
        if(!havesuf)
        {
            while(s[i][ed] != '*') suf += s[i][ed --];
            if(ed + 1 < s[i].length()) havesuf = 1;
        }else
        {
            while(s[i][ed] != '*')
            {
                int v = s[i].length() - ed - 1;
                if(v < suf.length() && s[i][ed] != suf[v]) return false;
                if(v >= suf.length()) suf += s[i][ed];
                -- ed;
            }
        }
        for(int k = bg; k <= ed; ++ k) if(s[i][k] != '*') mid += s[i][k];
    }
    reverse(suf.begin(), suf.end());
    return true;
}

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    for(int cas = 1; cas <= T; ++ cas)
    {
        cin >> n;
        for(int i = 1; i <= n; ++ i) cin >> s[i];
        havepre = 0; havesuf = 0;
        pre = suf = mid = "";
        cout << "Case #" << cas << ": ";
        if(!solve()) cout << "*" << endl; else cout << pre << mid << suf << endl;
    }
    return 0;
}
