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
#define endl '\n'

const long long maxn=2e5+5;
const long long minn=-1e6;
const long long inf=1e18;
int n,m,q,sz[maxn],res[maxn],rq[maxn],par[maxn];
vector<pii>edge;
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		sz[i]=1;
		par[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		edge.pb({u,v});		
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>rq[i];
	}
}
int get(int u){
	if(u==par[u]) return u;
	return par[u]=get(par[u]);
}
void Union(int u,int v){
	u=get(u);
	v=get(v);
	if(u==v) return;
	if(sz[u]<sz[v]) swap(u,v);
	par[v]=u;
	sz[u]+=sz[v];
}
void solve(){
	for(int i=q;i>=1;i--){
		
	}
	

}
int main(){
	faster
	nhap();
	solve();
	




	return 0;
}
