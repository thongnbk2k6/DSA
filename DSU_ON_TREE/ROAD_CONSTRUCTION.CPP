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
int n,m,sz[maxn],parent[maxn],components,maxSz;
vector<pii>roads;
void nhap(){
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int u,v;cin >> u >>v;
		roads.pb({u,v});
	}
}
int Find(int u){
	if(u==parent[u]) return u;
	return parent[u]=Find(parent[u]);
}
void Union(int u,int v){
	u=Find(u);
	v=Find(v);
	if(u==v) return;
	if(sz[u]<sz[v]) swap(u,v);
	parent[v]=u;
	sz[u]+=sz[v];
	components--;
	maxSz=max(maxSz,sz[u]);

}


void solve(){
	for(int i=1;i<=n;i++){
		sz[i]=1;
		parent[i]=i;
	}
	components=n;
	maxSz=0;
	for(int i=0;i<m;i++){
		int u=roads[i].fi,v=roads[i].sc;
		Union(u,v);
		cout<<components<<" "<<maxSz<<endl;
	}

}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
