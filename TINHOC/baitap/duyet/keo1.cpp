#include <bits/stdc++.h>
using namespace std;
const int maxn=50;
int n,kiluc;
int a[maxn],t1,t2,a0[maxn],sum[maxn];
int x[maxn],vt[maxn],x0[maxn];
void quicksort(int l,int r)
{
    int i=l,j=r;
    int x=a[(i+j)/2];
    while(i<=j)
    {
        while(a[i]>x) i++;
        while(a[j]<x) j--;
        if(i<=j) {swap(a[i],a[j]);swap(vt[i],vt[j]);
        i++;
        j--;}
    }
    if(j>l) quicksort(l,j);
    if(i<r) quicksort(i,r);
}
void init()
{
    cin>>n;
    for(int i=1;i<=n;i++) {cin>>a[i]; vt[i]=i;}
    quicksort(1,n);
    sum[n]=a[n];
    for(int i=n-1;i>=1;i--) sum[i]=sum[i+1]+a[i];
    t1=t2=0;
    kiluc=10000000;
}
void cnkl()
{
    if(abs(t1-t2)<kiluc)
        {kiluc=abs(t1-t2);
         for(int i=1;i<=n;i++) x0[i]=x[i];}
}
void chia(int i)
{
    for(int j=2;j>=1;j--)
        { x[i]=j;
          if(j==1) t1=t1+a[i];
          if(j==2) t2=t2+a[i];
          if(i==n) cnkl();
          else
            if(sum[i]>abs(t1-t2)) chia(i+1);
          if(j==2) t2=t2-a[i];
          if(j==1) t1=t1-a[i];
        }
}
int main()
{
   /* ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("KEO.inp","r",stdin);
    freopen("KEO.out","w",stdout);*/
    init();
    chia(1);
    int t1,t2;
    t1=t2=0;
    for(int i=1;i<=n;i++) if(x0[i]==1)t1 += a[i];
    for(int i=1;i<=n;i++) if(x0[i]==2)t2 += a[i];
    cout<<kiluc<<" "<<t1<<" "<<t2<<'\n';
    for(int i=1;i<=n;i++) if(x0[i]==1) cout<<vt[i]<<" ";
    cout << '\n';
    for(int i=1;i<=n;i++) if(x0[i]==2) cout<<vt[i]<<" ";
    return 0;
}


