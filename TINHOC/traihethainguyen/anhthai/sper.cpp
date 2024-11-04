#include<bits/stdc++.h>
using namespace std;
int n;
long long save[22][1<<20];
long long duyet(int i,int mark)
{
    if(i>n)
        return 1;
    if(save[i][mark>>1]!=-1)
        return save[i][mark>>1];
    long long ans;
    ans=0;
    for(int j=1; j<=n; j++)
    {
        if(!(mark>>j&1))
        {
            for(int k=1; k<=n; k++)
                if((mark>>k&1)&&(k&j)==j)
                    goto next_j;
            ans+=duyet(i+1,1<<j|mark);
        }
        next_j:;
    }
    save[i][mark>>1]=ans;
    return ans;

}
int main()
{
    cin>>n;
    cout<<duyet(1,0);
}
