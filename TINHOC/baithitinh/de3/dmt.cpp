#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=350007;
int t,f[N],de[N],res;
void sang()
{
    f[0]=f[1]=1;
    for(int i=2;i*i<=350000;i++)
    if(f[i]==0)
        for(int j=i*i;j<=350000;j+=i)
        f[j]=1;
}
main()
{
    #define name "dmt"
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(name".inp","r",stdin);
	freopen(name".out","w",stdout);
    cin>>t;
    sang();
    int tam=1,bon=1;
    fu(i,1,8) tam*=3;
    fu(i,1,4) bon*=3;
    fu(i,1,350000)
    if(f[i]==0) de[i]=de[i-1]+1;
    else de[i]=de[i-1];
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        if(n<=tam&&tam<=m) res=1;
        else res=0;
        int a=sqrt(n)/3;
        int b=sqrt(m)/3;
        if(a*a*9==n)
        res+=de[b]-de[a-1];
        else
            res+=de[b]-de[a];
        if(n<=bon&&bon<=m) res--;
        cout<<res<<'\n';
    }
}
