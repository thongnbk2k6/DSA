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

int n,q,parent[maxn],sz[maxn],chainID[maxn],chainHead[maxn],pos[maxn],arr[maxn],h[maxn],curChain,curPos;
vector<int>adj[maxn];


void preprocess(){
	h[1] = 0;
	curPos = 1;
	curChain = 1;
	parent[1] = 1;

}

void nhap(){
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		int u;cin>>u;
		adj[u].push_back(i);
		adj[i].push_back(u);
	}

}
void dfs(int v,int p){
	sz[v] = 1;
	for(int u:adj[v]){
		if(u==p) continue;
		h[u] = h[v] + 1;
		parent[u] = v;
		dfs(u,v);
		sz[v]+=sz[u];
	}
}
void HLD(int v,int p){
	if(chainHead[curChain]==0) chainHead[curChain] = v;
	chainID[v] = curChain;
	pos[v] = curPos;
	arr[curPos] = v;
	curPos++;
	int heavyChain = 0;
	for(int u:adj[v]){
		if(u==p) continue;
		if(heavyChain==0||sz[u]>sz[heavyChain]) heavyChain = u;
	}
	if(heavyChain) HLD(heavyChain,v);
	for(int u:adj[v]){
		if(u==p||u==heavyChain) continue;
		curChain++;
		HLD(u,v);
	}
}
int LCA(int u,int v){
	while(chainID[u]!=chainID[v]){
		if(chainID[u]>chainID[v]){
			u = parent[chainHead[chainID[u]]];
		}else{
			v = parent[chainHead[chainID[v]]];
		}
	}
	if(h[u]<h[v]) return u;
	return v;
}
void solve(){
	dfs(1,-1);
	HLD(1,-1);
	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		cout<<LCA(u,v)<<endl;
	}

}
int main(){
	faster
	preprocess();
	nhap();
	solve();
	




	return 0;
}
