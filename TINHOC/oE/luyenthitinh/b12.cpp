#include<bits/stdc++.h>
using namespace std;
string s;
main()
{
    getline(cin,s);
    while(s[0]==' ') s.erase(0,1);
    int n=s.size();
    while(s[n-1]==' ') s.erase(n-1,1);
    for(int i=0;i<s.size();i++)
    {
        while(s[i]==' '&&s[i+1]==' ') s.erase(i,1);
    }
    cout<<s;
}
