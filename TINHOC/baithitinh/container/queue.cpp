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

int n,a[100000];
queue<int> q;

void nhap()
{

}

void solve()
{

}

main()
{
    #define name ""
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    cin>>n;
    fu(i,1,n) a[i]=rand()%10000;
    fu(i,1,n) cout<<a[i]<<" ";
    cout<<'\n';
    fu(i,1,n) q.push(a[i]);
    while(!q.empty())
    {
        cout<<q.front()<<" "<<q.back()<<'\n';
        q.pop();
    }
}
