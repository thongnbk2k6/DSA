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
int n,m,q,sz[maxn],par[maxn];
struct rq{
	string s;
	int u;
	int v;
};
map<pii,int>mp;
vector<pii>edge;
vector<rq>truyvan;
vector<int>res;
void nhap(){
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		edge.pb({u,v});
	}
	for(int i=1;i<=q;i++){
		string s;
		int u,v;
		cin>>s>>u>>v;
		truyvan.pb({s,u,v});
	}
	for(int i=1;i<=n;i++){
		sz[i]=1;
		par[i]=i;
	}
}
int get(int u){
	if(u==par[u]) return u;
	return par[u]=get(par[u]);
}
void Union(int u,int v){
	u=get(u);
	v=get(v);
	if(u==v) return;
	if(sz[u]<sz[v]) swap(u,v);
	par[v]=u;
	sz[u]+=sz[v];
}
void solve(){
	for(rq x:truyvan){
		string s=x.s;
		int u=x.u,v=x.v;
		if(s=="ask") continue;
		if(u==v) continue;
		pii p={u,v};
		mp[p]=1;
	}
	for(pii x:edge){
		int u=x.fi,v=x.sc;
		pii p1={u,v},p2={v,u};
		if(u==v) continue;
		if(mp[p1]==1||mp[p2]==1) {
			continue;
		}else{
			Union(u,v);
		}
	}
	for(int i=truyvan.size()-1;i>=0;i--){
		rq x=truyvan[i];
		string s=x.s;
		int u=x.u,v=x.v;
		if(s=="ask"){
			u=get(u);
			v=get(v);
			if(u==v) res.pb(1);
			else res.pb(0);
		}else{
			Union(u,v);
		}
	}
	reverse(all(res));
	for(int x:res){
		if(x==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

}
int main(){
	faster
	nhap();
	solve();
	




	return 0;
}
