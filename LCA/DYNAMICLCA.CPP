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

const long long maxn=1e6+5;
const long long minn=-1e6;
const long long inf=1e18;
int n,m,up[100001][18],h[100001];
vector<int>ke[100001];
void nhap(){
	for(int i=1;i<=n;i++){
		ke[i].clear();
		up[i][0]=i;
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		ke[u].pb(v);
		ke[v].pb(u);
	}
	h[1]=0;
}
void dfs(int u){
	for(int v:ke[u]){
		if(v==up[u][0]) continue;
		up[v][0]=u;
		h[v]=h[u]+1;
		for(int i=1;i<=17;i++){
			up[v][i]=up[up[v][i-1]][i-1];
		}
		dfs(v);
	}
}
int lca(int u,int v){
	if(h[u]!=h[v]){
		if(h[u]<h[v]) swap(u,v);
		int k=h[u]-h[v];
		for(int j=0;(1<<j)<=k;j++){
			if(k>>j&1) u=up[u][j];
		}
	}
	if(u==v) return u;
	int k=__lg(h[u]);
	for(int j=k;j>=0;j--){
		if(up[u][j]!=up[v][j]){
			u=up[u][j];
			v=up[v][j];
		}
	}
	return up[u][0];
}
void solve(){
	dfs(1);
	cin>>m;
	int root=1;
	for(int i=1;i<=m;i++){
		char c;cin>>c;
		if(c=='?'){
			int u,v;cin>>u>>v;
			int uv=lca(u,v);
			int ur=lca(u,root);
			int vr=lca(v,root);
			cout<<(uv^ur^vr)<<endl;

		}else cin>>root;
	}
	// int tmp;cin>>tmp;

}
int main(){
	faster
	while(cin>>n,n){
		nhap();
		solve();
	}
	
	




	return 0;
}
