#include<bits/stdc++.h>
using namespace std;

const int maxn = 260;
char ss[maxn][505];
bool vis[maxn];
int T, n, len[maxn];
string ans;

int main()
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++)
    {
        scanf("%d", &n); ans = "";
        for(int i = 1; i <= n; ++ i) scanf("%s", ss[i] + 1), len[i] = strlen(ss[i] + 1);
        for(int i = 1; i <= n; ++ i) vis[i] = false;
        int cnt = n, pos = 0;
        while(cnt > 0)
        {
            pos ++;
            int r = 0, p = 0, s = 0;
            for(int i = 1; i <= n; ++ i)
            {
                if(vis[i]) continue;
                int now = ((pos - 1) % len[i]) + 1;
                if(ss[i][now] == 'R') r ++;
                if(ss[i][now] == 'P') p ++;
                if(ss[i][now] == 'S') s ++;
            }
            if(r > 0 && p > 0 && s > 0) {cnt = -1; break;}
            if(s + r <= 0) {ans += 'S'; cnt = 0; break;}
            if(s + p <= 0) {ans += 'P'; cnt = 0; break;}
            if(p + r <= 0) {ans += 'R'; cnt = 0; break;}
            if(s == 0)
            {
                ans += 'P';
                for(int i = 1; i <= n; ++ i)
                {
                    if(vis[i]) continue;
                    int now = ((pos - 1) % len[i]) + 1;
                    if(ss[i][now] == 'R') {vis[i] = true; cnt --;}
                }
                continue;
            }
            if(r == 0)
            {
                ans += 'S';
                for(int i = 1; i <= n; ++ i)
                {
                    if(vis[i]) continue;
                    int now = ((pos - 1) % len[i]) + 1;
                    if(ss[i][now] == 'P') {vis[i] = true; cnt --;}
        
                }
                continue;
            }
            if(p == 0)
            {
                ans += 'R';
                for(int i = 1; i <= n; ++ i)
                {
                    if(vis[i]) continue;
                    int now = ((pos - 1) % len[i]) + 1;
                    if(ss[i][now] == 'S') {vis[i] = true; cnt --;}
                }
                continue;
            }
        }
        printf("Case #%d: ", cas);
        if(cnt < 0) cout << "IMPOSSIBLE" << endl; else cout << ans << endl;
    }
    return 0;
}
