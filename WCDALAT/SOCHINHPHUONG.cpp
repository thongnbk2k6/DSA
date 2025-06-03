#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;

bool kt(ll n){
	n=pow(n,2);
	map<ll,ll>mp;
	while(n!=0){
		mp[n%10]++;
		if(mp[n%10]>1) return 0;
		n/=10;
	}
	return 1;
}
main(){
	freopen("squares.inp","r",stdin);
	freopen("squares.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll k;cin>>k;
//	if(k>1e5) {
//		cout<<-1;return 0;
//	}
	int dem=0;
	bool ok=0;
	for(ll i=1;i<=1e5;i++){
		if(kt(i)){
			dem++;
			if(dem==k) {
				cout<<pow(i,2);
				ok=1;
				break;
			}
		}
	}
	if(!ok) cout<<-1<<endl;
	
}

