#include <bits/stdc++.h>
using namespace std;

long long value(vector<long long> c,vector<long long> h,int ht){
	long long cost=0;
	for(int i=0;i<h.size();i++){
		cost+=c[i]*(abs(h[i]-ht));
	}
	return cost;
}

int main(){
	int t,n;
	long long a;
	long long hi,lo,mid,costleft,costright,costmid;
	cin>>t;
	vector<long long> h,c;
	while(t--){
		h.clear();
		c.clear();
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a;
			h.push_back(a);
		}
		for(int i=0;i<n;i++){
			cin>>a;
			c.push_back(a);
		}
		lo=0;
		hi=10000;
		while(hi!=lo){
			//cout<<hi<<" "<<lo;
			if(mid==(lo+hi)/2){
				break;
			}
			mid=(lo+hi)/2;
			costleft=value(c,h,mid-1);
			costright=value(c,h,mid+1);
		    costmid=value(c,h,mid);
			if(costleft>=costmid && costmid>=costright){
				lo=mid+1;
			}
			if(costleft<=costmid && costmid<=costright){
				hi=mid-1;
			}
		}
		if(hi==lo){
			cout<<value(c,h,lo)<<endl;
		}
		else{
			cout<<costmid<<endl;
		}
		
	}
}