#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e3+7;
int n;
string s;
int l[N][N];
main()
{
    #define name "robot"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(name".inp","r",stdin);
	freopen(name".out","w",stdout);
    cin>>n;
    cin>>s;
    s='+'+s;
    fu(i,1,n) l[i][i]=1;
    fu(i,1,n-1) if(s[i]==s[i+1]) l[i][i+1]=1;
    fu(j,3,n)
    fu(i,1,j-2)
    {
        if(s[i]==s[j]) l[i][j]=l[i+1][j-1];
        else l[i][j]=0;
    }
    if(l[1][n]==1) cout<<"CO";
    else cout<<"KHONG";
}
