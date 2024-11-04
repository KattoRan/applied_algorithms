#include<bits/stdc++.h>
using namespace std;
const int oo=1e9+7;
const int maxn=1e3+7;
int cx[maxn],c[maxn][maxn],x[maxn];
int n,s,m;
void nhap()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a,b,d;
        cin>>a>>b>>d;
        c[a][b]=c[b][a]=d;
    }
}
int kt(int i)
{
    int mm=oo,vt;
    for(int j=1; j<=n; j++)
        if(cx[j]==0&&c[x[i]][j]&&mm>c[x[i]][j])
            mm=c[x[i]][j],vt=j;
    return vt;
}
void thamlam()
{
    x[1]=1;
    cx[1]=1;
    int i=1;
    while(i<=n)
    {
        int j;
        j=kt(i);
        i++;
        x[i]=j;
        cx[j]=1;
               s+=c[x[i-1]][x[i]];
    }
    s+=c[x[n]][1];

}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     freopen("dulich.inp","r",stdin);
     freopen("dulich.out","w",stdout);
    nhap();
    thamlam();
    cout<<s<<endl;
    for(int i=1; i<=n; i++)
        cout<<x[i]<<" ";
    cout<<"1";
    return 0;
}
