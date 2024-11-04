#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define task "number2"
using namespace std;
const int N=1e3+7;

typedef long long ll;
string x,y;
string f[N][N];
string min2so(string a,string b)
{
    if(a.size()<b.size()) return a;
    if(b.size()<a.size()) return b;
    if(a<b) return a;
    else return b;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>x>>y;
    int m=x.size();
    int n=y.size();
    x="="+x;
    y="="+y;
    fu(i,1,n)
    f[0][i]=f[0][i-1]+y[i];
    fu(i,1,m)
    f[i][0]=f[i-1][0]+x[i];
    fu(i,1,m)
    fu(j,1,n)
    {
        if(x[i]==y[j]) f[i][j]=f[i-1][j-1]+x[i];
        else
            {
             string c=min2so(f[i-1][j],f[i][j-1]);
             if(c==f[i-1][j]) f[i][j]=c+x[i];
             else f[i][j]=c+y[j];}

    }
    while(f[m][n][0]=='0'&&f[m][n].size()>1) f[m][n].erase(0,1);
    cout<<f[m][n];
}
