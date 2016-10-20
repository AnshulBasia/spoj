#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> dp;

long long recurse(ll n){
	if(n==0){return 0;}
	if(dp[n]!=0){
		return dp[n];
	}
	ll temp=recurse(n/2) + recurse(n/3) + recurse(n/4);
	if(temp>n){
		dp[n]=temp;
		return dp[n];
	}
	dp[n]=n;
	return n;
}

int main(){
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;
	dp[4]=4;
	ll n;
	int t=0;
	while(cin>>n){
		cout<<recurse(n)<<endl;
		t++;
		if(t==10){break;}
	}
	
}