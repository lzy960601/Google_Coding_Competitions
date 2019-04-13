/*****************************************
Author: lizi
Email: zyli@smail.nju.edu.cn
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
  
vi ans, sta;
int T, n, b, f;
const int maxn = 1024;
vector<string> g[64];

string inter(int n, string s)
{
    string tmp = "";
    for(int i = 0; i < n; ++ i) tmp += s[i];
    cout << tmp << endl; fflush(stdout);
    string ret = "";
    cin >> ret;
    for(int i = n; i < maxn; ++ i) ret += s[i];
    return ret;
}

int interans()
{
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++ i)
    {
        if(i > 0) cout << ' ';
        cout << ans[i];
    }
    cout << endl; fflush(stdout);
    int ret; cin >> ret;
    return ret;
}

void solve(int label, int layer, int l, int r, int base)
{
    if(l == r)
    {
        //cout << "!!!  " << layer << ' ' << l << ' ' << r << ' ' << base << endl;
        for(int i = 0; i < (1 << (layer + 1)); ++ i) ans.pb(base + i);
        return;
    }
    if(layer < 0) return;
    string test = "";
    for(int i = l; i < r; ++ i) test += g[label][layer][i];
    //cout << layer << ' ' << l << ' ' << r << ' ' << base << ' ' << test << endl;
    int cnt = 0; 
    while(cnt < test.size() && test[cnt] == '0') ++ cnt;
    solve(label, layer - 1, l, l + cnt, base);
    solve(label, layer - 1, l + cnt, r, base + (1 << layer));
}

int main()
{
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d%d", &n, &b, &f); ans.clear(); sta.clear();
        cerr << "C++ : " << n << '-' << b << '-' << f << endl; 
        // First Time
        string now = "";
        for(int i = 0; i < 64; ++ i)
            for(int j = 0; j < 16; ++ j) now += (char)(48 + (i & 1));
        string ret = inter(n, now);
        int base = 0;
        for(int i = 0; i < 64; ++ i)
        {
            int cnt = 0; g[i].clear();
            while(base < ret.size() && ret[base] == (char)(48 + (i & 1))) {++ base; ++ cnt;}
            sta.pb(cnt);
        }
        // 4 Times
        for(int id = 0; id <= 3; ++ id)
        {
            now = "";
            for(int i = 0; i < 64; ++ i)
                for(int j = 0; j < 16; ++ j) now += (char)(48 + ((j >> id) & 1));
            ret = inter(n, now);
            int bg = 0;
            for(int i = 0; i < 64; ++ i)
            {
                string tmp = "";
                for(int j = bg; j < bg + sta[i]; ++ j) tmp += ret[j];
                g[i].pb(tmp);
                bg += sta[i];
            }
        }
        // Solve
        for(int i = 0; i < 64; ++ i)
        {
            int base = 16 * i;
            solve(i, 3, 0, sta[i], base);
        }
        if(interans() < 0) exit(1);
    }
    return 0;
}
