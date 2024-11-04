#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
main(){
	long n, k; cin>>n>>k;
	char s[n]; cin>>s;
	long vitri=0, k1=k, dem=0;
	while(dem<n-k){
		char max1=s[vitri];
		for(long i=vitri+1; i<=k1; i++)
			if(max1<s[i]){
				vitri=i;
				max1=s[i];
			}
		dem++; k1++;
		cout<<max1;
		vitri++;
	}
	return 0;}
