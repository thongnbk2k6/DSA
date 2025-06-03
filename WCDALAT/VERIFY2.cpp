#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;
int n,q,t;
vector<int>v;
map<pair<int,int>,int>mp;

#define ii pair<pair<int,int>,int>
vector<ii> vec;

void khoitao(){
	cin>>n>>q;
	for(int i=0;i<n;i++){
		v.push_back(i);
	}
	
	for(int i=1;i<=q;i++){
		int l,r,a;cin>>l>>r>>a;
		pair<int,int>x={l,r};
		mp[x]=a;
	}
}
bool kt(){
	for(auto x:mp){
		pair<int,int>top=x.first;
		int l=top.first,r=top.second;
		int mi=x.second;
		if(mi!=*min_element(v.begin()+l,v.begin()+r)){
			return 0;
		}
	}
	return 1;
}
main(){
	
	khoitao();
	do{
		if(kt()){
			for(int i=0;i<n;i++){
				cout<<v[i]<<" ";
			}
			return 0;
		}
	}while(next_permutation(v.begin(),v.end()));
	for(int i=1;i<=n;i++){
		cout<<-1<<" ";
	}
//	for(auto x:mp){
//		pair<int,int>top=x.first;
//		int a=x.second;
//		cout<<top.first<<" "<<top.second<<" "<<a<<endl;
//	}
}

