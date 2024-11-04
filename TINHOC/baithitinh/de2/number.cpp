#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define task "number"
using namespace std;
const int N=207;

typedef long long ll;
string x,y;
string l[N][N];

string max2so(string a,string b)
{
    if(a.size()<b.size()) return b;
    if(b.size()<a.size()) return a;
    if(a<b) return b;
    else return a;
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
    fu(i,1,m)
    fu(j,1,n)
    {
        if(x[i]==y[j]) l[i][j]=l[i-1][j-1]+x[i];
        else l[i][j]=max2so(l[i-1][j],l[i][j-1]);
        while(l[i][j][0]=='0'&&l[i][j].size()>1) l[i][j].erase(0,1);
    }
    cout<<l[m][n];
}
