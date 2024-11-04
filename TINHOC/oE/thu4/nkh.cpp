#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
string res="";
int a[1000007];
void cnkl()
{
    for(int i=0;i<s.size();i++)
        cout<<a[i];
    exit(0);
}
void tryi(int i,int j,int k)
{
    if(i>=s.size())
        cnkl();
    else
    {
        if(s[i]==s1[j])
        {
            a[i]=1;
            tryi(i+1,j+1,k);
        }
        if(s[i]==s2[k])
        {
            a[i]=2;
            tryi(i+1,j,k+1);
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("nkh.inp","r",stdin);
    freopen("nkh.out","w",stdout);
    cin>>s1>>s2>>s;
    tryi(0,0,0);
}
