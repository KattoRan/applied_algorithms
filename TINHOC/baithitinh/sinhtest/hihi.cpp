#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
int n,a[N];
long long t,s,res;
int l[1000007];
void read(int &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-')
    {
        c=getchar();
        tam=-1;
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("expression.inp","r",stdin);
    freopen("expression.ans","w",stdout);
    read(n);
    for(int i=1;i<=n;i++) read(a[i]),t+=a[i];
    s=t/2;
    for(int i=1; i<=s; i++)
        l[i]=0;
    l[0]=1;
    for(int i=1; i<=n; i++)
        for(int j=s; j>=a[i]; j--)
            if(l[j-a[i]]==1&&l[j]==0) l[j]=1;
    int m=s;
    while(l[m]==0)
        m--;
    res=t-2*m;
//    cout<<res<<'\n';
    int cc=(t-res)/2;
    cout<<1ll*cc*(t-cc);
    cerr<<1ll*cc*(t-cc);
}
