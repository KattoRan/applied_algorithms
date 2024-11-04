#include<bits/stdc++.h>
#define up(i,d,n) for(int i=d;i<=n;i++)
using namespace std;
const int maxn=1e3+7;
const int oo=1e9+7;
bool l[maxn][maxn];
string s;
int n,res,io,jo,j;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("palin3.inp","r",stdin);
    //freopen("palin3.out","w",stdout);
    cin>>s;
    n=s.size();
    s="+"+s;
}
void tinh()
{
    up(i,1,n) l[i][i]=1;
    up(i,1,n-1) if(s[i]==s[i+1]) l[i][i+1]=1;
    up(j,3,n)
    up(i,1,j-2)
    {
        if(s[i]==s[j])l[i][j]=l[i+1][j-1];
        else l[i][j]=0;
    }
    res=-oo;
    up(i,1,n)
    up(j,1,n)
    if(l[i][j]&&j-i+1>res)
    {
        res=j-i+1;
        io=i;
        jo=j;
    }
}
int main()
{
    init();
    tinh();
    cout<<res<<'\n';
    for(int i=io;i<=jo;i++) cout<<s[i];
    return 0;
}
