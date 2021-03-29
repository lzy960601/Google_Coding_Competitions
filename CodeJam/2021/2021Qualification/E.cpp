#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<bitset>
#include<cmath>
#include<assert.h>
#include<time.h>
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i--)
#define link(x) for(edge *j=h[x];j;j=j->next)
#define mem(a) memset(a,0,sizeof(a))
#define ll long long
#define succ(x) (1<<x)
#define lowbit(x) (x&(-x))
#define sqr(x) ((x)*(x))
#define mid (x+y>>1)
#define NM 10005
#define nm 200005
using namespace std;
const double pi=acos(-1);
const double eps=1e-8;
const ll inf=1e9+7;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return f*x;
}

const int n=100;
const int m=10000;

int a[NM],ca;
double b[NM],c[NM],d[NM],g[NM];
char s[105][NM];

int main(){
    //freopen("cheating_detection_sample_ts1_input.txt","r",stdin);
    int _=read();read();while(_--){
        mem(a);mem(b);mem(c);mem(d);mem(g);
        inc(i,1,n)scanf("%s",s[i]+1);
        inc(i,1,n)inc(j,1,m)if(s[i][j]=='1')b[j]++;
        inc(i,1,m)b[i]/=n;
        inc(i,1,m){
            b[i]=log((exp(6)-1)/(exp(b[i])-1)-1)-3;
        }
        inc(i,1,n)inc(j,1,m){
            if(s[i][j]=='1'){
                a[i]++;
                c[i]+=b[j];
            }else{
                d[i]+=b[j];
            }
        }
        inc(i,1,n){
            c[i]/=a[i];
            if(a[i]<m)d[i]/=(m-a[i]);else d[i]=3;
        }
        inc(i,1,n)g[i]=c[i]/d[i];
        //inc(i,1,n)printf("%d:%lf\n",i,g[i]);
        int t=1;
        inc(i,2,n)if(g[t]<g[i])t=i;
        printf("Case #%d: %d\n",++ca,t);
    }
}

