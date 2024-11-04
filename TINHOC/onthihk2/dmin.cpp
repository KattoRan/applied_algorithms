#include<bits/stdc++.h>
using namespace std;
const int oo=1e12+7;
const int maxn=1e6+7;
int n,a[maxn],cs1,cs2,k,cs,d;
long long s,sum[maxn],res;
    long long tong=0;
void xuli1()
{
    for(int i=1; i<=n; i++)
    {
        int j;
        j=lower_bound(sum+1,sum+n+1,s)-sum;
        cs1=j;
    }
    k=sum[cs1-1];
    for(int i=cs1; i<=n; i++)
    {
        int t;
        t=sum[i]-k;
        if(t>=s)
        {
            cs2=i;
            break;
        }
    }
    cout<<cs2-cs1;
}
void xuli2()
{
    int h=*max_element(a+1,a+n+1);
    if (h>=s)
        cout<<1;
    else
    {
        cs=oo;
        for(int i=1; i<n; i++)
        {
            int t=a[i];
            d=1;
            for(int j=i+1; j<=n; j++)
            {
                t=t+a[j];
                d++;
                if(t>=s)
                {
                    if(d<=cs)
                        cs=d;
                    if(d>cs)
                        break;
                }
            }
        }
    }
    if(cs!=oo)
        cout<<cs;
    else
        cout<<0;
}
void xuli3(int i,int j)
{
}
int main()
{
    /*    ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        freopen("dmin.inp","r",stdin);
        freopen("dmin.out","w",stdout);*/
    cin>>n>>s;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    /*sum[1]=a[1];
    for(int i=2; i<=n; i++)
        sum[i]=sum[i-1]+a[i];
    if(n<=100000) xuli2();
    else xuli1();*/
    return 0;
}

