#include<bits/stdc++.h>
using namespace std;
const int maxn=10;
int n,k[maxn],d,x[maxn];
string s[1001]="";
void khoitao()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        k[i]=i;
    d=0;
}
void ghinhan()
{
    d++;
    for(int i=1; i<=n; i++)
        if(x[i]==1)
            s[d]=s[d]+char(k[i]+48)+' ';
}
void Try(int i)
{
    for(int j=1; j>=0; j--)
    {
        x[i]=j;
        if(i==n)
            ghinhan();
        else
            Try(i+1);
    }
}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     freopen("only.inp","r",stdin);
     freopen("only.out","w",stdout);
    khoitao();
    Try(1);
    sort(s+1,s+d+1);
    cout<<d<<endl;
    for(int i=1; i<=d; i++)
        cout<<s[i]<<endl;
    return 0;
}

