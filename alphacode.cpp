#include <bits/stdc++.h>
using namespace std;
long long dp[5000];
long long alpha(string s)
{
	long long a,b;
	if(s.length()==1)
	{
		if(s[0]=='0'){dp[0]=0;return 0;}
		else {dp[0]=1;return 1;}
	}

	if(s.length()==2)
	{
		if(atoi(s.substr(s.length()-2,2).c_str())>=10&&atoi(s.substr(s.length()-2,2).c_str())<=26)
		{
			if(s[1]=='0'){dp[1]=1;return 1;}
			else{dp[1]=2;return 2;}
		}
		if(s[1]=='0'){dp[1]=0;return 0;}
		else{dp[1]=1;return 1;}
	}

	if(dp[s.length()-1]!=-1){return dp[s.length()-1];}


	if(s[s.length()-1]=='0')
	{
		if(atoi(s.substr(s.length()-2,2).c_str())>=10&&atoi(s.substr(s.length()-2,2).c_str())<=26)
		{
			dp[s.length()-1]=alpha(s.substr(0,s.length()-2));
		}
		else{dp[s.length()-1]=0;return 0;}
		return dp[s.length()-1];
	}
	else
	{
		if(atoi(s.substr(s.length()-2,2).c_str())>=11&&atoi(s.substr(s.length()-2,2).c_str())<=26)
		{
			a=alpha(s.substr(0,s.length()-2));
		}
		else{a=0;}

		b=alpha(s.substr(0,s.length()-1));
		dp[s.length()-1]=a+b;
		return a+b;
	}
}

int main()
{
	string s;

	while(1>0)
	{
		
		cin>>s;
		memset(&dp,-1,sizeof(dp));
		if(s[0]=='0'&&s.length()==1){break;}
		if(s[0]=='0'){cout<<"0"<<endl; continue;}
		cout<<alpha(s)<<endl;
	}
	

}