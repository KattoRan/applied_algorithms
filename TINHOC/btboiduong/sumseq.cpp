#include<iostream>
#include<fstream>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=1e6+7;
int a[maxn],amax[maxn],amin[maxn],n,kl,kq,bt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sumseq.INP","r",stdin);
    freopen("sumseq.OUT","w",stdout);
    cin>>n;kq=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    amax[1]=a[1];
    amin[3]=a[3];
    for(int i=2;i<=n-2;++i) amax[i]=max(amax[i-1],a[i]);
    for(int k=4;k<=n;++k) amin[k]=min(amin[k-1],a[k]);
    for(int j=2;j<=n-1;j++)
    {
        bt=2*amax[j-1]+3*a[j]-4*amin[j+1];
        kq=max(bt,kq);
    }
    cout<<kq;
    return 0;
}
