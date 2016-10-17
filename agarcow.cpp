#include <bits/stdc++.h>
using namespace std;


bool check(vector<long long> diff,int c,long long gap)
{
	
	
	c--; //placed first cow
	long long sum=0;
	int i=0;
	while(i<=diff.size())
	{
		if(c<=0){return true;}
		//cout<<sum<<endl;
		if(sum>=gap)
		{
			c--;
			sum=0;
		}
		else
		{
			sum+=diff[i];
			i++;
		}
	}
	return false;
}
int main()
{	
	
	int t;
	int n,c;
	long long a;
	cin>>t;
	while(t--)
	{	
	 	cin>>n>>c;
		vector<long long> pos;
		for(int j=0;j<n;j++)
		{
			cin>>a;
			pos.push_back(a);
		}

		long long min=0;
		long long max=*max_element(pos.begin(),pos.end())-*min_element(pos.begin(),pos.end());
		long long mid;
		sort(pos.begin(),pos.end());
		vector<long long> diff;
		for(int i=1;i<pos.size();i++)
		{
			diff.push_back(pos[i]-pos[i-1]);
		}
		while(min<max)
		{
			if(min==max-1){break;}
			mid=(min+max)/2;
			if(check(diff,c,mid))
			{
				min=mid;
			}
			else
			{
				max=mid;
			}
		}
		cout<<min<<endl;
	}
}