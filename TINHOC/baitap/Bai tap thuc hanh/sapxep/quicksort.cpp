#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int n,a[maxn];
void quicksort(int a[],int l,int r)
{   if(l<=r)
    {int i=l,j=r;
    int x=a[(i+j)/2];
    while(i<=j)
    {
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        if(i<=j) {swap(a[i],a[j]);
        i++;
        j--;}
    }
    if(i<r) quicksort(a,i,r);
    if(j>l) quicksort(a,l,j);}
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    quicksort(a,1,n);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}
