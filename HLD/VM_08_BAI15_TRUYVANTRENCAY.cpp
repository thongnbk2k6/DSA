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
#define int long long
const long long maxn=1e6+5;
const long long minn=-1e6;
const long long MOD=1e9+7;
const long long inf=1e18;
int n,q;
vector<int>ke[100001];
int curchain,curpos,pos[maxn],chainhead[maxn],chainID[maxn],Sz[maxn],parent[maxn],arr[maxn];
ll sg[maxn*4];
void nhap(){
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		ke[u].pb(v);
		ke[v].pb(u);
	}
	curchain=curpos=1;
	parent[1]=1;
}
void dfs(int u,int pre){
	Sz[u]=1;
	for(int v:ke[u]){
		if(v==pre) continue;
		parent[v]=u;
		dfs(v,u);
		Sz[u]+=Sz[v];
	}
}
void build(int id,int l,int r){
	if(l==r){
		sg[id]=inf;
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	sg[id]=min(sg[id*2],sg[id*2+1]);
}
void Hld(int u,int pre){
	if(!chainhead[curchain]) chainhead[curchain]=u;
	chainID[u]=curchain;
	pos[u]=curpos;
	arr[curpos]=u;
	curpos++;
	int nxt=0;
	for(int v:ke[u]){
		if(v!=pre){
			if(!nxt||Sz[v]>Sz[nxt]) nxt=v;
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
void update(int id,int l,int r,int pos){
	if(l>pos||r<pos) return;
	if(l==r&&r==pos){
		if(sg[id]!=inf) sg[id]=inf;
		else{
			sg[id]=l;
		}
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos);
	update(id*2+1,mid+1,r,pos);
	sg[id]=min(sg[id*2],sg[id*2+1]);
}
ll get(int id,int l,int r,int u,int v){
	if(l>v||r<u) return inf;
	if(u<=l&&r<=v) return sg[id];
	int mid=(l+r)/2;
	return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
void updatediem(int vt){
	update(1,1,n,pos[vt]);
}
ll tinh(int vt){
	ll ans=inf;
	while(chainID[vt]!=chainID[1]){
		ll tmp=get(1,1,n,pos[chainhead[chainID[vt]]],pos[vt]);
		ans=min(ans,tmp);
		vt=parent[chainhead[chainID[vt]]];
	}
	ll tmp=get(1,1,n,pos[1],pos[vt]);
	ans=min(ans,tmp);
	return ans;
}
void solve(){
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op) {
			int vt;cin>>vt;
			ll tmp=tinh(vt);
			if(tmp==inf) cout<<-1<<endl;
			else cout<<arr[tmp]<<endl;
		}else{
			int vt;cin>>vt;
			updatediem(vt);
		}
	}

}
 main(){
	faster
	nhap();
	dfs(1,1);
	build(1,1,n);
	Hld(1,1);
	solve();
	




	return 0;
}

