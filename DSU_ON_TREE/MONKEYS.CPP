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
const int inf=4e5+1;
int n,m,trai[maxn],phai[maxn],sz[maxn],par[maxn],t[maxn],sz1[maxn],par1[maxn];
pii edge[maxn];
vector<pii>query;
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int l,r;cin>>l>>r;
		edge[i]={l,r};
		trai[i]=phai[i]=0;
		sz[i]=sz1[i]=1;
		par[i]=par1[i]=i;
		t[i]=inf;
		if(l==-1) trai[i]=-1;
		if(r==-1) phai[i]=-1;
	}
	for(int i=1;i<=m;i++){
		int u,num;cin>>u>>num;
		if(num==1) trai[u]=1;
		if(num==2) phai[u]=1;
		query.pb({u,num});
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
	sz[u]+=sz[v];
	par[v]=u;
}
int get1(int u){
	if(u==par1[u]) return u;
	return par1[u]=get1(par1[u]);
}
void Union1(int u,int v){
	u=get1(u);
	v=get1(v);
	if(u==v) return;
	if(sz1[u]<sz1[v]) swap(u,v);
	sz1[u]+=sz1[v];
	par1[v]=u;
	if(t[u]==inf&&t[v]!=inf) t[u]=t[v];

}
void solve(){
	for(int i=1;i<=n;i++){
		pii x=edge[i];
		if(trai[i]==0){
			int u=x.fi;
			Union(i,u);
			if(get(u)!=get(1)) {
				Union1(u,i);
			}
		}
		if(phai[i]==0){
			int v=x.sc;
			Union(i,v);
			if(get(v)!=get(1)) {
				Union1(v,i);
			}
		}
	}
	t[1]=-1;
	for(int i=m-1;i>=0;i--){
		pii x=query[i];
		int u=x.fi,num=x.sc;
		pii y=edge[u];
		int v;
		if(num==1){
			v=y.fi;
			if(v==-1) continue;
		}
		if(num==2){
			v=y.sc;
			if(v==-1) continue;
		}
		u=get(u);
		v=get(v);
		int w=get(1);
		if(u!=w&&v!=w){
			Union(u,v);
			Union1(u,v);
		}else{
			if(u==v&&u==w) continue;
			if(v==w&&u!=w) swap(u,v);
			Union(u,v);
			v=get1(v);
			t[v]=i;
		}
	}
	cout<<t[1]<<endl;
	for(int i=2;i<=n;i++){
		int u=i;
		u=get1(u);
		cout<<t[u]<<endl;
	}





}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
