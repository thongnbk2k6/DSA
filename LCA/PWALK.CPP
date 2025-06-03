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
int n,q,up[1001][10],h[1001],f[1001],lg2[1001];
vector<pii>ke[1001];
void tinhlg2(){
	lg2[1]=0;
	for(int i=2;i<=n;i++){
		lg2[i]=lg2[i/2]+1;
	}
}
void nhap(){
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int u,v,w;cin>>u>>v>>w;
		ke[u].pb({v,w});
		ke[v].pb({u,w});
	}
	memset(h,0,sizeof(h));
	memset(f,0,sizeof(f));
}
void dfs(int u){
	for(pii e:ke[u]){
		int v=e.fi,w=e.sc;
		if(v==up[u][0]) continue;
		h[v]=h[u]+1;
		f[v]=f[u]+w;
		up[v][0]=u;
		for(int j=1;j<10;j++){
			up[v][j]=up[up[v][j-1]][j-1];
		}
		dfs(v);
	}
}
int lca(int u,int v){
	if(h[u]!=h[v]){
		if(h[u]<h[v]){
			swap(u,v);
			int k=h[u]-h[v];
			for(int j=0;(1<<j)<=k;j++){
				if(k>>j&1) u=up[u][j];
			}
		}
	}
	if(u==v) return u;
	int k=lg2[h[u]];
	for(int j=k;j>=0;j--){
		if(up[u][j]!=up[v][j]){
			u=up[u][j];
			v=up[v][j];
		}
	}
	return up[u][0];




}
int dis(int u,int v){
	return f[u]+f[v]-2*f[lca(u,v)];
}
void solve(){
	dfs(1);
	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		cout<<dis(u,v)<<endl;
	}

}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
