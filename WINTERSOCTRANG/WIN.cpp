#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int sub,n,m,Size[maxn],parent[maxn];
struct edge{
	int u,v,w,chiso;
};
vector<edge>canh;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
void Makeset(){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		Size[i]=1;
	}
}
int find(int u){
	if(u==parent[u]) return u;
	return parent[u]=find(parent[u]);
}
bool Union(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v) return 0;
	else{
		if(Size[u]<Size[v]) swap(u,v);
		parent[v]=u;
		Size[u]+=Size[v];
		
	}
	return 1;
}
void nhap(){
	cin>>sub>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		canh.push_back({x,y,z,i});
	}
}
void kruskal(){
	vector<edge>vec;
	sort(canh.begin(),canh.end(),cmp);
	for(int i=0;i<canh.size();i++){
		if(Union(canh[i].u,canh[i].v)){
			vec.push_back({canh[i].u,canh[i].v,canh[i].w,canh[i].chiso});
		}
	}
	if(vec.size()!=n-1) cout<<0<<endl;
	else {
		for(int i=0;i<vec.size();i++){
			cout<<vec[i].chiso<<" ";
		}
	}
}
main(){
	freopen("mst.inp","r",stdin);
	freopen("mst.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	nhap();
	Makeset();
	kruskal();
	
}

