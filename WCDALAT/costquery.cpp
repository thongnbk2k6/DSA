#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define int long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int n,q;
vector<int>ke[maxn];
struct edge{
	int u,v,w;
};
vector<edge>canh;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int sz[maxn+1],parent[maxn+1];
void makeset(){
	for(int i=1;i<=maxn;i++){
		parent[i]=i;
		sz[i]=1;
	}
}
int find(int u){
	if(u==parent[u]) return u;
	return parent[u]=find(parent[u]);
}
void Union(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v) return ;
	else{
		if(sz[u]<sz[v]) swap(u,v);
		parent[v]=u;
		sz[u]+=sz[v];
		return ;
	}
	
	
}
vector<int> comp;
int t[maxn*4];
void nhap(){
	cin>>n>>q;
	edge e;
	for(int i=1;i<n;i++){
		int x,y,z;cin>>x>>y>>z;
		e.u=x;
		e.v=y;
		e.w=z;
		comp.push_back(e.w);
		canh.push_back(e);
	}
//	memset(a,0,sizeof(a));
	memset(t,0,sizeof(t));
	makeset();
}

//void build(int id,int l,int r){
//	if(l==r) {
//		t[id]=a[l];
//	}
//	int mid=(l+r)/2;
//	build(id*2,l,mid);
//	build(id*2+1,mid+1,r);
//}

int get(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(u<=l&&r<=v) return t[id];
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
void update(int id,int l,int r,int pos,int val){
	if(pos>r||pos<l) return;
	if(l==r) {
		t[id]+=val;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	t[id]=t[id*2]+t[id*2+1];	
}
void xuly(){
	for(auto it:canh){
		
		int x=it.u,y=it.v,z=it.w;
		x = find(x);
		y = find(y);
		update(1,1,maxn,z,sz[x]*sz[y]);
		Union(x, y);
	}
}

main(){
	freopen("costquery.inp","r",stdin);
	freopen("costquery.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
//	for(auto x:canh){
//		cout<<x.u<<" "<<x.v<<" "<<x.w<<endl;
//	}
	vector<pair<int,int>> vec;
	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		comp.push_back(u);
		comp.push_back(v);
		vec.push_back({u, v});
//		cout<<get(1,1,n,u,v)<<" ";
	}
	
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	
	for(int i=0;i<canh.size();i++){
		canh[i].w = lower_bound(comp.begin(), comp.end(), canh[i].w) - comp.begin() + 1;
	}
	for(int i=0;i<vec.size();i++){
		vec[i].first = lower_bound(comp.begin(), comp.end(), vec[i].first) - comp.begin() + 1;
		vec[i].second = lower_bound(comp.begin(), comp.end(), vec[i].second) - comp.begin() + 1;
	}
	
	sort(canh.begin(),canh.end(),cmp);
	xuly();
	for(auto it: vec){
		int l = it.first;
		int r = it.second;
		cout << get(1, 1, maxn, l, r) << " ";
	}
	
}

