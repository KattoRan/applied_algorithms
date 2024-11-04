#include<bits/stdc++.h>
#define task "tea"
using namespace std;
const int maxn=1e6+7;
typedef long long ll;
int n,m,d1,d2,d3,res;
int t[maxn],l[maxn],r[maxn];
int x[maxn],xo[maxn];
string kq1,kq2;
void cnkl()
{
    d3=0;
    for(int i=1; i<=m; i++)
    {
        d1=0;
        d2=0;
        for(int j=1; j<=n; j++)
        {
            if(l[i]<=t[j]&&t[j]<=r[i])
            {
                if(x[j]==1)
                    d1++;
                if(x[j]==0)
                    d2++;
            }
        }
        if(abs(d1-d2)<=1) d3++;
    }
    if(d3>res){res=max(res,d3); for(int i=1;i<=n;i++) xo[i]=x[i];}

}
void Try(int i)
{
    for(int j=0; j<=1; j++)
    {
        x[i]=j;
        if(i==n)
        {
            kq1="";
            cnkl();
        }
        else
            Try(i+1);
    }
}
main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     freopen("tea.inp","r",stdin);
     freopen("tea.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>t[i];
    for(int i=1; i<=m; i++)
        cin>>l[i]>>r[i];
    res=0;
    Try(1);
    cout<<res<<'\n';
   for(int i=1;i<=n;i++) {if(xo[i]==1) cout<<'S'; if(xo[i]==0) cout<<'C';}

}
