#include<bits/stdc++.h>
#define up(i,d,n) for(int i=d;i<=n;i++)
using namespace std;
const int maxn=1e3+7;
int l[maxn][maxn],d[maxn];
string s;
int n;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("palin4.inp","r",stdin);
    //freopen("palin4.out","w",stdout);
    cin>>s;
    n=s.size();
    s="+"+s;
}
void tinh()
{
    up(i,1,n) l[i][i]=1;
    for(int j=2;j<=n;j++)
    for(int i=j-1;i>=1;i--)
    {
        if(s[i]==s[j])l[i][j]=l[i+1][j-1]+2;
        else l[i][j]=max(l[i][j-1],l[i+1][j]);
    }
    cout<<l[1][n]<<" ";

    /*int i=1,j=n;
    while(l[i][j]!=0)
    {
        if(s[i]==s[j]) d[i]=1,d[j]=1,i++,j--;
        else
            if(l[i][j]==l[i+1][j]) i++;
            else j--;
    }*/
}
int main()
{
    init();
    tinh();
    for(int i=1;i<=n;i++)
        if(d[i]==1) cout<<s[i];
    return 0;
}
