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
int T, N, A, B, C, a[maxn], b[maxn];

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d%d%d", &N, &A, &B, &C);
        for(int i = 1; i <= N; ++ i) a[i] = 0;
        if(N == 1)
        {
            prcas;
            if(A == 1 && B == 1 && C == 1)
                puts("1");
            else
                puts("IMPOSSIBLE");
            continue;
        }
        if(N == 2)
        {
            prcas;
            if(A == 1 && B == 1 && C == 1) { puts("IMPOSSIBLE"); continue; }
            if(A == 1 && B == 2 && C == 1) { puts("2 1"); continue; }
            if(A == 2 && B == 1 && C == 1) { puts("1 2"); continue; }
            if(A == 2 && B == 2 && C == 1) { puts("IMPOSSIBLE"); continue; }
            if(A == 2 && B == 2 && C == 2) { puts("2 2"); continue; }
            assert(0);
            continue;
        }
        int l = A - C, r = B - C;
        if(l + r + C > N) {prcas; puts("IMPOSSIBLE"); continue;}
        if(C >= 2)
        {
            for(int i = 1; i <= l; ++ i) a[i] = 1;
            for(int i = 1; i <= r; ++ i) a[N - i + 1] = 1;
            a[l + 1] = a[N - r] = N;
            for(int i = 1; i <= C - 2; ++ i) a[l + i + 1] = N;
            for(int i = 1; i <= N; ++ i) if(a[i] == 0) a[i] = 1;
        }else
        {
            if(l + r <= 0) {prcas; puts("IMPOSSIBLE"); continue;}
            if(l == 0)
            {
                a[1] = N;
                for(int i = 1; i <= r; ++ i) a[N - i + 1] = 2;
                for(int i = 2; i <= N - r; ++ i) a[i] = 1;
            }
            if(r == 0)
            {
                a[N] = N;
                for(int i = 1; i <= l; ++ i) a[i] = 2;
                for(int i = l + 1; i < N; ++ i) a[i] = 1;
            }
            if(l > 0 && r > 0)
            {
                for(int i = 1; i <= l; ++ i) a[i] = 2;
                a[l + 1] = N;
                for(int i = 1; i <= r; ++ i) a[N - i + 1] = 2;
                for(int i = l + 2; i <= N - r; ++ i) a[i] = 1;
            }
        }
        prcas; for(int i = 1; i <= N; ++ i) printf("%d%c", a[i], i == N ? '\n' : ' ');
    }
    return 0;
}


