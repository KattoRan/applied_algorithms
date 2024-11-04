#include<bits/stdc++.h>
#define fu(i,d,c) for(int i=d;i<=c;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define point pair<double,double>
#define x first
#define y second
#define double long double
using namespace std;
//typedef struct point{int x;int y;};
int n,m;
int q;
point k1[1005];
point k2[1000];
int kq=1;
map<point,int> s;
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
    if(d!=0)
    {
        return {(double) dx/d,(double)dy/d};

    }

    return {-1,-1};
}
main()
{
    #define NAME "cat"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
    cin>>m>>n;
    cin>>q;
    fu(i,1,q)
    {
        cin>>k1[i].x>>k1[i].y;
        cin>>k2[i].x>>k2[i].y;
    }
    fu(i,1,q)
    {
        s.clear();
        fu(j,1,i-1)
        {
            point tg=gd(k1[i],k2[i],k1[j],k2[j]);


            if(tg.x>0&&tg.x<m&&tg.y>0&&tg.y<n)
            {
                s[tg]++;
            }
        }
        kq+=s.size()+1;
    }
    cout<<kq;
    return 0;
}
