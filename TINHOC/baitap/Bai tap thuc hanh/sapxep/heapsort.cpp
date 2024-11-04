#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int a[maxn],n;
void heapi(int a[],int n,int i)
{
    int vt=i;
    int l=i*2,r=i*2+1;
    if(l<=n&&a[i]<a[l]) vt=l;
    if(r<=n&&a[vt]<a[r]) vt=r;
    if(vt!=i) {swap(a[i],a[vt]);heapi(a,n,vt);}
}
void heapsort(int a[],int n)
{
    for(int i=(int)n/2;i>=1;i--) heapi(a,n,i);
    for(int i=n;i>=1;i--) {swap(a[1],a[i]);heapi(a,i-1,1);}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("heapsort.INP","r",stdin);
    freopen("heapsort.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    heapsort(a,n);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}
