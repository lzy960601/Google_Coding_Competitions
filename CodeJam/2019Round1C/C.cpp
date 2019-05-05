#include<bits/stdc++.h>
using namespace std;
#define N 20
int b[N][N];
int a[N][N][N][N],test,T,n,m,ans;
char c[N];
int vis[N*N];
inline bool check1(int x,int y1,int y2) {
    for (int i=y1;i<=y2;i++) if (!b[x][i]) return false;
    return true;
}
inline bool check2(int y,int x1,int x2) {
    for (int i=x1;i<=x2;i++) if (!b[i][y]) return false;
    return true;
}
int main() {
    scanf("%d",&test);
    while (test--) {
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) {
            scanf("%s",c);
            for (int j=0;j<m;j++) b[i][j+1]=(c[j]=='.');
        }
        for (int dx=0;dx<=n;dx++)
        for (int dy=0;dy<=m;dy++)
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) {
            if (i+dx>n||j+dy>m) continue;
            for (int x=i;x<=i+dx;x++) if (check1(x,j,j+dy))
            vis[a[i][j][x-1][j+dy]^a[x+1][j][i+dx][j+dy]]=1;
            for (int y=j;y<=j+dy;y++) if (check2(y,i,i+dx))
            vis[a[i][j][i+dx][y-1]^a[i][y+1][i+dx][j+dy]]=1;
            int x=0;
            while (vis[x]) x++;
            memset(vis,0,sizeof(vis));
            a[i][j][i+dx][j+dy]=x;
        }
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) {
            if (check1(i,1,m)&&!(a[1][1][i-1][m]^a[i+1][1][n][m])) ans++;
            if (check2(j,1,n)&&!(a[1][1][n][j-1]^a[1][j+1][n][m])) ans++;
        }
        printf("Case #%d: %d\n",++T,ans);
        ans=0;
    }
}
