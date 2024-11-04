#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
int l[N][N];
string s;
int n;
bool ok(string s)
{
    n=size();
    int ok1=true;
    for(int i=0;i<=n/2;i++)
    {
        if(s[i]!=s[n-i-1]) {ok1=false;break;}
    }
    return ok1;
}
main()
{
    cin>>s;
    n=s.size();
    s="+"+s;
    for(int i=1;i<=n;i++) l[i][i]=1;
    for(int i=1;i<n;i++) if(s[i]==s[i+1]) l[i][i+1]=1;
    for(int j=3;j<=n;j++)
        for(int i=j-2;i>=1;i--)
    {
        if(s[i]==s[j]) l[i][j]=l[i+1][j-1];
        else l[i][j]=0;
    }
    cout<<l[1][n];
}
