#include<bits/stdc++.h>
using namespace std;
int n,k,nxt[5005][300],m[5005][300];
char s[100011];
int tryy(int i,int ok,int h)
{
    int ans = ok && h==0;
    if(nxt[i]['('] != -1&&h<k)
    {
        ans+=tryy(nxt[i]['('],ok||h+1==k,h+1);
    }
    if(nxt[i][')'] != -1&&h)
    {
        ans+=tryy(nxt[i][')'],ok,h-1);
    }
    return ans;
}
int main()
{
    freopen("bk2.inp","r",stdin);
    freopen("bk2.out","w",stdout);
    scanf("%d%s",&k,s);
    n=strlen(s);
    if(s[n-1]==')')
    {
        nxt[n-1][')']=-1,m[n-1][')']=n-1;
        nxt[n-1]['(']=-1,m[n-1]['(']=-1;
    }
    else
    {
        nxt[n-1][')']=-1,m[n-1][')']=-1;
        nxt[n-1]['(']=-1,m[n-1]['(']=n-1;
    }
    for(int i=n-2;i>=0;i--)
    {
        if(m[i+1][')']==-1&&s[i]==')') nxt[i][')']=i;
        else
        {nxt[i][')']=m[i+1][')'];}
        if(m[i+1]['(']==-1&&s[i]=='(') nxt[i]['(']=i;
        else
        {nxt[i]['(']=m[i+1]['('];}

        if(s[i]==')') {m[i][')']=i;m[i]['(']=m[i+1]['('];}
        else
        {
            m[i]['(']=i;
            m[i][')']=m[i+1][')'];
        }
    }
    cout<<tryy(0,0,0);
}

