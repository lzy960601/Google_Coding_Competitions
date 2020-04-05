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

const int maxn = 505;
int sum[maxn][maxn], dis[maxn][maxn], dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char a[maxn][maxn];
queue< pii > q;
int T, n, m;

bool legal(int x, int y) {return x > 0 && x <= n && y > 0 && y <= m;}

bool check(int dd)
{
    int cnt = 0, N = 2 * max(n, m) - 1, NN = max(n, m);
    for(int i = 0; i <= N; ++ i)
        for(int j = 0; j <= N; ++ j)
            sum[i][j] = 0;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
        {
            if(dis[i][j] <= dd) continue;
            cnt ++;
            int x = NN + i - j, y = i + j - 1;
            int u = max(1, x - dd);
            int d = min(N, x + dd);
            int l = max(1, y - dd);
            int r = min(N, y + dd);
            sum[u][l] ++;
            sum[u][r + 1] --;
            sum[d + 1][l] --;
            sum[d + 1][r + 1] ++;
        }
    //printf("-- %d : %d\n",cnt, dd);
    for(int i = 1; i <= N; ++ i)
        for(int j = 1; j <= N; ++ j)
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    for(int i = 1; i <= N; ++ i)
        for(int j = 1; j <= N; ++ j)
            if(sum[i][j] >= cnt && ((i + j + NN) & 1) && (i - j <= NN - 1) && (i - j >= 1 - NN)) return true;
    return false;
}

void BFS()
{
    while(!q.empty()) q.pop();
    for(int i = 1; i <= n; ++ i) 
        for(int j = 1; j <= m; ++ j)
            dis[i][j] = 1000;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            if(a[i][j] == '1') {dis[i][j] = 0; q.push(mp(i, j));}
    while(!q.empty())
    {
        pii t = q.front(); q.pop();
        for(int di = 0; di < 4; ++ di)
        {
            int x = t.fi + dir[di][0];
            int y = t.se + dir[di][1];
            if(!legal(x, y) || dis[x][y] < 1000) continue;
            dis[x][y] = dis[t.fi][t.se] + 1;
            q.push(mp(x, y));
        }
    }
}

int main()
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++ i) scanf("%s", a[i] + 1);
        BFS();
        int l = 0, r = n + m;
        while(r - l > 1)
        {
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid; else l = mid;
        }
        while(r >= 0 && check(r)) r --;
        prr(cas); printf("%d\n", r + 1);
    }   
    return 0;
}
