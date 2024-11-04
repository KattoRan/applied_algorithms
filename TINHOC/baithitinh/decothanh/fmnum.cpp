#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,s;
string res;
int f[N];
main()
{
    #define name "fmnum"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(name".inp","r",stdin);
	freopen(name".out","w",stdout);
    cin>>n>>s;
    res="";
    int m;
    m=n*9;
    if(s==m)
    {
        for(int k=1; k<=n; k++)
            res='9'+res;
    }
    else
    {
        for(int i=9;i>=1;i--)
        {
            while(s>i) res=char(i+48)+res,s-=i;
            if(s<=i&&res.size()!=0)
            {
                while(res.size()<n-1) res='0'+res;
                res=char(s+48)+res;
            }
            if(res.size()==n) break;
        }
    }
    cout<<res<<" ";
    for(int i=0;i<n;i++) f[i+1]=int(res[i]-48);
    for(int i=1;i<n;i++)
    {
        if(f[i]>1&&f[i]+f[i+1]-1<=9) {f[i+1]+=(f[i]-1);f[i]=1;}
        if(f[i+1]<9&&f[i]+f[i+1]-9>=0&&i>1) f[i]=f[i]+f[i+1]-9,f[i+1]=9;
        if(f[i]>0&&f[i]+f[i+1]<=9&&i>1) f[i+1]+=f[i],f[i]=0;
    }
    for(int i=1;i<=n;i++) cout<<f[i];
}
