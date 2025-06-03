#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int sub,n,m,parent[maxn],Size[maxn];
struct edge{
	int u,v,w;
};
vector<edge>canh;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
void make_set(){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		Size[i]=1;
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
		if(Size[u]<Size[v]) swap(u,v);
		parent[v]=u;
		Size[u]+=Size[v];
		
	}
}
bool check(int u,int v){
	u=find(u);
	v=find(v);
	return u!=v;
}
vector<pair<int,int>>vec;

map<int,vector<pair<int,int>>>mp1;

map<pair<int,int>,string>ans;
vector<int>nhom;
void nhap(){
	cin>>sub>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		nhom.push_back(z);
		vec.push_back({x,y});
		mp1[z].push_back({x,y});
	}
}
void nenso(){
	vector<int>cmp;
	//nen trong so
	cmp=nhom;
	sort(cmp.begin(),cmp.end());
	cmp.erase(unique(cmp.begin(),cmp.end()),cmp.end());
	for(int i=0;i<nhom.size();i++){
		nhom[i]=lower_bound(cmp.begin(),cmp.end(),nhom[i])-cmp.begin()+1;
	}
}
void kruskal(){
	sort(nhom.begin(),nhom.end());
	//sap xep cac  nhom co trong so tu nho den big
	nhom.erase(unique(nhom.begin(),nhom.end()),nhom.end());
	for(int i=0;i<nhom.size();i++){
		for(pair<int,int>p1:mp1[nhom[i]]){
			if(check(p1.first,p1.second)){
				ans[p1]="Yes";
			}else ans[p1]="No";
		}
		for(pair<int,int>p2:mp1[nhom[i]]){
			Union(p2.first,p2.second);
		}
	}
	for(pair<int,int>p:vec){
		cout<<ans[p]<<" ";
	}
}
main(){
//	freopen("mst.inp","r",stdin);
//	freopen("mst.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
//	for(int i=0;i<nhom.size();i++) cout<<nhom[i]<<" ";
//	cout<<endl;
	make_set();
//	nenso();
//	for(int i=0;i<nhom.size();i++) cout<<nhom[i]<<" ";
	kruskal();
}

