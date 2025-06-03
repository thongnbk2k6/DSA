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
int n,h[1001],up[1001][18];
vector<int>ke[1001];
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++){
		ke[i].clear();
		up[i][0]=i;
	}
	for(int i=1;i<=n;i++){
		int m;cin>>m;
		for(int j=1;j<=m;j++){
			int u;cin>>u;
			ke[i].pb(u);
			ke[u].pb(i);
		}
	}
	h[1]=0;
	
}
void dfs(int u){
	for(int v:ke[u]){
		if(v==up[u][0]) continue;
		h[v]=h[u]+1;
		up[v][0]=u;
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
			if((k>>j)&1) u=up[u][j];
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
void solve(int tc){
	dfs(1);
	int q;cin>>q;
	cout<<"Case "<<tc+1<<":"<<endl;
	while(q--){
		int u,v;cin>>u>>v;
		cout<<lca(u,v)<<endl;
	}


}
int main(){
	faster
	int tc;cin>>tc;
	while(tc--){
		nhap();
		solve(tc);
	}
	




	return 0;
}
