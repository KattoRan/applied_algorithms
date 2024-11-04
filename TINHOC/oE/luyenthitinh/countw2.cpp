#include<bits/stdc++.h>
using namespace std;
string s,st;
long long n;
int res,res1;
vector<string> a;
map<string,int> m;
void chuanhoa(string &s)
{
    while(s[0]==' ')
        s.erase(0,1);
    int n=s.size();
    while(s[n-1]==' ')
        s.erase(n-1,1);
    int i=s.find("  ");
    while(i!=-1)
    {
        s.erase(i,1);
        i=s.find("  ");
    }
    cout<<s<<endl;
}
main()
{
#define name "countw2"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    getline(cin,s);
    chuanhoa(s);
    s=s+" ";
    res=1000000000;
    string s1="";
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==' ')
        {
            m[s1]++;
            int k=s1.size();
            res=min(k,res);
            s1="";
        }
        else
            s1=s1+s[i];
    }
    for(auto i:m)
    {
        if(i.second>1) res1++;
    }
    cout<<res1<<" "<<res;
}
