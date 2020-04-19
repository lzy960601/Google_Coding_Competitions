# 2018 Google Kickstart Round G Solution

## [原文链接](http://liziyang.space/2018/10/22/Work_PT_KS2018G/)

## A

本题是说给你$1 \leq n \leq 7000$个$0 \leq A_i \leq 200000$的非负整数，问你有多少对**无序三元组**满足$1 \leq i \leq n, i \neq j, i \neq k, j \neq k, A_i \times A_j = A_k$.

---

非常简单的题目，只需要特别讨论一下0的情况，然后考虑Kickstart本身是下载数据本地跑然后提交的，于是很暴力的算就可以了，我写了个$O(7000*(200000+7000))$的做法。还拿到了这题大数据的FB嘿嘿嘿。

```cpp
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
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
  
LL a[200005];
int T,n;

int cnt[200005];

int main()
{
    IN;OUT;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        long long ans = 0,cnt0=0;
        for(int i=1;i<=n;i++)if(a[i]==0)cnt0++;else break;
        ans+=cnt0*(cnt0-1)*(cnt0-2)/6;
        ans+=cnt0*(cnt0-1)/2*(n-cnt0);
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)continue;
            for(int j=0;j<=200000;j++)cnt[j]=0;
            for(int j=i+1;j<=n;j++)cnt[a[j]]++;
            for(int j=i+1;j<=n;j++)
            {
                LL tmp=1ll*a[i]*a[j];
                if(tmp>200000)break;
                cnt[a[j]]--;
                ans+=cnt[tmp];
            }
        }
        prr(cas);printf("%lld\n",ans);
    }
    return 0;
}
```

## B

本题是说，给你$1 \leq n \leq 400000$段连续正整数，范围是$1 \leq L_i \leq R_i \leq 10^9$.所有数里面第$1 \leq k \leq 10^9$大的数是几，数目不够答案就是$0$，单组数据询问有$1 \leq q \leq 10^5$个，最后按题目的公式算一下输出。

---

挺不错的题目鸭，原来想的是差分打标记，然后扫一遍，然后觉得这样做可能本地时间不太够，于是有了非常科学的做法。

首先按照题目给的生成器生成好数据，然后离散化，通过扫描线动态扫描每一段数字，因为我们知道这一段中每个数字都有相同的个数，所以可以很方便地计算其中某一排名的数字是几，同时把询问离线排好序，两个同时扫就可以了。

时间复杂度是$O(n\log n + q\log q)$。

```cpp
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
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

struct generator
{
    int a,b,A,B,C,M;
    vector<int> result;
    void read(){scanf("%d%d%d%d%d%d",&a,&b,&A,&B,&C,&M);}
    void gen(int nn)
    {
        result.clear();
        result.pb(a);
        result.pb(b);
        for(int i=2;i<nn;i++)
        {
            LL tmp=1ll*A*result[i-1]+1ll*B*result[i-2]+C;
            result.pb((int)(tmp%M));
        }
    }
}x,y,z;

int n,q,T;
int l[400005],r[400005],ans[100005];
pii query[100005];
int lsh[1000005],ls[1000005],lsc;
int gin[1000005],gout[1000005];

void solve()
{
    LL sum=0;
    ls[0]=0;ls[lsc+1]=0;
    int label=1,cnt=0;
    for(int i=lsc;i>=1;i--)
    {
        LL nxt=sum+1ll*(ls[i+1]-ls[i])*cnt;
        while(label<=q && query[label].fi<=nxt)
        {
            int tmp=query[label].fi-sum;
            int ret=ls[i+1]-(tmp+cnt-1)/cnt;
            ans[query[label].se]=ret;
            label++;
        }
        nxt+=gin[i];
        while(label<=q && query[label].fi<=nxt)
        {
            ans[query[label].se]=ls[i];
            label++;
        }
        cnt-=gout[i];cnt+=gin[i];
        sum=nxt;
    }
}

int main()
{
    IN;OUT;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&n,&q);
        x.read();y.read();z.read();
        x.gen(n);y.gen(n);z.gen(q);
        for(int i=1;i<=n;i++)
        {
            int xx=x.result[i-1],yy=y.result[i-1];
            l[i]=min(xx,yy)+1;
            r[i]=max(xx,yy)+1;
            lsh[2*i-1]=l[i];
            lsh[2*i]=r[i];
        }
        sort(lsh+1,lsh+2*n+1);ls[lsc=1]=lsh[1];
        for(int i=2;i<=2*n;i++)if(lsh[i]!=lsh[i-1])ls[++lsc]=lsh[i];
        for(int i=1;i<=lsc;i++){gin[i]=gout[i]=0;}
        for(int i=1;i<=n;i++)
        { 
            l[i]=lower_bound(ls+1,ls+lsc+1,l[i])-ls; 
            r[i]=lower_bound(ls+1,ls+lsc+1,r[i])-ls; 
            gin[r[i]]++;gout[l[i]]++; 
        }
        for(int i=1;i<=q;i++)query[i]=mp(z.result[i-1]+1,i),ans[i]=0;
        sort(query+1,query+q+1);
        solve();
        LL ret=0;
        for(int i=1;i<=q;i++)
        {
            //printf("%d %d %d\n",i,z.result[i-1]+1,ans[i]);
            ret+=1ll*i*ans[i];
        }
        prr(cas);printf("%lld\n",ret);
    }
    return 0;
}
```

## C

可以说是非常有趣的一道题目了。

题目是给定$n \times m, 1 \leq n,m \leq 100$的网格迷宫，网格四联通。有的格子是障碍不能走，有的格子第一次进入的时候需要花钱，钱不够不能进；有的格子第一次进入的时候可以拿钱。

你有一个初始的钱数， 需要从起点走到终点，走到终点之后也可以不急着离开，继续晃悠。问你最后是否能成功离开这里，能的话能带走多少钱。

所有钱数都不超过$10^5$，需要花钱的格子不超过15个。

---

很棒的题目！

小数据表示没有可以拿钱的格子，于是跑一个单源最短路就完事儿啦！

我一开始没看见15个这个条件，于是痛苦地想了很久QwQ。看到之后就会做啦。

我们考虑这样一件事情，通过状态压缩，我们可以很轻易地知道已经去过某些需要花钱地格子地情况下，手上的最大钱数以及能否到达终点这两件事情。(对于每个状态都暴力BFS/DFS一遍迷宫就行啦)

接着我们对于每个状态，可以求出和目前能到达区域接壤的花钱格子有哪些，并据此判断能否经过这些格子。

接下来我们初始状态定为所有的花钱格子都没有踩， 这样的情况是初始可达的。

我们按照踩过的花钱格子个数从小到大的顺序依次DP，就可以算出对于每个状态，初始态是否可达，以及最终这个状态能否走出迷宫。

如果以上两个条件都满足了，我们就可以拿这个状态下的最大钱数更新答案啦！

复杂度是$O(2^{15} \times 100 \times 100)$。如果有更优的复杂度，欢迎讨论哟~

```cpp
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
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

const int maxn=105;
int money[70005];
int Tx,Ty,Sx,Sy,T,n,m,cnt;
int a[maxn][maxn],label[maxn][maxn],bg;
bool vis[maxn][maxn],canend[70005],canarr[70005];
vi g[16];
vector< pii > reach;

bool legal1(int x,int y,int mask)
{
    if(x<1 || x>n || y<1 || y>m)return false;
    if(a[x][y]<=-100000)return false;
    if(a[x][y]>=0 || ((mask>>(label[x][y]-1))&1))return true;
    return false;
}

bool legal2(int x,int y,int mask)
{
    if(x<1 || x>n || y<1 || y>m)return false;
    if(a[x][y]<=-100000)return false;
    return true;
}

bool DFS(int x,int y,int mask)
{
    if(!legal1(x,y,mask) || vis[x][y])return false;
    //if(mask==0)printf("%d %d\n",x,y);
    vis[x][y]=true;
    if(a[x][y]>0)money[mask]+=a[x][y];
    if(a[x][y]<0)money[mask]+=a[x][y];
    bool flag=false;
    if(x==Tx && y==Ty)flag=true;
    flag|=DFS(x+1,y,mask);
    flag|=DFS(x-1,y,mask);
    flag|=DFS(x,y+1,mask);
    flag|=DFS(x,y-1,mask);
    return flag;
}

void findreach(int x,int y,int mask)
{
    if(!legal2(x,y,mask) || vis[x][y])return;
    vis[x][y]=true;
    if(a[x][y]<0 && a[x][y]>-100000 && ((mask>>(label[x][y]-1))&1)==0)
    {
        reach.pb(mp(x,y));
        return;
    }
    findreach(x+1,y,mask);
    findreach(x-1,y,mask);
    findreach(x,y+1,mask);
    findreach(x,y-1,mask);
}

int main()
{
    IN;OUT;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d%d",&n,&m,&bg);
        scanf("%d%d%d%d",&Sx,&Sy,&Tx,&Ty);
        cnt=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                label[i][j]=0;
                scanf("%d",&a[i][j]);
                if(a[i][j]<0 && a[i][j]>-100000)label[i][j]=++cnt;
            }
        int ans=-1;
        for(int mask=0;mask<(1<<cnt);mask++)money[mask]=bg,canend[mask]=canarr[mask]=false;
        for(int mask=0;mask<(1<<cnt);mask++)
        {
            //money[mask]=0;cost[mask]=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    vis[i][j]=false;
            canend[mask]=DFS(Sx,Sy,mask);
        }   
        for(int i=0;i<=cnt;i++)g[i].clear();
        for(int mask=0;mask<(1<<cnt);mask++)
        {
            int cc=0;
            for(int j=0;j<cnt;j++)if((mask>>j)&1)cc++;
            g[cc].pb(mask);
        }
        canarr[0]=true;
        if(canend[0])ans=max(ans,money[0]);
        for(int cc=0;cc<=cnt;cc++)
            for(int p : g[cc])
            {
                if(!canarr[p])continue;
                if(canend[p])ans=max(ans,money[p]);
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=m;j++)
                        vis[i][j]=false;
                reach.clear();
                findreach(Sx,Sy,p);
                for(pii s : reach)
                {
                    if(money[p]+a[s.fi][s.se]<0)continue;
                    //printf("%d %d %d\n",s.fi,s.se,label[s.fi][s.se]);
                    int mask=p|(1<<(label[s.fi][s.se]-1));
                    canarr[mask]=true;
                }
            }
        prr(cas);printf("%d\n",ans);
    }
    return 0;
}
```

