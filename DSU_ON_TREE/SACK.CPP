#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define bit(n,i) ((n>>i)&1)
#define fi first
#define sc second
#define pdb pair<double,double>
#define db double
#define endl '\n'

const long long maxn=1e5+5;
const long long minn=-1e6;
const long long inf=1e18;
int n,q,color[maxn],sz[maxn],cnt[maxn],res[maxn];
vector<int>ke[maxn];
vector<pii>query[maxn];
void nhap(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>color[i];
		sz[i]=1;
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		ke[u].pb(v);
		ke[v].pb(u);
	}
	for(int i=1;i<=q;i++){
		int v,c;cin>>v>>c;
		query[v].pb({c,i});
	}
}
void predfs(int u,int p){
	sz[u]=1;
	for(int v:ke[u]){
		if(v!=p){
			predfs(v,u);
			sz[u]+=sz[v];
		}
	}
}
void update(int u,int p,int delta){
	cnt[color[u]]+=delta;
	for(int v:ke[u]) {
		if(v!=p){
			update(v,u,delta);
		}
	}

}
void dfs(int u,int p){
	int bigchild=-1;
	for(int v:ke[u]){
		if(v!=p){
			if(bigchild==-1||sz[v]>sz[bigchild]) bigchild=v;
		}
	}
	for(int v:ke[u]){
		if(v!=p&&v!=bigchild){
			dfs(v,u);
			update(v,u,-1);
		}
	}
	if(bigchild!=-1) dfs(bigchild,u);
	for(int v:ke[u]){
		if(v!=p&&v!=bigchild) update(v,u,1);
	}
	cnt[color[u]]++;
	for(pii x:query[u]) res[x.sc]=cnt[x.fi];
}
void solve(){
	predfs(1,0);
	dfs(1,0);
	for(int i=1;i<=q;i++){
		cout<<res[i]<<endl;
	}

}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
