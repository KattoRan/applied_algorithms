#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int d[maxn],vt[maxn],n,t;
void quicksort(int l,int r)
{
    int i=l,j=r;
    int x=d[(i+j)/2];
    while(i<=j)
    {
        while(d[i]<x) i++;
        while(d[j]>x) j--;
        if(i<=j) {swap(d[i],d[j]);swap(vt[i],vt[j]);
        i++;
        j--;}
    }
    if(j>l) quicksort(l,j);
    if(i<r) quicksort(i,r);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("coc.INP","r",stdin);
    freopen("coc.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>d[i],vt[i]=i;
    quicksort(1,n);
    t=d[n]-d[1];
    cout<<t<<'\n';
    for(int i=1;i<=n;i++)  cout<<vt[i]<<" ";
    return 0;

}
