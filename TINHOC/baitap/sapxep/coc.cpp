#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
int a[maxn],vt[maxn],n,t;
void quicksort(int l,int r)
{
    int i=l,j=r;
    int x=a[(i+j)/2];
    while(i<=j)
    {
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        if(i<=j) {swap(a[i],a[j]);swap(vt[i],vt[j]);
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
    for(int i=1;i<=n;i++) cin>>a[i],vt[i]=i;
    quicksort(1,n);
    t=a[n]-a[1];
    cout<<t<<'\n';
    for(int i=1;i<=n;i++)  cout<<vt[i]<<" ";
    return 0;

}
