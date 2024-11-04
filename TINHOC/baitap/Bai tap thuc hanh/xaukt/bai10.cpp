#include<bits/stdc++.h>
using namespace std;
string s;
int i,d,dmax;
int main()
{
    getline(cin,s);
    i=0;
    d=0;
    while(i<s.size())
    {
        while((s[i]==' '||s[i]=='.'||s[i]==',')&&(i<s.size())) i++;
        d++;
        i++;
        while((s[i]!=' '&&s[i]!='.'&&s[i]!=',')&&(i<s.size())) {d++;i++;}
        if(d>dmax) dmax=d;
        d=0;
        i++;
    }
    cout<<dmax;
    return 0;
}
