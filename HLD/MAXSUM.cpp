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
int n,a[maxn],curchain,curpos,h[maxn],parent[maxn],Sz[maxn];
int chainhead[maxn],chainID[maxn],pos[maxn],arr[maxn];
bool isLa[maxn];
vector<int>ke[1000001];
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		ke[u].pb(v);
		ke[v].pb(u);
	}
	h[1]=1;
	curchain=curpos=1;
}
void dfs(int u,int pre){
	Sz[u]=1;
	if(ke[u].size()==1&&u!=1) isLa[u]=1;
	for(int v:ke[u]){
		if(v==pre) continue;
		h[v]=h[u]+1;
		parent[v]=u;
		dfs(v,u);
		Sz[u]+=Sz[v];	
	}
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
int sg[maxn*4];
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
	if(u<=l&&r<=v){
		return sg[id];
	}
	int  mid=(l+r)/2;
	return getsum(id*2,l,mid,u,v)+getsum(id*2+1,mid+1,r,u,v);
}
ll tinh(int u,int v){
	ll res=0;
	while(chainID[v]!=chainID[1]){
		res+=getsum(1,1,n,pos[chainhead[chainID[v]]],pos[v]);
		v=parent[chainhead[chainID[v]]];
	}
	res+=getsum(1,1,n,pos[1],pos[v]);
	return res;
}
void solve(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(isLa[i]){
			ans=max(ans,tinh(1,i));
		}
	}
	cout<<ans;

}
int main(){
	freopen("MAXSUM.INP","r",stdin);
	freopen("MAXSUM.OUT","w",stdout);
	faster
	nhap();
	dfs(1,1);
	Hld(1,1);
	build(1,1,n);
	solve();



	return 0;
}

