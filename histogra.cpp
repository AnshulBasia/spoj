#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,tp;
	long long a;
	vector<long long> ht;
	long long cur=0,max=0;
	while(1>0){
		cin>>n;
		cur=0;
		max=0;
		ht.clear();
		if(n==0){break;}
		for(int i=0;i<n;i++){
			cin>>a;
			ht.push_back(a);
		}
		stack<int> s;
		int i=0;
		while(i<n){
			if(s.empty()||ht[s.top()]<ht[i]){
				s.push(i);
				i++;
			}
			else{
				tp=s.top();
				s.pop();
				cur=ht[tp]*(s.empty()?i:i-s.top()-1);
				if(cur>max){max=cur;}
			}
		}
		while(!s.empty()){
			tp=s.top();
			s.pop();
			cur=ht[tp]*(s.empty()?i:i-s.top()-1);
			if(cur>max){max=cur;}
		}
		cout<<max<<endl;
	}
}