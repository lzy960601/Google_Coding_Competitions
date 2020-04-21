/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-04-20
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

const int bound = 1e9 + 1;
mt19937 gen(19260817);

char s[15];
int query(int x, int y)
{
    printf("%d %d\n", x, y);
    cerr << x << " " << y << endl;
    fflush(stdout);
    scs(s + 1);
    if(s[1] == 'C') return 2;
    if(s[1] == 'H') return 1;
    if(s[1] == 'M') return -1;
    //assert(0); return 0;
    return -1;
}

int rd()
{
    int k = gen() % 2;
    k = 2 * k - 1;
    int v = gen() % bound;
    return k * v;
}

int T, A, B;

bool find_bound(int x, int y)
{
    int res = 0;
    // find right
    int rl = y, rr = bound - 1;
    while(rr - rl > 1)
    {
        int mid = (rl + rr) / 2;
        res = query(x, mid);
        if(res == 2) return true;
        if(res > 0) rl = mid; else rr = mid;
    }
    while((res = query(x, rr)) < 0) -- rr;
    if(res == 2) return true;
    // find left
    int ll = -(bound - 1), lr = y;
    while(lr - ll > 1)
    {
        int mid = (ll + lr) / 2;
        res = query(x, mid);
        if(res == 2) return true;
        if(res > 0) lr = mid; else ll = mid;
    }
    while((res = query(x, ll)) < 0) ++ ll;
    if(res == 2) return true;
    // find up
    int ul = x, ur = bound - 1;
    while(ur - ul > 1)
    {
        int mid = (ul + ur) / 2;
        res = query(mid, y);
        if(res == 2) return true;
        if(res > 0) ul = mid; else ur = mid;
    }
    while((res = query(ur, y)) < 0) -- ur;
    if(res == 2) return true;
    // find down
    int dl = -(bound - 1), dr = x;
    while(dr - dl > 1)
    {
        int mid = (dl + dr) / 2;
        res = query(mid, y);
        if(res == 2) return true;
        if(res > 0) dr = mid; else dl = mid;
    }
    while((res = query(dl, y)) < 0) ++ dl;
    if(res == 2) return true;
    res = query((ur + dl) >> 1, (ll + rr) >> 1);
    return res == 2;
}

int main()
{	
    scanf("%d%d%d", &T, &A, &B);
    while(T --)
    {
        bool flag = false;
        while(!flag)
        {
            int res = 0, x = 0, y = 0;
            while(res <= 0)
            {
                x = rd(); y = rd();
                res = query(x, y);
            }
            cerr << "random success" << endl;
            if(res == 2) break;
            flag = find_bound(x, y);
        }
        cerr << "end one case" << endl;
    }
    return 0;
}
