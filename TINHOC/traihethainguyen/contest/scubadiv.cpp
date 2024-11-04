#include<bits/stdc++.h>
using namespace std;

#define fort(i,a,b) for(int i=a;i<=b;i++)
#define oo 10000000000

vector<int> a,b,w;
int t,n,a0,b0;
int f[22][80][1001];

void xuli(){
    fort(i,0,21)
    fort(j,0,79){
    if(i<a[1]&&j<b[1])
        f[i][j][1]=w[1];
    else f[i][j][1]=oo;
    }
    f[0][0][1]=0;
    int oxi,nitro;
    fort(k,2,n)
    fort(i,0,a0)
    fort(j,0,b0){
    if(i>=a[k])  oxi=i-a[k];
    else oxi=0;
    if(j>=b[k])  nitro=j-b[k];
    else nitro=0;
    f[i][j][k]=min(f[i][j][k-1],f[oxi][nitro][k-1]+w[k]);
    }
    cout<<f[a0][b0][n]<<'\n';
}


int main()
{
    cin>>t;
    while(t>0)
    {
        t--;
        cin>>a0>>b0;
        cin>>n;
        a.resize(n+5);
        b.resize(n+5);
        w.resize(n+5);
        fort(i,1,n) cin>>a[i]>>b[i]>>w[i];
        xuli();
    }
    return 0;
}
