#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int d[maxn],c[maxn],n,t;
void countsort(int a[],int n)
{   int b[maxn];
    for(int i=1;i<=n;i++) b[i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
            if(a[i]>a[j]) b[i]++;
            else b[j]++;
    }
    for(int i=1;i<=n;i++) c[b[i]]=i;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("coc.INP","r",stdin);
    freopen("coc.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>d[i];
    countsort(d,n);
    t=d[n]-d[1];
    cout<<t<<'\n';
    for(int i=1;i<=n;i++) cout<<c[i]<<" ";
    return 0;

}
