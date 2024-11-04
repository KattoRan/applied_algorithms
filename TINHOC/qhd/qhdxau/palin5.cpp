#include<bits/stdc++.h>
#define up(i,d,n) for(int i=d;i<=n;i++)
using namespace std;
const int maxn=1e3+7;
bool l[maxn][maxn];
string s;
int n,f[maxn];
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("palin5.inp","r",stdin);
    freopen("palin5.out","w",stdout);
    cin>>s;
    n=s.size();
    s="+"+s;
}
void tinh()
{
    up(i,1,n) f[i]=i;
    up(i,1,n) l[i][i]=1;
    up(i,1,n-1) if(s[i]==s[i+1]) l[i][i+1]=1;
    up(j,3,n)
    up(i,1,j-2)
    {
        if(s[i]==s[j])l[i][j]=l[i+1][j-1];
        else l[i][j]=0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
    {
        if(l[j][i]) f[i]=min(f[i],f[j-1]+1);
    }
}
int main()
{
    init();
    tinh();
    cout<<f[n]<<'\n';
    return 0;
}
