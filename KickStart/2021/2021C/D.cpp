/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-23
File: D.cpp
*****************************************/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
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
#define rng(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
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

struct Node
{
    int op; // 0 = +, 1 = *, 2 = #
    int state; // 1 = number(leaf), 0 = has #
    string val;
    int ls, rs;
}tr[5005];
int ncnt = 0;

map<string, string> mm;

string splus(string a, string b)
{
    reverse(rng(a)); reverse(rng(b));
    int la = a.length(), lb = b.length();
    int sz = max(la, lb);
    int v = 0;
    string ret = "";
    for(int i = 0; i < sz; ++ i)
    {
        if(i < la) v += a[i] - '0';
        if(i < lb) v += b[i] - '0';
        ret += (char)(v % 10 + '0');
        v /= 10;
    }
    if(v > 0) ret += (char)(v % 10 + '0');
    reverse(rng(ret));
    return ret;
}

string smulti(string a, string b)
{
    reverse(rng(a)); reverse(rng(b));
    int la = a.length(), lb = b.length();
    int sz = la * lb;
    int val[sz + 5];
    for(int i = 0; i < sz + 4; ++ i) val[i] = 0;
    for(int i = 0; i < la; ++ i)
        for(int j = 0; j < lb; ++ j)
            val[i + j] += (a[i] - '0') * (b[j] - '0');
    string ret = "";
    for(int i = 0; i < sz; ++ i)
    {
        val[i + 1] += val[i] / 10;
        val[i] %= 10;
    }
    while(val[sz] > 0)
    {
        val[sz + 1] += val[sz] / 10;
        val[sz] %= 10;
        ++ sz;
    }
    while(sz > 0 && val[sz] == 0) -- sz;
    for(int i = 0; i <= sz; ++ i) ret += (char)(val[i] + '0');
    reverse(rng(ret));
    return ret;
}

void splittree(int &o, char sit[], int l, int r)
{
    o = ++ ncnt;
    if(sit[l] != '(')
    {
        string s = "";
        for(int i = l; i <= r; ++ i) s += sit[i];
        tr[o].op = tr[o].state = 1;
        tr[o].val = s;
        tr[o].ls = tr[o].rs = 0;
        return;
    }
    ++ l; -- r;
    int pcnt = 0;
    for(int i = l; i <= r; ++ i)
    {
        if(sit[i] == '(') { pcnt ++; continue; }
        if(sit[i] == ')') { pcnt --; continue; }
        if(pcnt > 0) continue;
        if(sit[i] == '*' || sit[i] == '+' || sit[i] == '#')
        {
            if(sit[i] == '+') tr[o].op = 0;
            if(sit[i] == '*') tr[o].op = 1;
            if(sit[i] == '#') tr[o].op = 2;
            splittree(tr[o].ls, sit, l, i - 1);
            splittree(tr[o].rs, sit, i + 1, r);
            break;
        }
    }
}

int buildtree()
{
    char sit[105];
    scs(sit + 1);
    int n = strlen(sit + 1);
    ncnt = 0; int root;
    splittree(root, sit, 1, n);
    return root;
}

mt19937 gen(19260817);

string genrd(string s)
{
    if(mm.find(s) != mm.end()) return mm[s];
    string ret = "";
    int k = max((int)s.length(), 10);
    for(int i = 0; i < k; ++ i)
    {
        int v = gen() % 10;
        if(i == 0) v = (gen() % 9) + 1;
        ret += (char)(v + '0');
    }
    //cerr << "!!!" + ret << endl;
    return mm[s] = ret;
}

void reformtree(int o)
{
    if(tr[o].ls == 0) return;
    reformtree(tr[o].ls);
    reformtree(tr[o].rs);
    int ln = tr[o].ls, rn = tr[o].rs;
    tr[o].state = 1;
    if(tr[o].op == 2)
    {
        string u = tr[ln].val;
        string v = tr[rn].val;
        tr[o].val = genrd(u + "#" + v);
        return;
    }
    if(tr[o].op == 0) tr[o].val = splus(tr[ln].val, tr[rn].val);
    if(tr[o].op == 1) tr[o].val = smulti(tr[ln].val, tr[rn].val);
}

string getdone()
{
    int root = buildtree();
    reformtree(root);
    //cerr << endl;
    //for(int i = 1; i <= ncnt; ++ i)
        //cerr << i << " : " << tr[i].op << " " << tr[i].state <<" " << tr[i].val << endl;
    return tr[root].val;
}

void solve(int cas)
{
    map<string, int> m; 
    m.clear(); mm.clear();
    int n, cnt = 0; scd(n);
    prcas; 
    while(n --)
    {
        string has = getdone();
        int ans;
        if(m.find(has) != m.end())
            ans = m[has];
        else
        {
            ans = ++ cnt;
            m[has] = cnt;
        }
        printf("%d%c", ans, n > 0 ? ' ' : '\n');
    }
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
        solve(cas);
    return 0;
}