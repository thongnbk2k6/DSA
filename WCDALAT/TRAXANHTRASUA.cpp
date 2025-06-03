#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int sub,n,k;
float ans=0.0;
vector<pair<int,int>>tx,ts;
void nhap(){
	cin>>sub>>n>>k;
//	tx.push_back({0,0});
//	ts.push_back({0,0});
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		if(y==1) {
			tx.push_back({x,i});
		}
		else ts.push_back({x,i});
	}
	sort(tx.begin(),tx.end(),greater<pair<int,int>>());
	sort(ts.begin(),tx.end());
}
vector<int>vt;
void xuly(){
	if(tx.size()>=k-1){
		int i=0;
		for(i=0;i<k-1;i++){
			pair<int,int>t1=tx[i];
			ans+=t1.first/2.0;
		}
		//i=k-1;
		pair<int,int>x1=tx[i];
		pair<int,int>x2=ts[0];
		ans+=min(x1.first/2.0,x2.first/2.0);
		i++;
		for(i;i<tx.size();i++){
			pair<int,int>t1=tx[i];
			ans+=t1.first/2.0;
		}
		for(int j=1;j<=ts.size();j++){
			pair<int,int>t2=ts[j];
			ans+=1.0*t2.first;
		}
	}
	else if(tx.size()<k-1){
		int i=0;
		for(i;i<tx.size();i++){
			pair<int,int>t1=tx[i];
			ans+=t1.first/2.0;
		}
		for(int j=i;j<k;j++){
			pair<int,int>t2=ts[j];
			ans+=t2.first;
		}
	}
	cout<<ans;
}
main(){
	nhap();
	xuly();
	
}
