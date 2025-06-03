#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;

main(){
	int n,k,q;cin>>n>>k>>q;
	int t=n/k;
	vector<int>v;
	vector<int>v1[t];
	stack<pair<int,int>>st;
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		st.push({x,y});
	}
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.push_back(x);
		v1[i/k].push_back(x);
	}
//	cout<<t;return 0;
//	for(int i=0;i<t;i++){
//		for(int x:v1[i]) cout<<x<<" ";
//	}
	while(!st.empty()){
		pair<int,int>x=st.top();st.pop();
		if(x.first==2){
			if(x.second>0){
				int t1=x.second;
				for(int i=1;i<=t1;i++){
					int tg=v[0];
					v.erase(v.begin());
					v.push_back(tg);
				}
				for(int j=0;j<v.size();j++){
					v1[j/k].clear();
				}
				for(int j=0;j<v.size();j++){
					v1[j/k].push_back(v[j]);
				}
			}
			if(x.second<0){
				int t1=x.second;
				for(int i=1;i<=t1;i++){
					int tg=v[n-1];
					v.insert(v.begin(),tg);
					v.pop_back();
				}
				for(int j=0;j<v.size();j++){
					v1[j/k].clear();
				}
				for(int j=0;j<v.size();j++){
					v1[j/k].push_back(v[j]);
				}
			}
		}
		if(x.first==1){
			if(x.second>0){
				int t1=x.second;
				for(int i=1;i<=t1;i++){
					for(int j=1;j<=t;j++){
						int tg=v1[j][0];
						v1[j].erase(v1[j].begin());
						v1[j].push_back(tg);
					}
				}
				v.clear();
				for(int i=1;i<=t;i++){
					for(int x:v1[i]){
						v.push_back(x);
					}
				}
			}
			if(x.second<0){
				int t1=abs(x.second);
				for(int i=1;i<=t1;i++){
					for(int j=1;j<=t;j++){
						int tg=v1[j][k-1];
						v1[j].insert(v1[j].begin(),tg);
						v1[j].pop_back();
					}
				}
				v.clear();
				for(int i=1;i<=t;i++){
					for(int x:v1[i]){
						v.push_back(x);
					}
				}
			}
		}
	}
	for(int x:v) cout<<x<<" ";
	
}

