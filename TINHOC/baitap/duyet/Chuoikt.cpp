#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,gia,kiluc,m;
char s[maxn],s0[maxn];
bool same(int i,int k)
{
    int j=i-k;
    for(int l=0;l<k;l++)
        if(s[i-l]!=s[j-l]) return 0;
    return 1;
}
bool kt(int i)
{
     for(int k=1;k<=i/2;k++)
        {
            if(same(i,k)) return false;
        }
     return true;
}
void cnkl()
{
    if(gia<kiluc) {kiluc=gia;
                   for(int i=1;i<=n;i++) s0[i]=s[i];}
}
void try1(int i)
{
    for(char j='A';j<='C';j++)
    {
        s[i]=j;
        if(kt(i))
        {
           if(j=='B') gia++;
           if(i>=n) cnkl();
           else
            if(gia+(n-i)/4<kiluc)
              try1(i+1);
           if(j=='B') gia--;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Chuoikt.inp","r",stdin);
    freopen("Chuoikt.out","w",stdout);
    cin>>n;
    kiluc=1000,gia=0;
    try1(1);
    cout<<kiluc<<'\n';
    for(int i=1;i<=n;i++) cout<<s0[i];
    return 0;
}
