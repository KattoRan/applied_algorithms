#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
string s;
int k,res;
char res1;
int d[50];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("matma.inp","r",stdin);
    //freopen("matma.out","w",stdout);
    cin>>k;
    s="";
    fu(i,1,k)
    {
        int p;
        cin>>p;
        int n=s.size();
        if(p==0)
        {
            string r;
            cin>>r;
            s+=r;
        }
        else
        {
            int r;
            cin>>r;
            fu(i,n-p,n-p+r-1) s=s+s[i];
        }
    }
    int m=s.size();
    fu(i,0,m-1)
    d[s[i]]++;
    res=1;
    for(char i='z';i>='a';i--)
        if(d[i]>=res) res=d[i],res1=i;
    cout<<res1<<res;
}
