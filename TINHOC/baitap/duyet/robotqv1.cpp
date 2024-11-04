#include<bits/stdc++.h>
using namespace std;
string p[10],s,s1;
int gia,kiluc,x[10],x0[10];
bool ok;
void init()
{   cin.ignore();
    for(int i=1;i<=9;i++)
        {cin>>p[i];p[i]="="+p[i];}
    cin>>s;
    s=" "+s;
    kiluc=1000000,gia=0;
}
void cnkl()
{
    bool ok=1;
    for(int i=1;i<=9;i++)
       if(s[i]!='T') {ok=0;break;}
    if(ok&&gia<kiluc)
    {
        kiluc=gia;
        for(int i=1;i<=9;i++)
            x0[i]=x[i];
    }
}
void try1(int i)
{
    for(int j=0;j<=2;j++)
    {
        x[i]=j;
        int n;
        n=p[i].size();
        if(j==1) {
                  for(int k=1;k<=n-1;k++)
                       {int t=p[i][k]-48;
                        if(s[t]=='T') s[t]='X';
                        if(s[t]=='X') s[t]='V';
                        if(s[t]=='V') s[t]='T';}
                 }
        if(j==2) {
                  for(int k=1;k<=n-1;k++)
                       {int t=p[i][k]-48;
                        if(s[t]=='T') s[t]='V';
                        if(s[t]=='X') s[t]='T';
                        if(s[t]=='V') s[t]='X';}
                 }
        gia+=j*(n-1);
        if(i==9) cnkl();
        else if(gia<kiluc) try1(i+1);
        gia-=j*(n-1);
        if(j==2) {
                  for(int k=1;k<=n-1;k++)
                       {int t=p[i][k]-48;
                        if(s[t]=='T') s[t]='X';
                        if(s[t]=='X') s[t]='V';
                        if(s[t]=='V') s[t]='T';} }
        if(j==1) {
                  for(int k=1;k<=n-1;k++)
                       {int t=p[i][k]-48;
                        if(s[t]=='T') s[t]='V';
                        if(s[t]=='X') s[t]='T';
                        if(s[t]=='V') s[t]='X';}
                 }
    }
}
int main()
{
    init();
    try1(1);
    cout<<kiluc<<'\n';
    for(int i=1;i<=9;i++) {if(x0[i]==1) cout<<i;
                           if(x0[i]==2) cout<<i<<i;}
    return 0;
}
