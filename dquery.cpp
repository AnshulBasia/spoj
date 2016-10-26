#include <bits/stdc++.h>
using namespace std;


struct query{
	int first;
	int second;
	int idx;
	query(){}
	query(int a,int b,int c){
		first=a;
		second=b;
		idx=c;
	}
};
int track[1000100];
int n,temp=0,sqrt_n;
bool comp(struct query p1,struct query p2){
	if(p1.first/sqrt_n<p2.first/sqrt_n){return 1;}
	else if(p1.first/sqrt_n>p2.first/sqrt_n){return 0;}
	else return p1.second<p2.second;

}
void add(int a){
	track[a]++;
	if(track[a]==1)temp++;
}
void remove(int a){
	track[a]--;
	if(track[a]==0)temp--;
}
int main(){
	cin>>n;
	int A[n];
	sqrt_n=floor(sqrt(n));
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	int q;
	cin>>q;
	struct query queries[q];
	int ans[q];
	int l,r;
	for(int i=0;i<q;i++){
		scanf("%d %d",&l,&r);
		l--;
		//r--;
		queries[i]=query(l,r,i);
	}

	sort(queries,queries+q,comp);
	
	l=0;r=0;
	for(int i=0;i<q;i++){
		while(l<queries[i].first){
			remove(A[l]);
			l++;
		}
		while(l>queries[i].first){
			l--;
			add(A[l]);
		}
		while(r>queries[i].second){
			r--;
			remove(A[r]);
		}
		while(r<queries[i].second){
			add(A[r]);
			r++;
		}
		ans[queries[i].idx]=temp;
	}
	for(int i=0;i<q;i++){
		printf("%d\n",ans[i]);
	}
}