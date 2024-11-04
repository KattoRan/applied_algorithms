#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
int c,n,k;
int a[maxn];
long g[maxn],s[maxn];
void trace(long long k)
{
    int tmp=n;
    while(k>1)
    {
        if(k==g[tmp])
        {
            cout<<tmp<<" ";
            tmp=0;
            break;
        }
        for(int i=1; i<=tmp; ++i)
            if(k>g[tmp-i])
                k-=g[tmp-i];
            else
            {
                cout<<i<<" ";
                tmp-=i;
                break;
            }
    }
    while(tmp--)
    {
        cout<<1<<" ";
    }
    cout<<endl;
}
void cal(int a[],int length)
{
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+g[i];
        if(s[i]>1e17) s[i]=1e17;
    }
    long long stage=0;
    int nc=n;
    for(int i=1;i<=length;i++)
    {
        long long tmp=s[nc-1]-s[nc-(a[i]-1)-1];
        stage+=tmp;
        nc-=a[i];
    }
   // cout<<stage+1<<endl;
}
int main()
{
    cin>>c;
    cin>>n;
    if(c==1)
        cin>>k;
    else
    {
        int x;
        int len=0;
        while(cin>>x)
        {
            a[len++]=x;
        }
    }
    long long sum=1;
    for(int i=1;i<=n;i++)
    {
        g[i]=sum;
        sum=sum+g[i];
        if(sum>1e17) sum=1e17;
    }
    trace(k);
    cal(a,n);

}
