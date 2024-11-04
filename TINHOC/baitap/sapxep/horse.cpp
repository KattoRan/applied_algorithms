#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int a[maxn],b[maxn],n,d=0;
void quicksort(int l,int r,int d[])
{   if(l<=r)
    {int i=l,j=r;
    int x=d[(i+j)/2];
    while(i<=j)
    {
        while(d[i]<x) i++;
        while(d[j]>x) j--;
        if(i<=j) {swap(d[i],d[j]);
        i++;
        j--;}
    }
    if(i<r) quicksort(i,r,d);
    if(j>l) quicksort(l,j,d);}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("horse.INP","r",stdin);
    freopen("horse.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    quicksort(1,n,a);
    quicksort(1,n,b);
    for(int i=1;i<=n;i++)
        for(int j=d+1;j<=n;j++) if(a[i]>b[j]) {d++;break;}
                                else {break;}
    cout<<d;
    return 0;
}
