#include <bits/stdc++.h>
using namespace std;
const int maxn =10003;
int m,n,sum,t,l[maxn][maxn],truoc[maxn],a[maxn],d[maxn];
int res;
void kt()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=n; i++)
        sum+=a[i];
    t= sum/2;
}
void tinh()
{
    for(int i=1; i<=t; i++)
    {
        d[i]=0;
        truoc[i]=0;
    }
    d[0]=1;
    for(int i=1; i<=n; i++)
        for(int j=t; j>=a[i]; j--)
            if(d[j-a[i]] ==1&&d[j]==0)
            {
                d[j]=1;
                truoc[j]=i;
            }
}
void timkq()
{
    m=sum/2;
    while(d[m]==0)
        m--;
    res =sum-2*m;
    cout<<res;
    cout<<" "<<m<<" "<<sum-m<<endl;
    int kq[maxn],s;
    for(int i=1; i<=n; i++)
        kq[i]=0;
    kq[truoc[m]] =1;
    s=m;
    while(truoc[s]>0)
    {
        s=s-a[truoc[s]];
        kq[truoc[s]]=1;
    }
    for(int i=1 ; i<=n; i++)
        if(kq[i]==1)
            cout<<i<<" ";
    cout<<endl;
    for(int i=1; i<=n; i++)
        if(kq[i]!=1)
            cout<<i<<" ";
}
int main()
{
    //freopen("keo.inp","r",stdin);
    //freopen("keo.out","w",stdout);
    kt();
    tinh();
    timkq();
}


