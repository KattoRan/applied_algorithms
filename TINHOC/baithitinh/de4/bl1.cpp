#include<bits/stdc++.h>
#define name "bl1"
using namespace std;
const int maxn=1e6+3;
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
void nhap()
{
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
}
int ccw(point a,point b,point c)
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
void xuli()
{
    int d1,d2,d3,d4;
    d1=ccw(a,b,c);
    d2=ccw(a,b,d);
    d3=ccw(c,d,a);
    d4=ccw(c,d,b);
    if(d1!=0&&d2!=0&&d3!=0&&d4!=0)
    {
        if((d1*d2<0)&&(d3*d4<0))
        {
            point g=gd(a,b,c,d);
            cout<<std::setprecision(2)<<fixed<<g.x<<" "<<g.y;
        }
        else cout<<0;
    }
    else
    {
        int dem=0;
        point gg;
        if(ok(c,a,b)) dem++,gg=c;
        if(ok(d,a,b)) dem++,gg=d;
        if(ok(a,c,d)) dem++,gg=a;
        if(ok(b,c,d)) dem++,gg=b;
        if(dm(a,c)) dem--;
        if(dm(a,d)) dem--;
        if(dm(b,c)) dem--;
        if(dm(b,d)) dem--;
        if(dem==0) cout<<0;
        if(dem==1)
        {
            cout<<std::setprecision(2)<<fixed<<gg.x<<" "<<gg.y;
        }
        if(dem==2) cout<<"VOSO";
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    nhap();
    xuli();
}

