#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
int n;
ll tinh(vector<ll>v){
	if(v.size()<=1) return 0;
	int mid=(v.size()-1)/2;
	vector<ll>v1,v2;
	for(int i=0;i<=mid;i++){
		v1.pb(v[i]);
	}
	for(int i=mid+1;i<v.size();i++){
		v2.pb(v[i]);
	}
	ll res=tinh(v1)+tinh(v2);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	ll ans=inf;
	ll dem=0;
	for(int i=0;i<v1.size();i++){
		int j=0;
		while(j<v2.size()&&v1[i]>v2[j]){
			j++;
		}
		dem+=j;
	}
	ans=min(ans,dem);
	dem=0;
	for(int i=0;i<v2.size();i++){
		int j=0;
		while(j<v1.size()&&v2[i]>v1[j]){
			j++;
		}
		dem+=j;
		if(dem>ans) break;
	}
	ans=min(ans,dem);
	return res+ans;
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	vector<ll>v;
	for(int i=1;i<=pow(2,n);i++){
		ll x;cin>>x;
		v.pb(x);
	}
	cout<<tinh(v);
}

