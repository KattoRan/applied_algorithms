// Cat \\
||*---*||
#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

stack<int> s;
string a;

void nhap()
{

}

void solve()
{

}

main()
{
    #define name "mmass"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>a;
    a='('+a;
    a=a+')';
    int n;
    n=a.size();
    a='+'+a;
    fu(i,1,n)
    {
        if(a[i]=='(') s.push(0);
        if(a[i]=='C') s.push(12);
        if(a[i]=='H') s.push(1);
        if(a[i]=='O') s.push(16);
        if(a[i]==')')
        {
            int k=0;
            while(s.top()!=0)
            {
                k+=s.top();
                s.pop();
            }
            s.top()=k;
        }
        if('0'<a[i]&&a[i]<='9')
        {
            int k=(int) (a[i]-48);
            while('0'<a[i+1]&&a[i+1]<='9')
            {
                k=k*10+(int) (a[i+1]-48);
                i++;
            }
            s.top()*=k;
        }
    }
    cout<<s.top();
}
