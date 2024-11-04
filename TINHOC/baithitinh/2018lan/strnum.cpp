#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
string s;
int n,k;
stack<int> q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("strnum.inp","r",stdin);
    freopen("strnum.out","w",stdout);
    cin>>n>>k;
    cin>>s;
    q.push(0);
    fu(i,1,n-1)
    {
       while(q.size()&&k>0&&s[q.top()]<s[i]) {q.pop();k--;}
       q.push(i);
    }
    while(k>0)
    {
        q.pop();k--;
    }
    string s1;
    while(q.size())
    {
        s1=s[q.top()]+s1;
        q.pop();
    }
    cout<<s1;
}

