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
int n,k,root,up[200001][18],h[200001],lg2[200001];
vector<int>group[200001];
vector<int>ke[200001];
void nhap(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		group[x].pb(i);
		if(y==0){
			root=i;
		}else{
			ke[y].pb(i);
			ke[i].pb(y);
		}

	}
	h[root]=0;
}
void tinhlg2(){
	lg2[1]=0;
	for(int i=1;i<=n;i++){
		lg2[i]=lg2[i/2]+1;
	}
}
void dfs(int u){
	for(int v:ke[u]){
		if(v==up[u][0]) continue;
		up[v][0]=u;
		h[v]=h[u]+1;
		for(int i=1;i<18;i++){
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
	int k=lg2[h[u]];
	for(int i=k;i>=0;i--){
		if(up[u][i]!=up[v][i]){
			u=up[u][i];
			v=up[v][i];
		}
	}
	return up[u][0];
}
int dis(int u,int v){
	return h[u]+h[v]-2*h[lca(u,v)];
}
int maxdis(int i){
	int a=group[i][0],b=a,maxdis=0,tmpdis;
	for(int x:group[i]){
		tmpdis=dis(a,x);
		if(maxdis<tmpdis){
			maxdis=tmpdis;
			b=x;
		}
	}
	maxdis=0;
	for(int x:group[i]){
		tmpdis=dis(b,x);
		if(maxdis<tmpdis){
			maxdis=tmpdis;
		}
	}
	return maxdis;

}
void solve(){
	tinhlg2();
	dfs(root);
	// for(int i=1;i<=n;i++){
	// 	cout<<i<<": "<<h[i]<<endl;
	// }
	for(int i=1;i<=k;i++){
		cout<<maxdis(i)<<endl;
	}

}
int main(){
	faster
	nhap();
	solve();
	




	return 0;
}
