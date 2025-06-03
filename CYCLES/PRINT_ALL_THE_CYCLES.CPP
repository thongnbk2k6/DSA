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

const long long maxn=1e5+5;
const long long minn=-1e6;
const long long inf=1e18;
int n,m,color[maxn],parent[maxn],cycle_number;
vector<vector<int>>cycles;
vector<int>adj[maxn];
void preprocess(){
	memset(color,0,sizeof color);
	cycle_number = 0;
}

void nhap(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
void dfs_cycles(int u,int p){
	if(color[u]==2) return;
	if(color[u]==1){
		vector<int>v;
		cycle_number++;
		int cur = p;
		v.push_back(cur);
		while(cur!=u){
			cur = parent[cur];
			v.push_back(cur);
		}
		// v.push_back(u);
		cycles.push_back(v);
		return;
	}
	parent[u] = p;
	color[u] = 1;
	for(int v:adj[u]){
		if(v==p) continue;
		dfs_cycles(v,u);
	}
	color[u] = 2;
}
void solve(){
	dfs_cycles(1,0);
	for(int  i =0;i<cycle_number;i++){
		for(int v:cycles[i]) cout<<v<<" ";
			cout<<endl;
	}

}
int main(){
	faster
	preprocess();
	nhap();
	solve();




	return 0;
}
