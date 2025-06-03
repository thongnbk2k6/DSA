#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
int n;
ll cal(vector<ll>v){
	if(v.size()<=1) return 0;
	int mid=(v.size()-1)/2;
	vector<ll>v1,v2;
	for(int i=0;i<=mid;i++){
		v1.push_back(v[i]);
	}
	for(int i=mid+1;i<v.size();i++){
		v2.push_back(v[i]);
	}
	ll res=cal(v1)+cal(v2);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	ll best=inf;
	ll cnt=0;
	for(int i=0,j=0;i<v1.size();i++){
		while(j<v2.size()&&v1[i]>v2[j]){
			j++;
		}
		cnt+=j;
	}
	best=min(best,cnt);
	cnt=0;
	for(int i=0,j=0;i<v2.size();i++){
		while(j<v1.size()&&v2[i]>v1[j]) j++;
		cnt+=j;
		if(cnt>best) break;
	}
	best=min(best,cnt);
	return best+res;
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	vector<ll>v;
	for(int i=1;i<=pow(2,n);i++){
		int x;cin>>x;
		v.push_back(x);
	}
	cout<<cal(v);
}

