/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-23
File: C.cpp
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

#define IN freopen("C.in", "r", stdin)
#define OUT freopen("C.out", "w", stdout)
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

int T, X;

char c[3] = {'R', 'P', 'S'};
int W, E;
double all = 0;
void go(string s)
{
    cout << s << endl;
    int cnt[3] = {0, 0, 0};
    for(char cc : s)
    {
        int v = (cc == 'R' ? 0 : (cc == 'P' ? 1 : 2)), u = cnt[0] + cnt[1] + cnt[2] - 1;
        if(cnt[0] + cnt[1] + cnt[2] == 0)
        {
            all += (double)(W + E) / 3.0;
        }else{
            all += (double)cnt[(v + 1) % 3] / (double)u * (double) W;
            all += (double)cnt[(v + 2) % 3] / (double)u * (double) E;
        }
    }
}

void solve(int cas)
{
    scanf("%d%d", &W, &E);
    prcas;
    if(E == W) go("SPRRSPSPRPRSRSPRSPRSPRSPSPRSRPSRPSRPSPRSRPSPRSPRRSPRSPSPRRSP");
    if(E * 2 == W) go("SPPRRRRSSSSSSSSPPPPPPPPPPPPPPPPRRRRRRRRRRRRRRRRRRRSSSSSSSSSS");
    if(E * 10 == W) go("SPPPPRRRRRRRRRRRRRRRSSSSSSSSSSSSSSSSSSSSSSSSSPPPPPPPPPPPPPPP");
    if(E == 0) go("PRRRRRRRRRSSSSSSSSSSSSSSSSSSSSSSSSSSSPPPPPPPPPPPPPPPPPPPPPPP");
}

int main()
{
    scd(T); scd(X);
    for(int cas = 1; cas <= T; ++ cas)
        solve(cas);
    cout << all / (double)T << endl;
    return 0;
}