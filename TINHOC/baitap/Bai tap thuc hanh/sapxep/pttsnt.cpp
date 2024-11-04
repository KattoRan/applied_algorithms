#include<bits/stdc++.h>
using namespace std;
const int maxk=1e6+1;
int n,nto[maxk],k;
void phantich(int a)
{   int i=2;k=0;
    while(i*i<=a)
       {while(a%i==0) {k++;nto[k]=i;a=a/i;} i++;}
    if(a>1) k++,nto[k]=a;
    return;
}
int main()
{
    cin>>n;
    phantich(n);
    for(int i=1;i<=k;i++) cout<<nto[i]<<" ";
    return 0;
}
