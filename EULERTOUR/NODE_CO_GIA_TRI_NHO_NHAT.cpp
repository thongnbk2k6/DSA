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

const long long maxn=1e6+5;
const long long minn=-1e6;
const long long MOD=1e9+7;
const long long inf=1e18;
int n,a[maxn],tour[maxn*4],timer=0,st[maxn],ed[maxn],q;
ll sg[maxn*4];
vector<int>ke[100001];
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		ke[u].pb(v);
		ke[v].pb(u);
	}
}
void dfs(int u,int pre){
	tour[++timer]=u;
	st[u]=timer;
	for(int v:ke[u]){
		if(v!=pre){
			dfs(v,u);
		}
	}
	tour[++timer]=u;
	ed[u]=timer;
}
void build(int id,int l,int r){
	if(l==r){
		sg[id]=a[tour[l]];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	sg[id]=min(sg[id*2],sg[id*2+1]);
}
ll get(int id,int l,int r,int u,int v){
	if(l>v||r<u) return inf;
	if(u<=l&&r<=v) return sg[id];
	int mid=(l+r)/2;
	return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
void update(int id,int l,int r,int u,int v,int val){
	if(l>v||r<u) return;
	if(l==r){
		sg[id]=val;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	sg[id]=min(sg[id*2],sg[id*2+1]);
}
void solve(){
	dfs(1,1);
	build(1,1,timer);
	cin>>q;
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op==1){
			int u;cin>>u;
			cout<<get(1,1,timer,st[u],ed[u])<<endl;
		}else{
			int u,val;cin>>u>>val;
			update(1,1,timer,st[u],ed[u],val);
		}
	}
}
int main(){
	faster
	nhap();
	solve();	




	return 0;
}

