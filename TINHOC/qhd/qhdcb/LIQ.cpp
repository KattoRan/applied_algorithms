#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int n,a[maxn],res,io,jo;
int truoc[maxn],l[maxn],kq[maxn];
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LIQ.inp","r",stdin);
    freopen("LIQ.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
}
void tinh()
{
    l[0]=0;l[1]=1;truoc[1]=0;io=1;
    for(int i=2;i<=n;i++)
    {
        jo=0;
        for(int j=i-1;j>=1;j--)
            if(a[j]<a[i]&&l[j]>l[jo]) jo=j;
        l[i]=l[jo]+1;
        truoc[i]=jo;
    }
    for(int i=1;i<=n;i++) if(l[i]>l[io]) io=i;
    res=l[io];
    for(int i=res;i>=1;i--)
        kq[i]=io,io=truoc[io];
}
int main()
{
    init();
    tinh();
    cout<<res<<'\n';
    for(int i=1;i<=res;i++) cout<<kq[i]<<" ";
    return 0;
}
