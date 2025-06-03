#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;


main(){
	freopen("colors.inp","r",stdin);
	freopen("colors.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll sub,n,c;cin>>sub>>n>>c;
	for(int i=1;i<n;i++){
		ll u,v;cin>>u>>v;
	}
	if(n<=1||c<=1) cout<<0<<endl;
	else{
		int s=1;
		for(int i=1;i<n;i++){
			s=(s*(c-1))%998244353;
		}
		cout<<(c*s)%998244353<<endl;
	}
}

