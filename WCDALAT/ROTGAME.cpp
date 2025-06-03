#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+1;
const int minN=-1e5+1;
main(){
	int n,k,q;
	cin>>n>>k>>q;
	vector<int>v;
//	int t=n/k;
//	vector<int>v1[t];
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	while(q--){
		int y,x;cin>>y>>x;
		if(y==2){
			if(x!=0){
				if(x>0){
					for(int i=1;i<=x;i++){
						int tg=v[n-1];
						v.insert(v.begin(),tg);
						v.pop_back();
					}
				}
				else{
					x=abs(x);
					for(int i=1;i<=x;i++){
						int tg=v[0];
						v.erase(v.begin());
						v.push_back(tg);
					}
				}
			}
			
		}
		if(y==1){
			if(x!=0){
				if(x>0){
					for(int i=1;i<=x;i++){
						for(int i=1;i<v.size();i+=k){
							int tg=v[i];
							v.insert(v.begin()+i-k+1,tg);
							v.erase(v.begin()+i);
						}	
					}
				}
			}
		}
		
	}
	for(int x:v) cout<<x<<" ";
	
}

