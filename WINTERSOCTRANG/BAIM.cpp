#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6+1000;
const long long minn=-1e6;
//const long long MAX=1001000;
int t,l[maxn],p[maxn];
bool prime[maxn];
void sangnt(){
	fill(prime,prime+maxn+1,1);
	prime[0]=0;
	prime[1]=1;
	for(int i=2;i*i<=maxn;i++){
		if(prime[i]){
			for(int j=i*i;j<=maxn;j+=i){
				prime[j]=0;
			}
		}
	}
}
vector<pair<ll,int>>v;
void xuly(){
	p[1]=1;
	for(int i=2;i<=maxn;i++){
		if(!prime[i]){
			ll pw=i;
			while(1LL maxn*maxn/pw>=i){
				pw*=p;
				v.push_back({pw,i});
			}
		}
	}
	sort(v.begin(),v.end());
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	sangnt();
	xuly();
	for(int i=1;i<=t;i++){
		int n;cin>>n;
		
	}
	
}

