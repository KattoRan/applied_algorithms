#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int a[maxn],n;
void selectionsort(int a[],int n)
{   for(int i=1;i<n;i++)
    {   int vt=i;
        for(int j=i+1;j<=n;j++)
            if(a[vt]>a[j]) vt=j;
        if(vt!=i) swap(a[i],a[vt]);
    }
}
void insertsort(int a[],int n)
{    for(int i=2;i<=n;i++)
    {
        int k=a[i];
        int j=i-1;
        while(a[j]>k&&j>0) {a[j+1]=a[j],j--;}
        a[j+1]=k;
    }
}
void bubblesort(int a[],int n)
{
    for(int i=n;i>=2;i--)
        for(int j=1;j<=i-1;j++)
          if(a[j]>a[j+1]) swap(a[j],a[j+1]);
}
void countsort(int a[],int n)
{   int b[maxn],c[maxn];
    for(int i=1;i<=n;i++) b[i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
            if(a[i]>a[j]) b[i]++;
            else b[j]++;
    }
    for(int i=1;i<=n;i++) c[b[i]]=a[i];
    for(int i=1;i<=n;i++) a[i]=c[i];
}
void ketqua(int a[],int n)
{
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sapxep.INP","r",stdin);
    freopen("sapxep.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int d;
    cin>>d;
    switch (d)
    {
        case 1 : selectionsort(a,n),ketqua(a,n);break;
        case 2 : insertsort(a,n),ketqua(a,n);break;
        case 3 : bubblesort(a,n),ketqua(a,n);break;
        case 4 : countsort(a,n),ketqua(a,n);break;
    }
    return 0;
}




