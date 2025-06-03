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
int n,q;
vector<int>ke[100001];
int a[maxn];
int parent[maxn],h[maxn],Sz[maxn],pos[maxn],arr[maxn],chainID[maxn],chainhead[maxn],curchain,curpos;
int par[maxn][18];

void dfs(int u,int pre){
	Sz[u]=1;
	for(int v:ke[u]){
		if(v==pre) continue;
		h[v]=h[u]+1;
		parent[v]=u;
		if(par[u][0]!=v) par[v][0]=u;
		dfs(v,u);
		Sz[u]+=Sz[v];
	}
}
void Hld(int u,int pre){
	if(!chainhead[curchain]){
		chainhead[curchain]=u;
	}
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
	if(nxt) Hld(nxt,u);
	for(int v:ke[u]){
		if(v!=pre&&v!=nxt){
			curchain++;
			Hld(v,u);
		}
	}
}
int lca(int u,int v){
	if(h[u]!=h[v]){
		if(h[u]<h[v]){
			swap(u,v);
		}
		for(int j=17;j>=0;j--){
			if(h[par[u][j]]>=h[v]){
				u=par[u][j];
			}
		}
	}
	if(u==v) return u;
	for(int j=17;j>=0;j--){
		if(par[u][j]!=par[v][j]){
			u=par[u][j];
			v=par[v][j];
		}
	}
	return par[u][0];
}
int sg[maxn*4];
void build(int id,int l,int r){
	if(l==r){
		sg[id]=a[arr[l]];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	sg[id]=sg[id*2]^sg[id*2+1];
}
void update(int id,int l,int r,int pos,int val){
	if(l>pos||r<pos) return;
	if(l==r&&l==pos){
		sg[id]=val;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	sg[id]=sg[id*2]^sg[id*2+1];
}
int calc(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(u<=l&&r<=v) return sg[id];
	int mid=(l+r)/2;
	return calc(id*2,l,mid,u,v)^calc(id*2+1,mid+1,r,u,v);
}
void upd(int vt,int val){
	update(1,1,n,pos[vt],val);
}
int tinh(int u,int v){
	int res=lca(u,v);
	int ans=0;
	while(chainID[u]!=chainID[res]){
		ans^=calc(1,1,n,pos[chainhead[chainID[u]]],pos[u]);
		u=parent[chainhead[chainID[u]]];
	}
	while(chainID[v]!=chainID[res]){
		ans^=calc(1,1,n,pos[chainhead[chainID[v]]],pos[v]);
		v=parent[chainhead[chainID[v]]];
	}
	if(h[u]<h[v]){
		ans^=calc(1,1,n,pos[u],pos[v]);
	}else{
		ans^=calc(1,1,n,pos[v],pos[u]);
	}
	return ans;
	
	
}
void solve(){
	
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op==1){
			int vt,val;cin>>vt>>val;
			upd(vt,val);
		}else{
			int u,v;cin>>u>>v;
			cout<<tinh(u,v)<<endl;
		}
	}

}
void nhap(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		ke[u].pb(v);
		ke[v].pb(u);
	}
	curchain=curpos=1;
	h[1]=0;
	par[1][0]=1;
}
int main(){
	faster
	nhap();
	dfs(1,1);
	Hld(1,1);
	for(int j=1;j<=17;j++){
		for(int i=1;i<=n;i++){
			par[i][j]=par[par[i][j-1]][j-1];
		}
	}
	build(1,1,n);
	solve();
//	cout<<lca(4,5);
	
	return 0;
}

