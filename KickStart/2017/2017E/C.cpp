/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-05-14
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

#define EPS 1e-10
#define INF 1e18
#define PI 3.14159265358979323846
#define EQ(t1, t2) (abs((t1) - (t2)) < EPS)
#define LE(t1, t2) ((t2) - (t1) > EPS)
#define LEQ(t1, t2) ((t1) - (t2) < EPS)
#define NEXT(i,n) ((i)+1>=(n)?0:(i)+1)
#define PREV(i,n) ((i)>0?(i)-1:(n)-1)
inline int SGN(double t){ return LE(t, 0) ? -1 : LE(0, t) ? 1 : 0; }
struct Point
{
	double x, y;
	bool operator == (const Point& p)const{ return EQ(x, p.x) && EQ(y, p.y); }
	bool operator < (const Point& p)const{ return LEQ(x, p.x) && (LE(x, p.x) || LE(y, p.y)); }
	Point operator + (const Point& p)const{ return{ x + p.x, y + p.y }; }
	Point operator - (const Point& p)const{ return{ x - p.x, y - p.y }; }
	double operator * (const Point& p)const{ return x*p.y - y*p.x; }
	Point operator * (double value)const{ return{ x*value, y*value }; }
	Point operator / (double value)const{ return{ x / value, y / value }; }
	double dot(const Point& p)const{ return x*p.x + y*p.y; }
	double r2()const{ return x*x + y*y; }
	double r()const{ return sqrt(x*x + y*y); }
	double dis2(const Point& p)const{ return (*this - p).r2(); }
	double dis(const Point& p)const{ return (*this - p).r(); }
	Point rotate90()const{ return{ -y, x }; }
    int direction(const Point& p1, const Point& p2)const{
		return SGN(x*(p1.y - p2.y) + p1.x*(p2.y - y) + p2.x*(y - p1.y));
	}
	bool onLine(const Point& p1, const Point& p2)const{
		return direction(p1, p2) == 0;
	}
}p[3];

struct Circle
{
    Point o;
    double r;
}c[3];

vector<double> getdis()
{
    double a[3][3];
    for(int i = 0; i < 3; ++ i)
        for(int j = 0; j < 3; ++ j) scanf("%lf", &a[i][j]);
    vector<double> ret; ret.clear();
    for(int i = 0; i < 3; ++ i)
        for(int j = i + 1; j < 3; ++ j)
        {
            double sum = 0;
            for(int k = 0; k < 3; ++ k)
                sum += sqr(a[i][k] - a[j][k]);
            ret.pb(sqrt(sum));
        }
    return ret;
}

inline Point lineLineIntersectPoint(const Point& p1, const Point& p2, const Point& q1, const Point& q2){
	Point q12 = q2 - q1;
	double k = (p2 - p1)*q12;
	if (EQ(k, 0))return{ INF*INF, INF*INF };
	double r = ((q1 - p1)*q12) / k;
	return p1 + (p2 - p1) * r;
}
//外心
Point circumcenter(const Point& p1, const Point& p2, const Point& p3)
{
	Point t1 = (p1 + p2)*0.5, t2, t3 = (p2 + p3)*0.5, t4;
	t2 = t1 + (p1 - p2).rotate90();
	t4 = t3 + (p2 - p3).rotate90();
	return lineLineIntersectPoint(t1, t2, t3, t4);
}

void circleCircleIntersectPoint(const Point& o1, double r1, const Point& o2, double r2, Point& ret1, Point& ret2)
{
	double d2 = o1.dis2(o2);
	double t1 = (r1*r1 - r2*r2) / (2 * d2) + 0.5;
	double t2 = r1*r1 / d2 - t1*t1;
	t2 = LEQ(t2, 0) ? 0 : sqrt(t2);
	Point foot = o1 + (o2 - o1)*t1;
	ret1 = foot + (o2 - o1).rotate90()*t2;
	ret2 = foot * 2 - ret1;
}

bool check(double r)
{
    for(int ce = 0; ce < 3; ++ ce)
    {
        for(int i = 0; i < 3; ++ i)
            if(i == ce) c[i] = {p[i], r};
            else c[i] = {p[i], 3.0 * r};
        for(int i = 0; i < 3; ++ i)
            for(int j = i + 1; j < 3; ++ j)
            {
                if(!LEQ(c[i].o.dis(c[j].o), c[i].r + c[j].r)) continue;
                Point x, y;
                circleCircleIntersectPoint(c[i].o, c[i].r, c[j].o, c[j].r, x, y);
                int id = 3 - i - j;
                if(LEQ(c[id].o.dis(x), c[id].r)) return true;
                if(LEQ(c[id].o.dis(y), c[id].r)) return true;
            }
    }
    for(int ce = 0; ce < 3; ++ ce)
    {
        for(int i = 0; i < 3; ++ i)
            if(i == ce) c[i] = {p[i], 5.0 * r};
            else c[i] = {p[i], r};
        for(int i = 0; i < 3; ++ i)
            for(int j = i + 1; j < 3; ++ j)
            {
                if(!LEQ(c[i].o.dis(c[j].o), c[i].r + c[j].r)) continue;
                Point x, y;
                circleCircleIntersectPoint(c[i].o, c[i].r, c[j].o, c[j].r, x, y);
                int id = 3 - i - j;
                if(LEQ(c[id].o.dis(x), c[id].r)) return true;
                if(LEQ(c[id].o.dis(y), c[id].r)) return true;
            }
    }
    return false;
}

double solve()
{
    vector<double> dis = getdis();
    p[0] = {0.0, 0.0};
    p[1] = {dis[0], 0.0};
    Point noneed;
    circleCircleIntersectPoint(p[0], dis[1], p[1], dis[2], p[2], noneed);

    //same line
    if(p[0].onLine(p[1], p[2]))
    {
        double ans = 0;
        ans = max(ans, p[0].dis(p[1]));
        ans = max(ans, p[0].dis(p[2]));
        ans = max(ans, p[1].dis(p[2]));
        return ans / 6.0;
    }

    //for(int i = 0; i < 3; ++ i) _debug("%.4f %.4f", p[i].x, p[i].y);
    double l = 0, r = p[0].dis(circumcenter(p[0], p[1], p[2]));
    int cnt = 100;
    while(cnt --)
    {
        double mid = (l + r) * 0.5;
        if(check(mid)) r = mid; else l = mid;
    }
    return l;
}

int main()
{
    int T; scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        double ans = solve();
        prcas; printf("%.12f\n", ans);
    }
    return 0;
}