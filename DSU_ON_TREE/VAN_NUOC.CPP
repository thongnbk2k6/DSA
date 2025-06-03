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
int n,p,sz[maxn],parent[maxn];
void preprocess(){
	
}

void nhap(){
	cin>>n>>p;
}
int find(int u){
	if(u==parent[u]) return u;
	return parent[u] = find(parent[u]);
}
void Union(int u,int v){
	u = find(u);
	v = find(v);
	if(u==v) return ;
	if(sz[u]<sz[v]) swap(u,v);
	sz[u]+=sz[v];
	parent[v] = u;
	// return 1;
}
void solve(){
	for(int i = 1;i<=n;i++){
		sz[i] = 1;
		parent[i] = i;
	}
	cout<<endl;
	for(int i=1;i<=p;i++){
		int u,v,k;cin>>u>>v>>k;
		if(k==1){
			Union(u,v);
		}
		else{
			u = find(u);
			v = find(v);
			if(u==v) cout<<0<<endl;
			else cout<<1<<endl;
			// cout<<u<<" "<<v<<endl;

		}
	}


}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
