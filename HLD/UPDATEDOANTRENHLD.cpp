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

const long long maxn=1e6+5;
const long long minn=-1e6;
const long long MOD=1e9+7;
const long long inf=1e18;
int n,q,a[maxn];
int curchain,curpos,chainhead[maxn],chainID[maxn],pos[maxn];
int parent[maxn],par[maxn][18],h[maxn],Sz[maxn],arr[maxn];
ll sg[maxn*4],lz[maxn*4];
//cay2
int par2[maxn][18],h2[maxn];
vector<int>ke[100001];
vector<int>ke2[100001];
vector<pii>cay;
void nhap(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		ke[u].pb(v);
		ke[v].pb(u);
		cay.pb({u,v});
	}
	h[1]=0;
	curchain=curpos=1;
	par[1][0]=1;
	memset(lz,0,sizeof(lz));
	memset(sg,0,sizeof(sg));
	parent[1]=1;
	par2[1][0]=1;
	h2[1]=0;
	
}
void dfs(int u,int pre){
	Sz[u]=1;
	for(int v:ke[u]){
		if(v==pre) continue;
		h[v]=h[u]+1;
		parent[v]=u;
		if(par[u][0]!=v){
			par[v][0]=u;
		}
		dfs(v,u);
		Sz[u]+=Sz[v];
	}
}
void Hld(int u,int pre){
	if(!chainhead[curchain]){
		chainhead[curchain]=u;
	}
	chainID[u]=curchain;
	arr[curpos]=u;
	pos[u]=curpos;
	curpos++;
	int nxt=0;
	for(int v:ke[u]){
		if(v!=pre){
			if(!nxt||Sz[v]>Sz[nxt]){
				nxt=v;
			}
		}
	}
	if(nxt){
		Hld(nxt,u);
	}
	for(int v:ke[u]){
		if(v!=pre&&v!=nxt){
			curchain++;
			Hld(v,u);
		}
	}
}
void taocay2(){
	for(int i=0;i<cay.size();i++){
		int u=cay[i].fi,v=cay[i].sc;
		ke2[pos[u]].pb({pos[v]});
		ke2[pos[v]].pb({pos[u]});
//		cout<<pos[u]<<" "<<pos[v]<<endl;
	}
}
void dfs2(int u,int pre){
	for(int v:ke2[u]){
		if(v==pre) continue;
		h2[v]=h2[u]+1;
		if(par2[u][0]!=v){
			par2[v][0]=u;
		}
		dfs2(v,u);
	}
}
int lca(int u,int v){
	if(h[u]!=h[v]){
		if(h[u]<h[v]){
			swap(u,v);
		}
		for(int i=17;i>=0;i--){
			if(h[par[u][i]]>=h[v]) u=par[u][i];
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
int lca2(int u,int v){
	if(h2[u]!=h2[v]){
		if(h2[u]<h2[v]){
			swap(u,v);
		}
		for(int i=17;i>=0;i--){
			if(h2[par2[u][i]]>=h2[v]){
				u=par2[u][i];
			}
		}
	}
	if(u==v) return u;
	for(int i=17;i>=0;i--){
		if(par2[u][i]!=par2[v][i]){
			u=par2[u][i];
			v=par2[v][i];
		}
	}
	return par2[u][0];
}
//void build(int id,int l,int r){
//	if(l==r){
//		sg[id]=a[arr[l]];
//		return;
//	}
//	int mid=(l+r)/2;
//	build(id*2,l,mid);
//	build(id*2+1,mid+1,r);
//	sg[id]=sg[id*2]+sg[id*2+1];
//}
void push(int id){
	if(lz[id]){
		sg[id*2]+=lz[id];
		sg[id*2+1]+=lz[id];
		lz[id*2]+=lz[id];
		lz[id*2+1]+=lz[id];
		lz[id]=0;
	}
}
int price(int u,int v){
	return h2[u]+h2[v]-2*h2[lca2(u,v)]+1;
}
ll getsum(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(u<=l&&r<=v){
		return sg[id];
	}
	int mid=(l+r)/2;
	push(id);
	return getsum(id*2,l,mid,u,v)+getsum(id*2+1,mid+1,r,u,v);
	
}
void update(int id,int l,int r,int u,int v,int val){
	if(l>v||r<u) return;
	if(u<=l&&r<=v){
		sg[id]+=val;
		lz[id]+=val;
		return;
	}
	int mid=(l+r)/2;
	push(id);
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	sg[id]=sg[id*2]+sg[id*2+1];
	
}
void updatedoan(int u,int v,int val){
	int res=lca(u,v);
	while(chainID[u]!=chainID[res]){
		update(1,1,n,pos[chainhead[chainID[u]]],pos[u],price(pos[chainhead[chainID[u]]],pos[u])*val);
		u=parent[chainhead[chainID[u]]];
	}
	while(chainID[v]!=chainID[res]){
		update(1,1,n,pos[chainhead[chainID[v]]],pos[v],price(pos[chainhead[chainID[v]]],pos[v])*val);
		v=parent[chainhead[chainID[v]]];
	}
	if(h[u]<h[v]){
		update(1,1,n,pos[u],pos[v],val*price(pos[u],pos[v]));
	}else{
		update(1,1,n,pos[v],pos[u],val*price(pos[u],pos[v]));
	}
	
}
ll tinh(int u,int v){
	int res=lca(u,v);
	ll ans=0;
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
	return ans;
}
void solve(){
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op==1){
			int u,v;cin>>u>>v;
			cout<<tinh(u,v);
		}
		if(op==2){
			int u,v,val;cin>>u>>v>>val;
			updatedoan(u,v,val);
		}
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
	Hld(1,1);
	taocay2();
	dfs2(1,1);
	for(int j=1;j<=17;j++){
		for(int i=1;i<=n;i++){
			par2[i][j]=par2[par2[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		update(1,1,n,i,i,a[arr[i]]);
	}
	solve();
//	cout<<h2[5]<<" "<<h2[lca(5,5)];
//	cout<<price(5,5);
//	cout<<price(3,1);
//	cout<<price(1,5);
//	cout<<pos[4]<<" "<<pos[5]<<endl;
//	cout<<pos[1]<<" "<<pos[3]<<" "<<pos[4];
//	cout<<tinh(2,4);
//	cout<<parent[chainhead[chainID[4]]];


	return 0;
}

