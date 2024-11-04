#include<bits/stdc++.h>
using namespace std;
const int a[10]= {6,2,5,5,4,5,6,3,7,6};
const int b[10]= {1,5,1,2,2,2,1,2,0,0};
const int c[10]= {1,5,1,2,2,2,1,4,0,1};
string n;
int v,len,d;
void xuli1()
{
    for(int i=0; i<=len-1; i++)
    {
        if(n[i]=='0')
            d+=a[0];
        if(n[i]=='1')
            d+=a[1];
        if(n[i]=='2')
            d+=a[2];
        if(n[i]=='3')
            d+=a[3];
        if(n[i]=='4')
            d+=a[4];
        if(n[i]=='5')
            d+=a[5];
        if(n[i]=='6')
            d+=a[6];
        if(n[i]=='7')
            d+=a[7];
        if(n[i]=='8')
            d+=a[8];
        if(n[i]=='9')
            d+=a[9];
    }
    cout<<d;
}
void xuli2()
{
    int k,h;
    for(char i='0'; i<='9'; i++)
        if(n[len-1]==i)
        {
            h=i-48;
        }
    k=0;
    k+=b[h];
    for(int i=len-2; i>=0; i--)
    {
        int t=n[i]-48;
        for(int j=1; j<=9; j++)
        {
            if(t==j)
                {
                 k=k+b[j]*k;
                 if(b[j-1]==c[j-1])
                    k=k+1;
                 else k=k+c[j];
                }
        }
    }
    cout<<k;
}
int main()
{
    cin>>v;
    cin>>n;
    len=n.size();
    if(v==1)
        xuli1();
    if(v==2)
        xuli2();
}
