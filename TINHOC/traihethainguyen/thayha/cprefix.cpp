#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
string s;
int n,k,d;
int f[maxn];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("cprefix.inp","r",stdin);
    //freopen("cprefix.out","w",stdout);
    cin>>s;
    n=s.size();
    s="="+s;
    for(int i=1;i<=n;i++) f[i]=1;
    int p[n];
    p[1]=0;
    for(int i=2;i<=n;i++)
    {
        while(k>0&&s[i]!=s[k+1]) k=p[k];
        if(s[i]==s[k+1]) k++;
        p[i]=k;
    }
    /*for(int x=n;x>=1;x--)
        f[p[x]]+=f[x];
    for(int i=1;i<=n;i++) cout<<f[i]<<" ";*/
    for(int i=1;i<=n;i++) cout<<p[i]<<" ";
}
