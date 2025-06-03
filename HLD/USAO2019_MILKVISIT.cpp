#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define piii int,pair<int,int>
#define bit(n,i) ((n>>i)&1)
#define fi first
#define sc second
#define pdb pair<double,double>
#define db double

const long long maxn=1e6;
const long long minn=-1e6;
const long long MOD=1e9+7;
const long long inf=1e18;
int n,m,a[maxn],h[maxn],parent[maxn],Sz[maxn];
int chainID[maxn],chainhead[maxn],par[maxn][18],arr[maxn],pos[maxn];
int sg[maxn*4];
int curchain,curpos;
vector<int>ke[100001];

void nhap(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;cin>>c;
		a[i]=(c=='H'?1:0);
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		ke[u].pb(v);
		ke[v].pb(u);
	}
	h[1]=0;
	par[1][0]=1;
	curchain=curpos=1;
}
void dfs(int u,int pre){
	Sz[u]=1;
	for(int v:ke[u]){
		if(v==pre) continue;
		h[v]=h[u]+1;
		if(par[u][0]!=v) par[v][0]=u;
		parent[v]=u;
		dfs(v,u);
		Sz[u]+=Sz[v];
	}
}
void HLD(int u,int pre){
	if(!chainhead[curchain]) chainhead[curchain]=u;
	chainID[u]=curchain;
	pos[u]=curpos;
	arr[curpos]=u;
	curpos++;
	int nxt=0;
	for(int v:ke[u]){
		if(v!=pre){
			if(nxt==0||Sz[v]>Sz[nxt]) nxt=v;
		}
	}
	if(nxt)	HLD(nxt,u);
	//canh nhe
	for(int v:ke[u]){
		if(v!=pre&&v!=nxt){
			curchain++;
			HLD(v,u);
		}
	}
}
int lca(int u,int v){
	if(h[u]!=h[v]){
		if(h[u]<h[v]) swap(u,v);
		for(int i=17;i>=0;i--){
			if(h[par[u][i]]>=h[v]){
				u=par[u][i];
			}
		}
	}
	if(u==v) return u;
	for(int i=17;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}
void build(int id,int l,int r){
	if(l==r){
		sg[id]=a[arr[l]];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	sg[id]=sg[id*2]+sg[id*2+1];
}
ll getsum(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(u<=l&&r<=v) return sg[id];
	int mid=(l+r)/2;
	return getsum(id*2,l,mid,u,v)+getsum(id*2+1,mid+1,r,u,v);
}
int dist(int u,int v){
	return h[u]+h[v]-2*h[lca(u,v)]+1;
}
void tinh(int u,int v,int c){
	int kc=dist(u,v);
	int res=lca(u,v);
	int ans=0;
	while(chainID[u]!=chainID[res]){
		ans+=getsum(1,1,n,pos[chainhead[chainID[u]]],pos[u]);
		u=parent[chainhead[chainID[u]]];
		
	}
	while(chainID[v]!=chainID[res]){
		ans+=getsum(1,1,n,pos[chainhead[chainID[v]]],pos[v]);
		v=parent[chainhead[chainID[v]]];
		
	}
	if(h[u]<h[v]){
		ans+=getsum(1,1,n,pos[u],pos[v]);
	}else{
		ans+=getsum(1,1,n,pos[v],pos[u]);
	}
	if(ans==kc){//toan bo cac dinh tren duong di deu la H
		if(c==0) cout<<0;
		if(c==1) cout<<1;
	}
	//neu toan bo cac dinh tren duong di deu la G
	if(ans==0){
		if(c==0) cout<<1;
		if(c==1) cout<<0;
	}
	if(ans>0&&ans<kc) cout<<1;
	
	
	
	
	
}
void solve(){
	for(int i=1;i<=m;i++){
		int u,v,x;char c;cin>>u>>v>>c;
		x=(c=='H'?1:0);
		tinh(u,v,x);
	}

}
int main(){
	faster
	nhap();
	dfs(1,1);
	for(int j=1;j<=17;j++){
		for(int i=1;i<=n;i++){
			par[i][j]=par[par[i][j-1]][j-1];
		}
	}
	HLD(1,1);
	build(1,1,n);
	solve();



	return 0;
}

