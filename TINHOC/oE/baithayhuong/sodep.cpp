#include<bits/stdc++.h>
using namespace std;
string s;
int tong9(string x)
{
    int res=0;
    for(int i=0;i<x.size();i++)
    {
        res+=(x[i]-48);
        if(res>9) return 0;
    }
    if(res==9) return 1;
    return 0;
}
main()
{
    #define name "sodep"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    while(cin>>s)
    {
        if(s=="9") cout<<"1"<<'\n';
        else
            cout<<tong9(s)<<'\n';
    }
}
