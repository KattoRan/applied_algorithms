#include<bits/stdc++.h>
#define mn 10000000
using namespace std;
string s,t;
int f[mn],g[mn],l[mn];
int n,m,cnt;
struct tv
{
    int x,l,r;
} res[mn];
bool cmp(tv a,tv b)
{
    if(a.x!=b.x)
        return a.x>b.x;
    if(a.l!=b.l)
        return a.l<b.l;
    if(a.r!=b.r)
        return a.r<b.r;
}
int main()
{
    cin>>s>>t;
    m=s.size();
    n=t.size();
    s=" "+s;
    t=" "+t;
    for(int i=1;i<=m;i++)
    l[i]=l[i-1]+s[i]-48;
    if(s==t)
    {
        cout<<1<<" "<<1;
        return 0;
    }
    for(int i=1;i<min(n,m);i++)
    if(s[i]==t[i])
        f[i]=i;
    else
        break;
    for(int i=1;i<min(n,m);i++)
    if(s[m-i+1]==t[n-i+1])
        g[n-i+1]=m-i+1;
    else
        break;
    g[n+1]=m+1;
    for(int i=0;i<=n;i++)
    {
        int d=0;
        for(int dem=1;dem<=7;dem++)
        {
            d=d*10+(t[i+dem]-48);
            int c=l[g[i+dem+1]-1]-l[f[i]];
            if((f[i]||i==0)&&g[i+dem+1]&&c==d)
                res[cnt++]= {g[i+dem+1]-f[i],f[i]+1,g[i+dem+1]-1};
        }
    }
    sort(res+1,res+1+cnt,cmp);
    cout<<res[1].l<<" "<<res[1].r;
    return 0;
}

