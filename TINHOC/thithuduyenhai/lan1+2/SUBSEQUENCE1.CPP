#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
int n,a[maxn],d,x[maxn],k;
string s[1001]="";
void khoitao()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    d=0;
}
void ghinhan()
{
    d++;
    for(int i=1; i<=n; i++)
        if(x[i]==1)
            s[d]=s[d]+char(a[i]+48)+' ';
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
    khoitao();
    Try(1);
    sort(s+1,s+d+1);
    for(int i=2;i<=d;i++) if(s[i]!=s[i-1]) k++;
    cout<<k;
    return 0;
}
