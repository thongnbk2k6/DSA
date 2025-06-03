#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;
int n,q;
vector<int>v;
main(){
	cin>>n>>q;
	for(int i=0;i<n;i++){
		v.push_back(i);
	}
	vector<int>v1;
	bool ok=1;
	
		while(q--){
			int l,r,a;cin>>l>>r>>a;
			do{
			if(a!=*min_element(v.begin()+l,v.begin()+r)){
				ok=0;
				break;
			}
		
			if(ok){
				for(int i=0;i<n;i++){
					v1.push_back(v[i]);
				}
				break;
			}
			if(ok){
		for(int x:v1) cout<<x<<" "; return 0;}
	
		
		
	
			}while(next_permutation(v.begin(),v.end()));
		
	for(int i=1;i<=q;i++)
			cout<<-1<<" ";
	
}

}



