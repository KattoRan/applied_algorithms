#include<bits/stdc++.h>
using namespace std;
string s;
int dem[26];
int main()
{
    getline(cin,s);
    for(int i=0;i<s.size();i++) s[i]-=32;
    for(char i='A';i<='Z';i++) dem[i]=0;
    for(int i=0;i<s.size();i++) dem[s[i]]++;
    for(char i='A';i<='Z';i++)
        if(dem[i]!=0) cout<<i<<" "<<dem[i]<<'\n';
    return 0;
}
