#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n;
char ans[maxn],s[maxn];
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        for(int i=0;s[i];i++) ans[i]^=s[i];
    }
    printf("%s\n",ans);


}

