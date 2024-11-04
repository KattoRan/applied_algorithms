#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int n,vet[maxn],d,tr[maxn],vt[maxn],dd[maxn];
struct quanli {int s;int f;};
quanli q[1001];
void quicksort(int l,int r)
{
    int i=l,j=r;
    int x=q[(i+j)/2].f;
    while(i<=j)
    {
        while(q[i].f<x) i++;
        while(q[j].f>x) j--;
        if(i<=j) {swap(q[i],q[j]);swap(vt[i],vt[j]);
        i++;
        j--;}
    }
    if(i<r) quicksort(i,r);
    if(j>l) quicksort(l,j);
}
int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("activity.INP","r",stdin);
    freopen("activity.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {cin>>q[i].s>>q[i].f;vt[i]=i;}
    quicksort(1,n);
    for(int i=1;i<=n;i++) tr[i]=i,dd[i]=1;
    for(int i=2;i<=n;i++)
       for(int j=i-1;j>=1;j--)
         if(q[i].s<=q[j].f) dd[i]++;
    for(int i=2;i<=n;i++)
       for(int j=i-1;j>=1;j--)
         if(q[i].s<=q[j].f) tr[j]=i;
    int ddm=dd[1],vtm=1;
    for(int i=1;i<=n;i++) if(dd[i]>ddm) ddm=dd[i],vtm=i;
    d=1;
    vet[d]=vt[vtm];
    while(tr[vtm]!=vtm)
    {
        d++;vet[d]=vt[tr[vtm]];vtm=tr[vtm];
    }
    cout<<d<<"\n";
    for(int i=d;i>=1;i--) cout<<vet[i]<<" ";
    return 0;
}
