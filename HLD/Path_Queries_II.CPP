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

int n,q,sz[maxn],parent[maxn],chainID[maxn],chainHead[maxn],pos[maxn],arr[maxn],curChain,curPos,h[maxn],val[maxn];
int ST[maxn*6];
vector<int>adj[maxn];

void preprocess(){
	h[1] = 0;
	parent[1] = 1;
	curPos = curChain = 1;
	
}

void nhap(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
void dfs(int v,int par){
	sz[v] = 1;
	for(int u:adj[v]){
		if(u==par) continue;
		h[u] = h[v] + 1;
		parent[u] = v;
		dfs(u,v);
		sz[v] += sz[u];
	}
}
void HLD(int v,int par){
	if(!chainHead[curChain]) chainHead[curChain] = v;
	chainID[v] = curChain;
	pos[v] = curPos;
	arr[curPos] = v;
	curPos++;
	int heavyChain = 0;
	for(int u:adj[v]){
		if(u==par) continue;
		if(heavyChain==0||sz[u]>sz[heavyChain]) heavyChain = u;
	}
	if(heavyChain) HLD(heavyChain,v);
	for(int u:adj[v]){
		if(u==par||u==heavyChain) continue;
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
	//luc nay ca u va v deu chung mot chain
	if(h[u]<h[v]) return u;
	return v;
}
void buildSegmentTree(int id,int l,int r){
	if(l==r){
		ST[id] = val[arr[l]];
		return;
	}
	int mid = (l+r)>>1;
	buildSegmentTree(id<<1,l,mid);
	buildSegmentTree(id<<1|1,mid+1,r);
	ST[id] = max(ST[id<<1],ST[id<<1|1]);

}
void update(int id,int l,int r,int p){
	if(l>p||r<p) return ;
	if(l==r&&l==p){
		ST[id] = val[arr[p]];
		return;
	}
	int mid = (l+r)>>1;
	update(id<<1,l,mid,p);
	update(id<<1|1,mid+1,r,p);
	ST[id] = max(ST[id<<1],ST[id<<1|1]);
}
int getMax(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(l>=u&&r<=v) return ST[id];
	int mid = (l+r)>>1;
	return max(getMax(id<<1,l,mid,u,v),getMax(id<<1|1,mid+1,r,u,v));
}
int queryMaxNodeValue(int u,int v){
	int ans = 0;
	int lca_u_v = LCA(u,v);
	while(chainID[u]!=chainID[lca_u_v]){
		ans = max(ans,getMax(1,1,n,pos[chainHead[chainID[u]]],pos[u]));
		u = parent[chainHead[chainID[u]]];
	}
	while(chainID[v]!=chainID[lca_u_v]){
		ans = max(ans,getMax(1,1,n,pos[chainHead[chainID[v]]],pos[v]));
		v = parent[chainHead[chainID[v]]];
	}
	// khi nay ca u va v deu nam tren cung mot chain
	if(h[u]<h[v]){
		ans = max(ans,getMax(1,1,n,pos[u],pos[v]));
	}else{
		ans = max(ans,getMax(1,1,n,pos[v],pos[u]));
	}
	return ans;

}
void solve(){
	dfs(1,-1);
	HLD(1,-1);
	buildSegmentTree(1,1,n);//n luc nay duoc xem nhu size cua chain
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op==1){
			int s,x;cin>>s>>x;
			val[s] = x;
			update(1,1,n,pos[s]);
		}else{
			int u,v;cin>>u>>v;
			cout<<queryMaxNodeValue(u,v)<<" ";
		}
	}

}
int main(){
	faster
	preprocess();
	nhap();
	solve();




	return 0;
}
