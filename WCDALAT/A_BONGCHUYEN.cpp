#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
main(){
	freopen("volleyball.inp","r",stdin);
	freopen("volleyball.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;cin>>tc;
	while(tc--){
		int k,x,y;cin>>k>>x>>y;
		if(x<y) swap(x,y);
		if(k>x) {
					cout<<k-x<<" ";
		
		}
		else{
			if(k<=x){
				if(x==y) cout<<2<<" ";
				else{
					if(x-y==1) cout<<1<<" ";
					else{
						 cout<<0<<" ";
					}
				}
			}
			
		}
	}
	
}

