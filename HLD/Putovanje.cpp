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
int n;
int pos[maxn],chainID[maxn],chainhead[maxn],curchain=1,curpos=1,arr[maxn];
int h[maxn],parent[maxn],Sz[maxn],par[maxn][18];
ll sg[maxn*4],lz[maxn*4];
struct edge{
	int u, v, c1, c2;
};
vector<edge>canh;
vector<int>ke[200001];
void nhap(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v,c1,c2;cin>>u>>v>>c1>>c2;
		ke[u].pb(v);
		ke[v].pb(u);
		canh.pb({u,v,c1,c2});	
	}
	h[0]=1;
//	memset(par,-1,sizeof(par));
	par[1][0]=1;
	
}

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
	if(!chainhead[curchain]) chainhead[curchain]=u;
	arr[curpos]=u;
	pos[u]=curpos;
	chainID[u]=curchain;
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
void push(int id){
	if(lz[id]){
		sg[id*2]+=lz[id];
		sg[id*2+1]+=lz[id];
		lz[id*2]+=lz[id];
		lz[id*2+1]+=lz[id];
		lz[id]=0;
	}
}
void update(int id,int l,int r,int u,int v){
	if(l>v||r<u) return;
	if(u<=l&&r<=v) {
		sg[id]+=1;//tang so lan di qua trong doan u-v len 1
		lz[id]+=1;
		return;
	}
	int mid=(l+r)/2;
	push(id);
	update(id*2,l,mid,u,v);
	update(id*2+1,mid+1,r,u,v);
	sg[id]=sg[id*2]+sg[id*2+1];
	
}
ll getsum(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(u<=l&&r<=v) return sg[id];
	int mid=(l+r)/2;
	push(id);
	return getsum(id*2,l,mid,u,v)+getsum(id*2+1,mid+1,r,u,v);
}
ll sl(int u,int v){
	int res=lca(u,v);
	ll ans=0;
	while(chainID[u]!=chainID[res]){
		ans+=getsum(1,1,n,pos[chainhead[chainID[u]]],pos[u]);
//		cout<<u<<" "<<parent[chainhead[chainID[u]]]<<endl;
		u=parent[chainhead[chainID[u]]];
//		cout<<ans<<endl;
	}	
//	cout<<chainID[v]<<" "<<chainID[res]<<endl;
	while(chainID[v]!=chainID[res]){
		ans+=getsum(1,1,n,pos[chainhead[chainID[v]]],pos[v]);
//		cout<<v<<" "<<parent[chainhead[chainID[v]]]<<endl;
		v=parent[chainhead[chainID[v]]];
	}
	if(h[u]<h[v]){
		ans+=getsum(1,1,n,pos[u],pos[v]);
//		cout<<ans<<endl;
	}else ans+=getsum(1,1,n,pos[v],pos[u]);
	return ans;
}

void solve(){
	memset(lz,0,sizeof(lz));	
	for(int i=1;i<n;i++){
		int u=pos[i],v=pos[i+1];
		if(u>v) swap(u,v);
		update(1,1,n,u,v);
	}
	ll ans=0;
	for(int i=0;i<canh.size();i++){
		ll u=canh[i].u,v=canh[i].v,c1=canh[i].c1,c2=canh[i].c2;
		ans+=min(sl(u,v)*c1,c2);
	}
	cout<<ans;
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
//	solve();
	update(1,1,n,pos[3],pos[4]);
	cout<<getsum(1,1,n,pos[1],pos[4]);
//	cout<<pos[1]<<" "<<pos[4];
//	cout<<sl(3,4);



	return 0;
}

