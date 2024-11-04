#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
int n,a,b,c,d;
vector <int> h,k;
int scp(int n)
{
    int t=sqrt(n);
    if(n==t*t) return 1;
    else return 0;
}
void xuli1()
{
    d=0;
    for(int a=1;a<=n-2;a++)
    for(int b=a+1;b<=n-1;b++)
    for(int c=b+1;c<=n;c++)
    {
        if(scp(a*b)&&scp(a*c)&&scp(b*c))
            d++;
        if(scp(a*b)==0) break;
    }
    cout<<d;
}
void xuli2()
{
    for(int i=1;i<=n;i++)
        {if(scp(i)) h.push_back(i);
         else k.push_back(i);}
    for(int a=0;a<=h.size()-3;a++)
    for(int b=a+1;b<=h.size()-2;b++)
    for(int c=b+1;c<=h.size()-1;c++)
    {
        d++;
    }
    for(int a=0;a<=k.size()-3;a++)
    for(int b=a+1;b<=k.size()-2;b++)
    for(int c=b+1;c<=k.size()-1;c++)
    {
        if(scp(k[a]*k[b])&&scp(k[a]*k[c])&&scp(k[b]*k[c]))
            d++;
        if(scp(k[a]*k[b])==0) break;
    }
    cout<<d;


}
int main()
{
    cin>>n;
    if(n<=100) xuli1();
    if(n>100&&n<=5000) xuli2();
    return 0;
}
