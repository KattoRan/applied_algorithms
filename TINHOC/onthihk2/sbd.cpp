#include<bits/stdc++.h>
using namespace std;
const int maxn=10;
string s,temp;
string x0[1000000],a0[1000000];
char x[maxn],b[maxn];
int d,n,k;
bool cx[maxn];
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sbd.inp","r",stdin);
    freopen("sbd.out","w",stdout);
    cin>>s;
    sort(s.begin(),s.end());
    n=s.size();
    for(int i=0;i<=n-1;i++)cx[i]=1;
    k=0;d=0;
    temp="";
}
void ghinhan()
{
        d++;
        for(int i=1;i<=n;i++) temp=temp+x[i];
        x0[d]=temp;
        temp="";
}
void Try(int i)
{
    for(int j=0;j<=n-1;j++)
       if(cx[j])
    {
        x[i]=s[j];
        cx[j]=0;
        if(i==n) ghinhan();
        else Try(i+1);
        cx[j]=1;
    }
}
int main()
{
    init();
    Try(1);
    sort(x0+1,x0+d+1);
    for(int i=2;i<=d;i++) if(x0[i]!=x0[i+1]&&x0[i]==x0[i-1]) k++,a0[k]=x0[i];
    cout<<k<<'\n';
    for(int i=1;i<=k;i++) cout<<a0[i]<<'\n';
    return 0;
}

