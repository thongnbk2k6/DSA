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
int n,color[maxn],ans[maxn];
vector<int>adj[maxn];
set<int>se[maxn];
void preprocess(){
	
}

void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>color[i];
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
void dfs(int v,int parent){
	se[v].insert(color[v]);
	for(int u:adj[v]){
		if(u==parent) continue;
		dfs(u,v);
		if(se[v].size()<se[u].size()) swap(se[v],se[u]);
		for(const int &value:se[u]) se[v].insert(value);
	}
	ans[v] = int(se[v].size());
	

}
void solve(){
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}

}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
