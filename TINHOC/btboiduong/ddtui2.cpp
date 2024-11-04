#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
const int maxm=1e8+7;
int m,n,l[maxm];
int w[maxn],v[maxn],a[maxn];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i]>>a[i];
    for(int j=1;j<=m;j++) l[j]=0;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=0;j--)
    {
        if(j-w[i]>=0)
        for(int k=1;k<=a[i];k++)
           {
            if(j-w[i]*k>=0) l[j]=max(l[j],v[i]*k+l[j-w[i]*k]);
            else break;
           }
    }
    cout<<l[m];
}



