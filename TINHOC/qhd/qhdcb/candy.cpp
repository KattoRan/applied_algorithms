#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+7;
long long sum,s;
long long n,a[maxn],l[maxn],res,truoc[maxn];
void init()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     freopen("candy.inp","r",stdin);
     freopen("candy.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
}
void tinh()
{
    sum=0;
    for(int i=1; i<=n; i++)
        sum+=a[i];
    s=sum/2;
    for(int i=1; i<=s; i++)
        l[i]=0,truoc[i]=0;
    l[0]=1;
    for(int i=1; i<=n; i++)
        for(int j=s; j>=a[i]; j--)
            if(l[j-a[i]]==1&&l[j]==0) l[j]=1,truoc[j]=i;

        }
void timkq()
{
    int m=s;
    while(l[m]==0)
        m--;
    res=sum-2*m;
    cout<<res;
}
int main()
{
    init();
    tinh();
    timkq();
    return 0;
}
