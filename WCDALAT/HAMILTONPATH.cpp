#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e6;
const int minn=-1e6;
ll n;
vector<pair<ll,ll>>b[1001];
//vector<ll>v;
void nhap(){
	cin>>n;
	for(int i=0;i<n;i++){
		ll x,y;cin>>x>>y;
		b[x/1000].push_back({y,i});
	}
//	sort(v.begin(),v.end());
}
void xuly(){
	for(int i=0;i<=1000;i++){
		if(i%2==0){
			sort(b[i].begin(),b[i].end());
		}	
		else{
			sort(b[i].begin(),b[i].end(),greater<pair<ll,ll>>());
		}
	}
	for(int i=0;i<=1000;i++){
		for(auto it: b[i]) cout << it.second +1 << ' ';
	}
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	xuly();
}

