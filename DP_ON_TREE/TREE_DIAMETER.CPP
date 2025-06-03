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
int n,dis[maxn],max_dist,farthest_node;
vector<int>adj[maxn];
void preprocess(){
	memset(dis,0,sizeof dis);
	max_dist = 0;
}

void nhap(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
}
void dfs(int v,int parent){
	for(int u:adj[v]){
		if(u==parent) continue;
		dis[u] = dis[v] + 1;
		if(dis[u]>max_dist){
			farthest_node = u;
			max_dist = dis[u];
		}
		dfs(u,v);

	}
}
void solve(){
	dfs(1,-1);
	preprocess();
	dfs(farthest_node,-1);
	cout<<max_dist;

}
int main(){
	faster
	preprocess();
	nhap();
	solve();




	return 0;
}
