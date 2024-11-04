#include<bits/stdc++.h>
using namespace std;
string s;
int d;
int main()
{
    getline(cin,s);
    d=1;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]==s[i-1]) d++;
        else {cout<<d<<s[i-1];
              d=1;}
    }
    cout<<d<<s[s.size()-1];
    return 0;
}
