#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
const int oo=101;
int x[maxn],x0[maxn],p[maxn],d[maxn];
int t,gia,n,kiluc,pmin,dmax,cantren,dem,tg;
bool cx[maxn];
void khoitao()
{
    cin>>n;gia=0;kiluc=0;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=1;i<=n;i++) cx[i]=1;
}
void cnkl()
{
        if(gia>kiluc) {kiluc=gia;
                       for(int i=1;i<=n;i++) x0[i]=x[i];}

}
void lap(int i)
{
    for(int j=1;j<=n;j++)
        if(cx[j])
    {
        x[i]=j;
        cx[j]=0;
        t=t+p[x[i]];
        if(t<=d[x[i]]) gia++;
        if(i==n) cnkl();
        else {dem=0,tg=t;pmin=-oo;dmax=oo;
              for(int k=i+1;k<=n;k++) {if(p[k]<pmin) pmin=p[k];
                                       if(d[k]>dmax) dmax=d[k];}
              for(int k=i+1;k<=n;k++) {tg+=pmin;
                                       if(tg<=dmax) dem++;}
              cantren=gia+dem;
              if(cantren>kiluc) lap(i+1);}
        if(t<=d[x[i]]) gia--;
        t-=p[x[i]];
        cx[j]=1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LICHDH.INP","r",stdin);
    freopen("LICHDH.OUT","w",stdout);
    khoitao();
    lap(1);
    cout<<kiluc<<endl;
    for(int i=1;i<=n;i++) cout<<x0[i]<<" ";
    return 0;
}

