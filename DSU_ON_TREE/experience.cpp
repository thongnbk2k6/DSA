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

const long long maxn=2e5+5;
const long long minn=-1e6;
const long long inf=1e18;
int n,m,par[maxn],sz[maxn],score[maxn],ex[maxn];
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		par[i]=i;
		sz[i]=1;
		ex[i]=score[i]=0;
	}

}
int get(int u){
	if(u==par[u]) return u;
	return get(par[u]);
}
void Union(int u,int v){
	u=get(u);
	v=get(v);
	if(u==v) return;
	if(sz[u]<sz[v]) swap(u,v);
	sz[u]+=sz[v];
	par[v]=u;
	ex[v]=score[u];
}
void add(int u,int value){
	u=get(u);
	score[u]+=value;
}
int getep(int u){
	if(u==par[u]) return score[u];
	return score[u]-ex[u]+getep(par[u]);
}
void solve(){
	for(int i=1;i<=m;i++){
		string s;cin>>s;
		if(s=="join"){
			int u,v;cin>>u>>v;
			Union(u,v);
		}
		if(s=="add"){
			int u,value;cin>>u>>value;
			add(u,value);
		}
		if(s=="get"){
			int u;cin>>u;
			cout<<getep(u)<<endl;
		}
	}
}
int main(){
	faster
	nhap();
	solve();



	return 0;
}
