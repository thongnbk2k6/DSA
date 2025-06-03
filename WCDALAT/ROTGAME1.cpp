#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;

main(){
	int n,q,k;cin>>n>>q>>k;
	vector<int>v;
	stack<pair<int,int>>st;
	for(int i=1;i<=q;i++){
		int y,x;cin>>y>>x;
		st.push({y,x});
	}
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	if(n==1) cout<<v[0]<<endl;
	else{
		while(!st.empty()){
			pair<int,int>x=st.top();
			st.pop();
			if(x.first==2){
				if(x.second>0){
					for(int i=1;i<=x.second;i++){
						int tg=v[n-1];
						v.insert(v.begin(),tg);
						v.pop_back();
					}
				}
				if(x.second<0){
					int tg1=abs(x.second);
					{
						for(int i=1;i<=tg1;i++){
							int tg=v[0];
							v.push_back(tg);
							v.erase(v.begin());
						}
					}
				}
			}
			if(x.first==1){
				int t=n/k;
				if(x.second>0){
					{
						for(int i=1;i<=x.second;i++){
						
							for(int j=0;j<v.size();j+=k){
								int tg=v[j];
								v.insert(v.begin()+j+k,tg);
								v.erase(v.begin()+j);
							}
					}
					}
				}
				if(x.second<0){
					int tg2=abs(x.second);
					for(int i=1;i<=x.second;i++){
						for(int j=k-1;j<v.size();j+=k){
							int tg=v[j];
							v.insert(v.begin()+j-k+1,tg);
							v.erase(v.begin()+j);
						}
					}
				}
			}
		}
		for(int x:v) cout<<x<<" ";
	}
}

