#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
int n,tinh[maxn],f[maxn],g[maxn];
bool vs[maxn];
vector<int>ke[1001];
void nhap(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		ke[u].push_back(v);
		ke[v].push_back(u);
	}
	memset(tinh,0,sizeof(tinh));
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
}
void predfs(int u,int parent){
	g[u]=inf;
	for(int v:ke[u]){
		if(v==parent) continue;
		f[v]=f[u]+1;
		predfs(v,u);
		g[u]=min(g[u],g[v]+1);
	}
	if(g[u]==inf) g[u]=0;
}
void dfs(int u,int parent ){
	if(f[u]>=g[u]){
		tinh[u]=1;
		return;
	}
	for(int v:ke[u]){
		if(v==parent) continue;
		dfs(v,u);
		tinh[u]+=tinh[v];
	}
	
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	predfs(1,0);
	dfs(1,0);
	cout<<tinh[1];
}

