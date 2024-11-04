#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
string a,b,s;
int k,res,d;
int kq[maxn];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("foundstring.inp","r",stdin);
    freopen("foundstring.out","w",stdout);
    cin>>a>>b;
    int m=a.size();
    s=a+"*";
    s=s+b;
    int n=s.size();
    s="="+s;
    int p[n];
    p[1]=0;
    for(int i=2;i<=n;i++)
    {
        while(k>0&&s[i]!=s[k+1]) k=p[k];
        if(s[i]==s[k+1]) k++;
        p[i]=k;
    }
    for(int i=1;i<=n;i++)
      if(p[i]==m) d++,kq[d]=i-2*m;
    cout<<d<<'\n';
    for(int i=1;i<=d;i++) cout<<kq[i]<<" ";
    return 0;
}
