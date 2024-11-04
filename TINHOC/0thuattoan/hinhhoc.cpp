// Cat \\
||*---*||
#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define catlan main
#define bit(X,i) ((X>>i)&1)
#define on(X,i) (X|(1<<i))
#define off(X,i) (X^(1<<i))
#define dembit(X) __builtin_popcount(X)
using namespace std;

const int N=1e6+7;

typedef long long ll;
typedef pair<int,int> ii;

template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-')
    {
        tam=-1;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}

void ent()
{

}

void solve()
{

}

const double oo=1e9+1;
typedef pair<int,int>ii;
struct point{double x,y;};
typedef long long ll;
point a,b,c,d;
void ptdt(point p1,point p2,double &a,double &b,double &c)
{
    a=p2.y-p1.y;
    b=p1.x-p2.x;
    c=-(a*p1.x+b*p1.y);

}
point gd(point p1,point p2,point p3,point p4)
{
    double a1,b1,c1,a2,b2,c2;
    ptdt(p1,p2,a1,b1,c1);
    ptdt(p3,p4,a2,b2,c2);
    double d=a1*b2-a2*b1;
    double dx=b1*c2-c1*b2;
    double dy=a2*c1-a1*c2;
    if(d==dx&&dx==dy&&dy==0) return{oo,oo};
    if(d!=0)
    {
        return {(double) dx/d,(double)dy/d};

    }
    return {-oo,-oo};
}
double dist(point a,point b)
{
    return (double)sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool ok(point a,point b,point c)
{
    if(dist(b,a)+dist(a,c)==dist(b,c)) return 1;
    return 0;
}
int ccw(point a,point b,point c) // hướng đi qua 3 điểm
{
    int dx1=a.x-c.x;
    int dy1=a.y-c.y;
    int dx2=b.x-c.x;
    int dy2=b.y-c.y;
    if(dx1*dy2>dx2*dy1) return 1;
    if(dx1*dy2<dx2*dy1) return -1;
    return 0;
}
bool dm(point a,point b)
{
    return(a.x==b.x&&a.y==b.y);
}
double dientich(int i,int j)
{
    double tg=0,s;
    p[j+1]=p[i];
    for(int k=i;k<=j;k++)
        tg+=(p[k+1].y+p[k].y)*(p[k+1].x-p[k].x);
    s=abs(tg)/2;
    return s;
}
void vtcp(point p1, point p2,dd &dx,dd &dy)
{
    dx=p2.x-p1.x;
    dy=p2.y-p1.y;
}
catlan()
{
    #define name ""
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    ent();
    solve();
}
