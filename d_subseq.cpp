#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	string s;
	vector<int> dp;
	int map[26];
	long long mod=1000000007;
	while(t>0)
	{
		t--;
		cin>>s;
		dp.clear();
		memset(&map,-1,sizeof(map));
		for(int i=0;i<s.length();i++)
		{
			if(i==0){dp.push_back(2); map[(int)s[i]-65]=i;continue;}
			int k= map[(int)s[i]-65];
			if(k==-1)
			{
				map[(int)s[i]-65]=i;
				dp.push_back((dp[i-1]*2)%mod);
				continue;
			}
			if(k==0)
			{
				map[(int)s[i]-65]=i;
				dp.push_back(((dp[i-1]*2)-1)%mod);
				continue;
			}

			long long temp=((dp[i-1]*2)-dp[k-1])%mod;
			if(temp<0){temp+=mod;}
			dp.push_back(temp);
			map[(int)s[i]-65]=i;
		}

		cout<<dp[s.length()-1]%mod<<endl;

	}
}