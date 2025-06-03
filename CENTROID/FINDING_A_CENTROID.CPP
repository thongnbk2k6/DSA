#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define getbit(n,i) ((n>>i)&1)
#define fi first
#define sc second
#define pdb pair<double,double>
#define db double
#define endl '\n'

const long long maxn=2e5+5;
const long long minn=-1e6;
const long long inf=1e18;

int n,sz[maxn];
vector<int>adj[maxn];

void preprocess(){
	
}

void nhap(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
}
void dfs(int u,int parent){
	sz[u] = 1;
	for(int v:adj[u]){
		if(v==parent) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
int findCentroid(int v,int parent){
	for(int u:adj[v]){
		if(u==parent) continue;
		if(sz[u]>n/2){
			return (findCentroid(u,v));
		}
	}
	return v;
}
void solve(){
	dfs(1,-1);
	cout<<findCentroid(1,-1);

}
int main(){
	faster
	preprocess();
	nhap();
	solve();
	




	return 0;
}
