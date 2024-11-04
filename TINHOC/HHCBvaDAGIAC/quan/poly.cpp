#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define name "poly"
using namespace std;
const int maxn=1e2+3;
const int oo=1e9+1;
typedef pair<int,int>ii;
typedef long long ll;
const double pi=2*acos(0);
struct point {double x,y;};
int n;
point p[maxn],dm,a[maxn];
vector<ii> v;
double smax,res;

double goc(point p1,point p2)
{
    double dx=p2.x-p1.x;
    double dy=p2.y-p1.y;
    if(dx>0)
    {
        if(dy>=0)
            return atan(dy/dx);
        else
            return atan(dy/dx)+pi*2;
    }
    if(dx<0)
    {
        return pi+atan(dy/dx);
    }
    if(dy>0) return pi/2;
    return 3*pi/2;
}
bool dmm(point a,point b)
{
    return(a.x==b.x&&a.y==b.y);
}
double dist(point a,point b)
{
    return (double)sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool ok(point a,point b,point c)
{
    if(dist(a,b)+dist(a,c)==dist(b,c)) return 1;
    return 0;
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
bool cmp(point a,point b)
{
    double g1=goc(dm,a);
    double g2=goc(dm,b);
    if(g1!=g2) return (g1<g2);
    return (dist(dm,a)<dist(dm,b));
}
bool ktra(point a,point b,point c,point d)
{
    int d1,d2,d3,d4;
    d1=ccw(a,b,c);
    d2=ccw(a,b,d);
    d3=ccw(c,d,a);
    d4=ccw(c,d,b);
    if(d1!=0&&d2!=0)
    {
        if((d1*d2<0)&&(d3*d4<0))
        {
            return 1;
        }
        else return 0;
    }
    else
    {
        int dem=0;
        if(ok(c,a,b)) dem++;
        if(ok(d,a,b)) dem++;
        if(ok(a,c,d)) dem++;
        if(ok(b,c,d)) dem++;
        if(dmm(a,c)) dem--;
        if(dmm(a,d)) dem--;
        if(dmm(b,c)) dem--;
        if(dmm(b,d)) dem--;
        if(dem==1||dem==2) return 1;
        return 0;
    }
}
double S(int u,int v)
{
    double s=0;
    vector<point> dmm;
    fu(i,u,v)
    dmm.push_back(p[i]);
    dmm.push_back(p[u]);
    int x=dmm.size();
    fu(i,0,x-2)
    {
        s+=(dmm[i+1].y+dmm[i].y)*(dmm[i+1].x-dmm[i].x);
    }
    s=abs(s)/2;
    return s;
}
void cd(double x)
{
    int k=x;
    cout<<k<<".";
    if(x==double(k)) cout<<"0000";
    else
    cout<<int(x*double(10000.00))%10000;
    cout<<" ";
}
void enter()
{
    cin>>n;
    fu(i,1,n)
    cin>>p[i].x>>p[i].y;
}
void solve()
{
    fu(p1,1,n-1)
    fu(p2,p1+2,n)
    {
        bool tm=0;
        fu(i,1,n-1)
        {
            int j=i+1;
            if(!ktra(p[i],p[j],p[p1],p[p2])) tm=1;
        }
        if(tm==1) v.push_back({p1,p2});
    }
    smax=S(1,n);
    res=oo;
    for(auto i:v)
    {
        double ss=S(i.fi,i.se);
        res=min(res,abs(smax-(2*ss)));
    }
    cd(res);
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    #endif // ONLINE_JUDGE
    enter();
    solve();
    cerr<<"\ntime: "<<clock()*1000/CLOCKS_PER_SEC<<"ms";
}
