#include<bits/stdc++.h>
using namespace std;
int n,q,t;
vector<int>v;
vector<int>v1[100001];
bool kt(){
	for(int i=1;i<=t;i++){
		int l=v1[t][0],r=v1[t][1],a=v1[t][2];
		if(a!=*min_element(v.begin()+l,v.begin()+r)) return 0;
	}
	return 1;
}
main(){
	cin>>n>>q;
	for(int i=0;i<n;i++){
		v.push_back(i);
	}
	t=q;
	while(q--){
		for(int i=1;i<=3;i++){
			int x;cin>>x;
			v1[q].push_back(x);
		}
	}
	do{
		if(kt()){
			for(int i=0;i<n;i++){
				cout<<v[i]<<" ";
			}
			return 0;
		}
	}while(next_permutation(v.begin(),v.end()));
	for(int i=1;i<=q;i++){
		cout<<-1<<" ";
	}
}

