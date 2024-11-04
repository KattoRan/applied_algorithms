#include<bits/stdc++.h>
using namespace std;
string s,st;
long long n;
int res;
vector<string> a;
long long ston(string s)
{
    long long t=0;
    for(int i=0;i<s.size();i++)
    {
        int x=s[i]-48;
        t=t*10+x;
    }
    return t;
}
string ntos(long long x)
{
    string res="";
    while(x>0)
    {
        res=char(x%10+48)+res;
        x=x/10;
    }
    return res;
}
void chuanhoa(string s)
{
    while(s[0]==' ') s.erase(0,1);
    int n=s.size();
    while(s[n-1]==' ') s.erase(n-1,1);
    for(int i=0;i<s.size();i++)
    {
        while(s[i]==' '&&s[i+1]==' ') s.erase(i,1);
    }
}
main()
{
    getline(cin,s);
    chuanhoa(s);
    s=s+" ";
    int i;
    i=s.find(" ");
    while(i!=-1)
    {
        st=s.substr(0,i);
        a.push_back(st);
        s.erase(0,i+1);
            i=s.find(" ");

    }
    res=a[0].size();
    cout<<res<<" ";
    for(int i=1;i<a.size();i++)
    {
        int k=a[i].size();
        res=min(res,k);
    }
    cout<<res;
}
