#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define bit(n,i) ((n>>i)&1)
#define fi first
#define sc second
#define pdb pair<double,double>
#define db double

const long long maxn=1e5+5;
const long long minn=-1e6;
const long long inf=1e18;
int n,q,c[maxn],r[maxn],sz[maxn];
map<int,int>mp[maxn];
void nhap(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		r[i]=i;
		mp[i][c[i]]=1;
		sz[i]=1;
	}
}
int get(int u){
	if(u==r[u]) return u;
	return r[u]=get(r[u]);
}
void Union(int u,int v){
	u=get(u);
	v=get(v);
	if(u==v) return;
	if(sz[u]!=sz[v]){
		if(sz[u]<sz[v]) swap(u,v);
	}
	r[v]=u;
	sz[u]+=sz[v];
	for(pii x:mp[v]){
		mp[u][x.fi]+=x.sc;
	}

}
int somau(int u,int mau){
	u=get(u);
	return mp[u][mau];
}
void solve(){
	for(int i=1;i<=q;i++){
		int tv;cin>>tv;
		if(tv==1){
			int u,v;cin>>u>>v;
			Union(u,v);
		}else{
			int u,mau;cin>>u>>mau;
			cout<<somau(u,mau)<<endl;
		}
	}

}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
