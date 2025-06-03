#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define piii int,pair<int,int>
#define bit(n,i) ((n>>i)&1)
#define fi first
#define sc second
#define pdb pair<double,double>
#define db double
#define endl '\n'

const long long maxn=1e6+5;
const long long minn=-1e6;
const long long MOD=1e9+7;
const long long inf=1e18;
ll n,q,a[maxn],bit[maxn],bit2[maxn];
void update(int vt,int val){
	while(vt<=n){
		bit[vt]+=val;
		vt+=(vt&-vt);
	}
}
void update2(int vt,int val){
	while(vt<=n){
		bit2[vt]+=val;
		vt+=(vt&-vt);
	}
}
ll getsum1(int vt){
	ll ans=0;
	while(vt){
		ans+=bit[vt];
		vt-=(vt&-vt);
	}
	return ans;
}
ll getsum2(int vt){
	ll ans=0;
	while(vt){
		ans+=bit2[vt];
		vt-=(vt&-vt);
	}
	return ans;
}
void updatedoan(int u,int v,int val){
	update(u,(n-u+1)*val);
	update(v+1,-(n-v)*val);
	update2(u,val);
	update2(v+1,-val);
}

ll prefix(int vt){
	return getsum1(vt)-getsum2(vt)*(n-vt);
}
ll tongdoan(int l,int r){
	return prefix(r)-prefix(l-1);
}
void nhap(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(i,a[i]);
	}
}
void solve(){
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op==1){
			int u,v,x;cin>>u>>v>>x;
			updatedoan(u,v,x);
		}else{
			int u,v;cin>>u>>v;
			cout<<tongdoan(u,v)<<endl;
		}
	}

}
int main(){
	faster
	nhap();
	solve();




	return 0;
}

