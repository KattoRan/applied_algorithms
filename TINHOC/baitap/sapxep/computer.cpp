#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int n,cost[maxn],vet[maxn],d,tr[maxn],vt[maxn];
struct quanli {int a;int b;int c;};
quanli q[1001];
void quicksort(int l,int r)
{
    int i=l,j=r;
    int x=q[(i+j)/2].a;
    while(i<=j)
    {
        while(q[i].a<x) i++;
        while(q[j].a>x) j--;
        if(i<=j) {swap(q[i],q[j]);swap(vt[i],vt[j]);
        i++;
        j--;}
    }
    if(i<r) quicksort(i,r);
    if(j>l) quicksort(l,j);
}
int main()
{ /* ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("computer.INP","r",stdin);
    freopen("computer.OUT","w",stdout);*/
    cin>>n;
    for(int i=1;i<=n;i++) {cin>>q[i].a>>q[i].b>>q[i].c;vt[i]=i;}
    quicksort(1,n);
    for(int i=1;i<=n;i++) cost[i]=q[i].c,tr[i]=i;
    for(int i=2;i<=n;i++)
       for(int j=i-1;j>=1;j--)
          {if(q[i].a>q[j].b) {cost[i]=max(cost[j]+q[i].c,cost[i]);
                                if(cost[i]==cost[j]+q[i].c) tr[i]=j;}}
    int costm=cost[1],vtm=1;
    for(int i=2;i<=n;i++) {if(cost[i]>costm) costm=cost[i],vtm=i;}
    d=1;
    vet[d]=vt[vtm];
    while(tr[vtm]!=vtm)
    {
        d++;vet[d]=vt[tr[vtm]];vtm=tr[vtm];
    }
    cout<<d<<" "<<costm<<'\n';
    for(int i=d;i>=1;i--) cout<<vet[i]<<" ";
    return 0;
}
