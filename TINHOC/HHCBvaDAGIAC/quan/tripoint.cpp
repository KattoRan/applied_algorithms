#include<bits/stdc++.h>
#define fu(i,d,c) for(int i=d;i<=c;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define point pair<double,double >
#define x first
#define y second
#define pb push_back
using namespace std;
int n;
int d;
point k[10005];
int res=0,dem;
vector<pair<int,int  > > kq;
vector<double> b;
long long ss;
void mons(point a,point b,double &dx,double &dy )
{
    dx=b.x-a.x;
    dy=b.y-a.y;
}
int main()
{
#define NAME "tripoint"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
    cin>>n;
    int tg=0;
    fu(i,1,n)
    {
        cin>>k[i].x>>k[i].y;
    }
    fu(i,1,n-1)
    {
        vector<double> a;
        tg=0;
        fu(j,i+1,n)
        {

            double dx=0;
            double dy=0;
            mons(k[i],k[j],dx,dy);
            if(dx==0)tg++;
            else a.pb(dy/dx);
        }
        res+=(tg*(tg-1)/2);
        int dem=1;
        sort(a.begin(),a.end());
        a.pb(INT_MAX);
        for(int i=0; i<a.size()-1; i++)
        {

            if(a[i]==a[i+1])dem++;
            else
            {
                res+=(dem*(dem-1)/2);
                dem=1;
            }
        }
    }
    cout<<res;
}
