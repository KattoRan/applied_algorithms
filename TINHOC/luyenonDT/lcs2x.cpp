#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define task "lcs2x"
using namespace std;
const int N=1e3+507;
typedef long long ll;
int n,m,res,t,res1,t1;
int c[N],a[N],b[N],d[N];
int f[N][N];
void xuli()
{
    cin>>m>>n;
    fu(i,1,m) cin>>a[i];
    fu(i,1,n) cin>>b[i];
    memset(c,0,sizeof(c));
    fu(i,1,m)
    {
        res1=0;
        fu(j,1,n)
        {
            t1=res1;
            if(2*b[j]<=a[i]) res1=max(res1,c[j]);
            if(a[i]==b[j]) c[j]=max(c[j],t1+1);
        }
    }
    res=0;
    fu(i,1,n) res=max(res,c[i]);
    cout<<res<<'\n';
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>t;
    while(t--) xuli();
}
