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
int n,numChild[maxn];
long long subtreeAns[maxn],ans[maxn];
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
void dfs1(int v,int parent){
	numChild[v] = 1;
	subtreeAns[v] = 0;
	for(int u:adj[v]){
		if(u==parent) continue;
		dfs1(u,v);
		numChild[v] += numChild[u];
		subtreeAns[v] += subtreeAns[u] + numChild[u];
	}
	
}
void dfs2(int v,int parent,long long ans_par){
	ans[v] = subtreeAns[v] + ans_par + n - numChild[v];
	for(int u:adj[v]){
		if(u==parent) continue;
		dfs2(u,v,ans[v] - subtreeAns[u] - numChild[u]);
	}
}
void solve(){
	dfs1(1,-1);
	dfs2(1,-1,0ll);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}

}
int main(){
	faster
	preprocess();
	nhap();
	solve();




	return 0;
}
