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

int n,q,val[maxn],chainID[maxn],chainHead[maxn],pos[maxn],arr[maxn],parent[maxn],sz[maxn],h[maxn],curChain,curPos;
vector<int>adj[maxn];

void preprocess(){
	h[1] = 0;
	curChain = 1;
	curPos = 1;
	parent[1] = 1;
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
	for(int u:adj[v]){//tim canh nang
		if(u==par) continue;
		if(!heavyChain||(sz[u]>sz[heavyChain])) heavyChain = u;
	}
	if(heavyChain) HLD(heavyChain,v);
	for(int u:adj[v]){//tim canh nhe
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
	//u va v da cung chain
	if(h[u]<h[v]) return u;
	return v;
}
long long ST[maxn*4];
void buildSegmentTree(int id,int l,int r){
	if(l==r){
		ST[id] = val[arr[l]];
		return;
	}
	int mid = (l+r)>>1;
	buildSegmentTree(id<<1,l,mid);//id*2
	buildSegmentTree(id<<1|1,mid+1,r);//id*2+1
	ST[id] = ST[id<<1] + ST[id<<1|1];

}
long long getSum(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(l>=u&&r<=v){
		return ST[id];
	}
	int mid = (l+r)>>1;
	return getSum(id<<1,l,mid,u,v)+getSum(id<<1|1,mid+1,r,u,v);
}
void Update(int id,int l,int r,int p){
	if(l>p||r<p) return;
	if(l==r&&l==p) {
		ST[id] = val[arr[p]];
		return;
	}
	int mid = (l+r)>>1;
	Update(id<<1,l,mid,p);
	Update(id<<1|1,mid+1,r,p);
	ST[id] = ST[id<<1] + ST[id<<1|1];
}
long long query(int u){
	long long ans = 0;
	while(chainID[u]!=chainID[1]){
		ans += getSum(1,1,n,pos[chainHead[chainID[u]]],pos[u]);
		u = parent[chainHead[chainID[u]]];
	}
	ans += getSum(1,1,n,pos[chainHead[chainID[1]]],pos[u]);
	return ans;
}
void solve(){
	dfs(1,-1);
	// for(int i=1;i<=n;i++){
	// 	cout<<i<<" "<<h[i]<<" "<<sz[i]<<endl;
	// }
	HLD(1,-1);
	// cout<<endl;
	// for(int i=1;i<=n;i++){
	// 	cout<<i<<" "<<chainHead[i]<<" "<<parent[chainHead[chainID[i]]] <<" "<<chainID[i]<<" "<<pos[i]<<" "<<endl;
	// }
	// cout<<pos[1]<<" "<<pos[n];
	// cout<<curPos;
	// return;
	// exit(0);
	buildSegmentTree(1,1,n);
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op==1){
			int s,x;cin>>s>>x;
			val[s] = x;
			Update(1,1,n,pos[s]);
		}else{
			int s;cin>>s;
			cout<<query(s)<<endl;
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
