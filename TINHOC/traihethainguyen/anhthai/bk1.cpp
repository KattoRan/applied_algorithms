#include<bits/stdc++.h>
using namespace std;
int n,k;
char s[100000001];
int tryy(int i,int ok,int h)
{
    if(i==n) return ok && h==0;
    int ans=tryy(i+1,ok,h);
    if(s[i]=='('&&h<k)
    {
        ans+=tryy(i+1,ok||h+1==k,h+1);
    }
    if(s[i]==')'&&h)
    {
        ans+=tryy(i+1,ok,h-1);
    }
    return ans;
}
int main()
{
    freopen("bk1.inp","r",stdin);
    freopen("bk1.out","w",stdout);
    scanf("%d%s",&k,s);
    n=strlen(s);
    cout<<tryy(0,0,0);
}

