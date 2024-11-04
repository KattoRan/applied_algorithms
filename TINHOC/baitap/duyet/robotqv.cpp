#include<bits/stdc++.h>
using namespace std;
string p[10],s;
int kt;
int gia,kiluc,x[10],x0[10];
void init()
{   cin.ignore();
    for(int i=1; i<=9; i++)
    {
        cin>>p[i];
        p[i]="="+p[i];
    }
    cin>>s;
    s=" "+s;
    kiluc=1000000,gia=0;
}
void cnkl()
{
    bool ok=1;
    for(int i=1; i<=9; i++)
        if(s[i]!='T')
        {
            ok=0;
            break;
        }
    if(ok&&gia<kiluc)
    {
        kiluc=gia;
        for(int i=1; i<=9; i++)
            x0[i]=x[i];
    }
}
void try1(int i)
{
    int n;string s1;
    for(int j=0; j<=2; j++)
    {
        x[i]=j;
        s1=s;
        n=p[i].size();
        for(int k=1; k<=j; k++)
            for(int h=1; h<n; h++)
            {
                int t=p[i][h]-48;
                switch (s[t])
                {
                case 'T':
                {
                    s[t]='X';
                    break;
                }
                case 'X':
                {
                    s[t]='V';
                    break;
                }
                case 'V':
                {
                    s[t]='T';
                    break;
                }
                }
            }
        gia+=j*(n-1);
        if(i==9)
            cnkl();
        else if(gia<kiluc)
            try1(i+1);
        gia-=j*(n-1);
        s=s1;
    }
}
int main()
{
    /*  ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      freopen("robotqv.inp","r",stdin);
      freopen("robotqv.out","w",stdout);*/
    init();
    try1(1);
    for(int i=1;i<=9;i++)
        if(x0[i]!=0) kt=1;
        else kt=0;
    if(kt==1)
    {cout<<kiluc<<'\n';
    for(int i=1; i<=9; i++)
    {
        if(x0[i]==1)
            cout<<i;
        if(x0[i]==2)
            cout<<i<<i;
    }
    }
    if(kt==0) cout<<"0";
    return 0;
}
