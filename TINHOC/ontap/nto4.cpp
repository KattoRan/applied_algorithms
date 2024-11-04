#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
long long x,k,res2,res1;
int p[N],m[N];
void phantich (long long x)
{
    int i=2;
    k=0;
    while(x>=i*i)
    {
        int dem=0;
        while(x%i==0)
            dem++, x=x/i;
        if(dem>0)
            k++, p[k]=i, m[k]=dem;
        i++;
    }
    if(x>1)
    {
        k++;
        p[k]=x;
        m[k]=1;
    }
}
long long sqr (long long x)
{
    return x*x;
}
long long powi (long long a, long long b)
{
    if(b==0)
        return 1;
    else if(b%2==0)
        return sqr(powi(a,b/2));
    else
        return a*sqr (powi(a, b/2));
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("nto4.inp","r",stdin);
    freopen("nto4.out","w",stdout);
    cin>>x;
    phantich(x);
    res1=1;
    for(int i=1;i<=k;i++)
    {
        res1*=(m[i]+1);
    }
    cout<<res1<<" ";
    res2=1;
    for(int i=1; i<=k; i++)
    {
        m[i]++;
        res2*=((powi(p[i],m[i])-1)/(p[i]-1));
    }
    cout<<res2;
}
