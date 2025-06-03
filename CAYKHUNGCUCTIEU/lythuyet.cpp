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
int n,m,sz[1001],parent[1001],min_sum_val,vs[1001];
struct Edge{
	int u,v,val;
};
bool cmp(const Edge&a,const Edge &b){
	return (a.val<b.val);
}
vector<Edge>edges;
vector<int>adj[1001];
void preprocess(){
	min_sum_val = 0;
	memset(vs,0,sizeof vs);
}

void nhap(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,val;cin>>u>>v>>val;
		edges.push_back({u,v,val});
	}

}
int find(int u){
	if(u==parent[u]) return u;
	return parent[u] = find(parent[u]);
}
bool Union(int u,int v){
	u = find(u);
	v = find(v);
	if(u==v) return 0;
	if(sz[u]<sz[v]) swap(u,v);
	sz[u] += sz[v];
	parent[v] = u ;
	return 1;
}
void dfs(int u){
	vs[u] = 1;
	for(int v:adj[u]){
		if(!vs[v]){
			cout<<u<<" "<<v<<endl;
			dfs(v);
		}
	}
}
void solve(){
	sort(all(edges),cmp);
	for(int i=1;i<=n;i++){
		sz[i] = 1;
		parent[i] = i;
	}
	for(int i=0;i<m;i++){
		int  u = edges[i].u,v = edges[i].v,val = edges[i].val;
		if(Union(u,v)){
			adj[u].push_back(v);
			adj[v].push_back(u);
			min_sum_val +=val;
		}
	}
	dfs(1);
	cout<<min_sum_val;

}
int main(){
	faster
	preprocess();
	nhap();
	solve();
	




	return 0;
}
