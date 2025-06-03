#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;

main(){
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		vector<int>v;
		for(int i=0;i<n;i++){
			int x;cin>>x;
			v.push_back(x);
		}
		priority_queue<pair<int,int>,vector<pair<int,int>>>mp;
		priority_queue<pair<int,int>,vector<pair<int,int>>>mp1;
		map<int,int>tg;
		map<int,int>tg1;
		int sl1=0;
		for(int i=0;i<n-1;i++){
			if(v[i]==v[i+2]){
				tg[v[i]]++;
				mp.push({tg[v[i]],v[i]});
				sl1++;
			}	
			tg1[v[i]]++;
			mp1.push({tg1[v[i]],v[i]});
		}
		int ans=1e5;
		if(sl1>=2){
			int a1,a2;
			for(int i=1;i<=2;i++){
				pair<int,int>x=mp.top();mp.pop();
				if(i==1) a1=x.second;
				else a2=x.second;
			}
			vector<int>v1;
			vector<int>v2;
			for(int i=1;i<=n;i++){
				if(i%2==0){
					v1.push_back(a1);
				}else{
					v1.push_back(a2);
				}
			}
			for(int i=1;i<=n;i++){
				if(i%2==0){
					v2.push_back(a2);
				}
				else{
					v2.push_back(a1);
				}
			}
			int dem=0;
			for(int i=0;i<n;i++){
				if(v[i]!=v1[i]){
					dem++;
				}
			}
			ans=min(ans,dem);
			dem=0;
			for(int i=0;i<n;i++){
				if(v[i]!=v2[i]){
					dem++;
				}
			}
			ans=min(ans,dem);
			cout<<ans<<endl;
		}else{
			if(sl1==1){
				int a3,a4;
				pair<int,int>x=mp.top();mp.pop();
				a3=x.second;
				pair<int,int>x2=mp1.top();
				a4=x2.second;
				vector<int,int>v3;
				vector<int,int>v4;
				for(int i=1;i<=n;i++){
					if(i%2!=0){
						v3.push_back(a3);
					}
					else{
						v3.push_back(a4);
					}
				}
				for(int i=1;i<=n;i++){
					if(i%2!=0){
						v4.push_back(a4);
					}else{
						v4.push_back(a3);
					}
				}
				int dem1=0;
				for(int i=0;i<n;i++){
					if(v3[i]!=v[i]){
						dem1++;
					}
				}
				ans=min(dem1,ans);
				dem1=0;
				for(int i=0;i<n;i++){
					if(v4[i]!=v4[i]){
						dem1++;
					}
				}
				ans=min(ans,dem1);
			}else{
				int a5,a6,tang=0;
				for(int i=1;i<=2;i++){
					pair<int,int>top3=mp1.top();mp1.pop();
					if(i==1) a5=top3.second;
					else a6=top3.second;
				}
				vector<int,int>v5;
				vector<int,int>v6;
				for(int i=1;i<=n;i++){
					if(i%2!=0){
						v5.push_back(a5);
					}else{
						v5.push_back(a6);
					}
				}
				for(int i=1;i<=n;i++){
					if(i%2!=0){
						v6.push_back(a6);
					}
					else{
						v6.push_back(a5);
					}
				}
				int dem2=0;
				for(int i=0;i<n;i++){
					if(v5[i]!=v6[i]) {
						dem2++;
					}
				}
				ans=min(ans,dem2);
				dem2=0;
				for(int i=0;i<n;i++){
					if(v6[i]!=v[i]){
						dem2++;
					}
				}
				ans=min(ans,dem2);
			}
		}
		cout<<ans<<endl;
	}
}

