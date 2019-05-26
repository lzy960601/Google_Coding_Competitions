/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2019-05-26
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

const int maxn = 200005;
int T;
int n, r, c, sr, sc;
map<pii, pii> fax, fay, up, down, le, ri;

pii findx(pii t)
{
	if(fax[t] == t) return t;
	return fax[t] = findx(fax[t]);
}

pii findy(pii t)
{
	if(fay[t] == t) return t;
	return fay[t] = findy(fay[t]); 
}

void addx(int x,int y)
{
	bool hl = fax.count(mp(x, y - 1)), hr = fax.count(mp(x, y + 1));
	if(!hl && !hr)
	{
		fax[mp(x, y)] = mp(x, y);
		le[mp(x, y)] = mp(x,y - 1);
		ri[mp(x, y)] = mp(x,y + 1);
	}
	if(hl && !hr)
	{
		fax[mp(x, y)] = findx(mp(x, y - 1));
		ri[findx(mp(x, y - 1))] = mp(x, y + 1);
	}
	if(!hl && hr)
	{
		fax[mp(x, y)] = findx(mp(x, y + 1));
		le[findx(mp(x, y + 1))] = mp(x, y - 1);
	}
	if(hl && hr)
	{
		pii f1 = findx(mp(x, y - 1)); 
        pii f2 = findx(mp(x, y + 1));
		fax[mp(x, y)] = fax[f2] = f1;
		ri[f1] = ri[f2]; 
	} 
}

void addy(int x, int y)
{
	bool hu = fay.count(mp(x - 1, y)), hd = fay.count(mp(x + 1, y));
	if(!hu && !hd)
	{
		fay[mp(x, y)] = mp(x, y);
		up[mp(x, y)] = mp(x - 1,y );
		down[mp(x, y)] = mp(x + 1, y);
	}
	if(hu && !hd)
	{
		fay[mp(x, y)] = findy(mp(x - 1, y));
		down[findy(mp(x - 1, y))] = mp(x + 1, y);
	}
	if(!hu && hd)
	{
		fay[mp(x, y)] = findy(mp(x + 1, y));
		up[findy(mp(x + 1, y))] = mp(x - 1, y);
	}
	if(hu && hd)
	{
		pii f1 = findy(mp(x - 1, y));
        pii f2 = findy(mp(x + 1, y));
		fay[mp(x, y)] = fay[f2] = f1;
		down[f1] = down[f2];
	}
}
char s[maxn];
int main()
{
    scd(T);
	for(int cas = 1; cas <= T; ++ cas)
	{
		scanf("%d%d%d%d%d", &n, &r, &c, &sr, &sc);
		fax.clear(); fay.clear(); up.clear(); down.clear(); le.clear(); ri.clear();
		pii now=mp(sr, sc); fax[now]=now; fay[now]=now;
		up[now] = mp(now.fi-1, now.se); down[now] = mp(now.fi+1, now.se);
		le[now] = mp(now.fi, now.se-1); ri[now] = mp(now.fi, now.se+1);
		scs(s);
		for(int i = 0; i < n ;++ i)
		{
			if(s[i] == 'N') now = up[findy(now)];
			if(s[i] == 'S') now = down[findy(now)];
			if(s[i] == 'W') now = le[findx(now)];
			if(s[i] == 'E') now = ri[findx(now)];
			int x=now.fi, y=now.se;
			addx(x,y); addy(x,y);
		}
        prcas(cas); printf("%d %d\n", now.fi, now.se);
	}
	return 0;
}
