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
#define endl '\n'

const long long maxn=50005;
const long long minn=-1e6;
const long long MOD=1e9+7;
const long long inf=1e18;
int n,m,cau,parent[maxn],Sz[maxn],par[maxn][18],par1[maxn],Sz1[maxn],par2[maxn],Sz2[maxn];
//hld
int curchain,curpos,chainhead[maxn],chainID[maxn],pos[maxn],arr[maxn],h[maxn];
bool used[maxn];
ll sg[maxn*4],lz[maxn*4];
vector<int>ke[50005];
vector<int>ke2[50005];
vector<pii>queries;
vector<pii>cay;
//tao cay sau hld
int par22[maxn][18],h22[maxn];
void make_set(){
	for(int i=1;i<=n;i++){
		par1[i]=i;
		Sz1[i]=1;
		par2[i]=i;
		Sz2[i]=1;
	}
}
int find(int u){
	if(u==par1[u]) return u;
	else return par1[u]=find(par1[u]);
}
bool Union(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v) return 0;
	else{
		if(Sz1[u]<Sz1[v]) swap(u,v);
		par1[v]=u;
		Sz1[u]+=Sz1[v];
		return 1;
	}
}
int find2(int u){
	if(u==par2[u]) return u;
	else return par2[u]=find2(par2[u]);
}
bool Union2(int u,int v){
	u=find2(u);
	v=find2(v);
	if(u==v) return 0;
	else{
		if(Sz2[u]<Sz2[v]) swap(u,v);
		par2[v]=u;
		Sz2[u]+=Sz2[v];
		return 1;
	}
}
void khoitao(){
	for(int i=1;i<=n;i++){
		ke[i].clear();
		ke2[i].clear();
	}
	memset(chainhead,-1,sizeof(chainhead));
	memset(pos,0,sizeof(pos));
	memset(arr,0,sizeof(arr));
	memset(h,0,sizeof(h));
	memset(sg,0,sizeof(sg));
	memset(lz,0,sizeof(lz));
	memset(used,0,sizeof(used));
	memset(h22,0,sizeof(h22));
	queries.clear();
	cay.clear();
	cau=0;
	curchain=curpos=1;
	par[1][0]=1;
	parent[1]=1;
	par22[1][0]=1;
	
	
}

void dfs(int u,int pre){
	Sz[u]=1;
	for(int v:ke[u]){
		if(v==pre) continue;
		if(par[u][0]!=v) par[v][0]=u;
		h[v]=h[u]+1;
		parent[v]=u;
		dfs(v,u);
		Sz[u]+=Sz[v];
	}
}
void Hld(int u,int pre){
	if(chainhead[curchain]==-1){
		chainhead[curchain]=u;
	}
	chainID[u]=curchain;
	arr[curpos]=u;
	pos[u]=curpos;
	curpos++;
	int nxt=0;
	for(int v:ke[u]){
		if(v!=pre){
			if(nxt==0||Sz[v]>Sz[nxt]){
				nxt=v;
			}
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
void taocay(){
	for(int i=0;i<cay.size();i++){
		int u=cay[i].fi,v=cay[i].sc;
		ke2[pos[u]].pb(pos[v]);
		ke2[pos[v]].pb(pos[u]);
	}
}
void dfs2(int u,int pre){
	for(int v:ke2[u]){
		if(v==pre) continue;
		h22[v]=h22[u]+1;
		if(par22[u][0]!=v) par22[v][0]=u;
		dfs2(v,u);
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
int lca2(int u,int v){
	if(h22[u]!=h22[v]){
		if(h22[u]<h22[v]){
			swap(u,v);
		}
		for(int i=17;i>=0;i--){
			if(h22[par22[u][i]]>=h22[v]){
				u=par22[u][i];
			}
		}
	}
	if(u==v) return u;
	for(int i=17;i>=0;i--){
		if(par22[u][i]!=par22[v][i]){
			u=par22[u][i];
			v=par22[v][i];
		}
	}
	return par22[u][0];
}
void push(int id){
	if(lz[id]){
		sg[id*2]+=lz[id];
		sg[id*2+1]+=lz[id];
		lz[id*2]+=lz[id];
		lz[id*2+1]+=lz[id];
		lz[id]=0;
	}
}
void update(int id,int l,int r,int u,int v,int val){
	if(l>v||r<u) return;
	if(u<=l&&r<=v) {
		lz[id]+=val;
		sg[id]+=val;
		return;
	}
	int mid=(l+r)/2;
	push(id);
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	sg[id]=sg[id*2]+sg[id*2+1];
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
ll tinhtongdoan(int u,int v){
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
int socon(int u,int v){
	return h22[u]+h22[v]-2*h22[lca2(u,v)]+1;
}
void updatedoan(int u,int v,int val){
	int res=lca(u,v);
	while(chainID[u]!=chainID[res]){
		update(1,1,n,pos[chainhead[chainID[u]]],pos[u],socon(pos[chainhead[chainID[u]]],pos[u])*val);
		u=parent[chainhead[chainID[u]]];
	}
	while(chainID[v]!=chainID[res]){
		update(1,1,n,pos[chainhead[chainID[v]]],pos[v],socon(pos[chainhead[chainID[v]]],pos[v])*val);
		v=parent[chainhead[chainID[v]]];
	}
	if(h[u]<h[v]){
		update(1,1,n,pos[u],pos[v],val*socon(pos[u],pos[v]));
	}else{
		update(1,1,n,pos[v],pos[u],val*socon(pos[u],pos[v]));
	}
}
void solve(){
	cout<<endl<<endl;
	for(int i=0;i<queries.size();i++){
		int u=queries[i].fi,v=queries[i].sc;
		if(Union2(u,v)){
			cau++;
//			cout<<1<<" "<<u<<" "<<v<<" "<<tinhtongdoan(u,v)<<endl;
//			cout<<u<<" "<<v<<" "<<used[u]<<" "<<used[v]<<endl;
//			if(!used[u]&&!used[v]){
//				updatedoan(u,v,1);
//				used[u]=1;
//				used[v]=1;
//			}else if(!used[u]&&used[v]){
//				update(1,1,n,pos[u],pos[u],1);
//				used[u]=1;
//			}else if(used[u]&&!used[v]){
//				update(1,1,n,pos[v],pos[v],1);
//				used[v]=1;
//			}
			updatedoan(u,u,-1*tinhtongdoan(u,u));
			updatedoan(v,v,-1*tinhtongdoan(v,v));
			updatedoan(u,v,1);
//			cout<<u<<" "<<v<<" "<<used[u]<<" "<<used[v]<<endl;
//			cout<<1<<" "<<u<<" "<<v<<" "<<tinhtongdoan(u,v)<<endl;
			cout<<cau<<endl;
			
		}else{
			ll sl=abs(tinhtongdoan(u,v));
//			cout<<2<<" "<<u<<" "<<v<<" "<<tinhtongdoan(u,v)<<endl;
			updatedoan(u,v,-1);
//			cout<<2<<" "<<u<<" "<<v<<" "<<tinhtongdoan(u,v)<<endl;
			cau=cau-(sl-1);
			cau=max(cau,0);
			cout<<cau<<endl;
		}
	}
	
}
void nhap(){
	cin>>n>>m;
	make_set();
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		u++;
		v++;
		if(Union(u,v)){
			ke[u].pb(v);
			ke[v].pb(u);
			cay.pb({u,v});
		}
		queries.pb({u,v});
	}
	
}
int main(){
	faster
	int tc;cin>>tc;
	while(tc--){
		khoitao();
		nhap();
		dfs(1,1);
		for(int j=1;j<=17;j++){
			for(int i=1;i<=n;i++){
				par[i][j]=par[par[i][j-1]][j-1];
			}
		}
		Hld(1,1);
		taocay();
		dfs2(1,1);
		for(int j=1;j<=17;j++){
			for(int i=1;i<=n;i++){
				par22[i][j]=par22[par22[i][j-1]][j-1];
			}
		}
		solve();	
//		cout<<pos[2]<<" "<<pos[5]<<endl;
//		updatedoan(2,5,1);
//		cout<<tinhtongdoan(1,5);
//		updatedoan(1,5,1);
//		cout<<tinhtongdoan(1,5);
	}
	




	return 0;
}

