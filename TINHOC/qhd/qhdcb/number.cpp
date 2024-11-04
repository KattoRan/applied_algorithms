#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int n,m;
string x,y;
string l[maxn][maxn];
string max2so(string a,string b)
{
    if(a==""&&b=="") return "";
    if(a==""&&b!="") return b;
    if(a!=""&&b=="") return a;
    while(a.size()<b.size()) a="0"+a;
    while(b.size()<a.size()) b="0"+b;
    if(a<b) return b;
    else return a;
}
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.inp","r",stdin);
    freopen("number.out","w",stdout);
    cin>>x>>y;
    m=x.size();
    n=y.size();
    x="+"+x;
    y="+"+y;
}
void tinh()
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
    {
        if(x[i]==y[j]) l[i][j]=l[i-1][j-1]+x[i];
        else l[i][j]=max2so(l[i-1][j],l[i][j-1]);
    }
}
int main()
{
    init();
    tinh();
    cout<<l[m][n];
    return 0;
}
