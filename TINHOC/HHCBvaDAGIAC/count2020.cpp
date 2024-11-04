#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
long long n;
bool d[1000006]= {};
int res;
struct point
{
    long long x,y;
} A,B;
void Read(long long &x)
{
    x=0;
    int tam=1;
    char c=getchar();
    while((c<'0'||c>'9')&&(c!='-'))
        c=getchar();
    if(c=='-')
    {
        tam=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}
long long dist(point A, point B)
{
    return (long long)(sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)));
}
int main()
{
   /* ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("COUNT.INP","r",stdin);
    freopen("COUNT.OUT","w",stdout);*/
    //sang nguyen to
    d[0]=d[1]=true;
    for(int i=2; i<=1000; i++)
        if(!d[i])
            for(int j=i*i; j<=1000000; j+=i)
                d[j]=true;
    //nhap
    Read(n);
    int res=0;

    for(int i=1; i<=n; i++)
    {
        Read(A.x);
        Read(A.y);
        Read(B.x);
        Read(B.y);
        if(!d[dist(A,B)])++res;

    }
    cout<<res;
    return 0;
}
