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
int n,ST[maxn*4],parent[maxn],h[maxn],sz[maxn],chainID[maxn],chainHead[maxn],pos[maxn],arrEdgeValue[maxn],curChain,curPos;
vector<pair<int,int>>adj[maxn];
vector<pair<int,int>>edge;
void preprocess(){
	h[1] = 0;
	curChain = 1;
	curPos = 1;
	//khong lay pos[0] va pos[last] chi lay tu [1->last-1]
	for(int i=1;i<=n;i++){
		adj[i].clear();
	}
	edge.resize(n+1);
	memset(parent,0,sizeof parent);
	memset(sz,0,sizeof sz);
	memset(chainHead,-1,sizeof chainHead);
	memset(h,0,sizeof h);
	memset(ST,0,sizeof ST);
	memset(arrEdgeValue,0,sizeof arrEdgeValue);
}

void nhap(){
	for(int i=1;i<n;i++){
		int u,v,w;cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
		edge[i] = {u,v};
	}

}
void dfs(int v,int par){
	sz[v] = 1;
	for(pair<int,int>cur_pair:adj[v]){
		int u = cur_pair.fi;
		if(u==par) continue;
		h[u] = h[v] + 1;
		parent[u] = v;
		dfs(u,v);
		sz[v]+=sz[u];
	}
}
void HLD(int v,int par,int val){
	if(chainHead[curChain]==-1){
		chainHead[curChain] = v;
	}
	chainID[v] = curChain;
	pos[v] = curPos;
	arrEdgeValue[curPos] = val;
	curPos++;
	int heavyNode = 0,heavyNodeVal;
	for(pair<int,int> cur_pair:adj[v]){
		int u = cur_pair.fi;
		int w = cur_pair.sc;
		if(u==par) continue;
		if(heavyNode==0||sz[heavyNode]<sz[u]) {
			heavyNode = u;
			heavyNodeVal = w;
		}
	}
	if(heavyNode){
		HLD(heavyNode,v,heavyNodeVal);
	}
	for(pair<int,int> cur_pair:adj[v]){
		int u = cur_pair.fi;
		int w = cur_pair.sc;
		if(u==par||u==heavyNode) continue;
		curChain++;
		HLD(u,v,w);
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
void buildSegmentTree(int id,int l,int r){
	if(l==r){
		ST[id] = arrEdgeValue[l];
		return;
	}
	int mid = (l+r)>>1;
	buildSegmentTree(id<<1,l,mid);
	buildSegmentTree(id<<1|1,mid+1,r);
	ST[id] = max(ST[id<<1],ST[id<<1|1]);
}
void updateEdge(int id,int l,int r,int position,int val){
	if(l>position||r<position) return;
	if(l==r&&l==position){
		ST[id] = val;
		arrEdgeValue[position] = val;
		return;
	}
	int mid = (l+r)>>1;
	if(position<=mid){
		updateEdge(id<<1,l,mid,position,val);
	}else{
		updateEdge(id<<1|1,mid+1,r,position,val);
	}
	ST[id] = max(ST[id<<1],ST[id<<1|1]);
}
int getMax(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(l>=u&&r<=v) return ST[id];
	int mid = (l+r)>>1;
	int t1 = getMax(id<<1,l,mid,u,v);
	int t2 = getMax(id<<1|1,mid+1,r,u,v);
	return max(t1,t2);
}
int getMaxNodeValue(int u,int v){
	int lca_u_v = LCA(u,v);
	int ans = 0;
	while(chainID[u]!=chainID[lca_u_v]){
		ans = max(ans,getMax(1,1,curPos,pos[chainHead[chainID[u]]],pos[u]));
		u = parent[chainHead[chainID[u]]];
	}
	while(chainID[v]!=chainID[lca_u_v]){
		ans = max(ans,getMax(1,1,curPos,pos[chainHead[chainID[v]]],pos[v]));
		v = parent[chainHead[chainID[v]]];
	}
	if(h[u]<h[v]) ans = max(ans,getMax(1,1,curPos,pos[u],pos[v]));
	else ans = max(ans,getMax(1,1,curPos,pos[v],pos[u]));
	return ans;
}
void solve(){
	dfs(1,-1);
	HLD(1,-1,0);
	curPos--;// chi lay mang ST tu [1->curPos-1]
	buildSegmentTree(1,1,curPos);
	string s;
	while(1){
		cin.ignore(1);
		cin>>s;
		if(s[0]=='D') break;
		if(s[0]=='C'){
			int i,x;cin>>i>>x;
			// cout<<i<<" "<<x<<endl;
			int u = edge[i].fi, v = edge[i].sc;
			if(h[u]>h[v]) swap(u,v);
			updateEdge(1,1,curPos,pos[u],x);
			// cout<<"pos "<<pos[u]<<endl;
		}else{
			int u,v;cin>>u>>v;
			// cout<<u<<" "<<v<<endl;
			cout<<getMaxNodeValue(u,v)<<endl;
		}
	}
	// cout<<curPos;
	// cout<<curChain;
	// cout<<getMaxNodeValue(1,3);
	// cout<<LCA(8,5);
}
int main(){
	faster
	int tc;cin>>tc;
	while(tc--){
		cin>>n;
		preprocess();
		nhap();
		solve();
	}
	




	return 0;
}
