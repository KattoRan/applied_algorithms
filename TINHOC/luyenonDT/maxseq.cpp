#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define task "maxseq"
using namespace std;
const int N=1e5+7;
int n,d,res;
int a[N],u[N];

typedef long long ll;
bool kt(int a)
{
    int k=sqrt(2*a);
    if((k*(k+1))/2==a) return 1;
    return 0;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    cin>>n;
    fu(i,1,n) cin>>a[i];
    d=0,res=0;
    fu(i,1,n)
    {
        if(kt(a[i]))
            {if(a[i]>=a[i-1]) d++;
             else d=1;
             res=max(res,d);}
        else d=0;
    }
    cout<<res;
}
