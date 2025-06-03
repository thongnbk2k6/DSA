#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
ll n,r,b,len,ans=0;
vector<ll>v;
void nhap(){
	cin>>n>>r>>b;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
}
void xuly(){
	
}
main(){
//	freopen("fields.inp","r",stdin);
//	freopen("fields.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll sub;cin>>sub;
	nhap();
	xuly();
}

