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
map<pair<int,int>,string>mpans;
vector<edge>canh;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
void Makeset(){
	for(int i=1;i<=n;i++){
		Size[i]=1;
		parent[i]=i;
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
vector<pair<int,int>>ans;
void nhap(){
	cin>>sub>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		canh.push_back({x,y,z});
		ans.push_back({x,y});
	}
}
void kruskal(){
	sort(canh.begin(),canh.end(),cmp);
	for(int i=0;i<canh.size();i++){
		pair<int,int>p1={canh[i].u,canh[i].v};
//		if(Union(4,3)) {
//			cout<<1<<endl;
//			return ;	
//		}else {
//			cout<<0;
//			return ;
//		}
//		if(Union(canh[i].u,canh[i].v)){
//			if(i+1<canh.size()&&Union(canh[i+1].u,canh[i+1].v)&&canh[i].w==canh[i+1].w){
//				pair<int,int>p2={canh[i+1].u,canh[i+1].v};
//					mpans[p1]="No";
//					mpans[p2]="No";
//					i++;
//			}else{
//				mpans[p1]="Yes";
//			}
//		}else mpans[p1]="No";
		cout<<canh[i].u<<" "<<canh[i].v<<" "<<canh[i].w<<endl;
	}
//	for(int i=0;i<canh.size();i++){
//		pair<int,int>p={canh[i].u,canh[i].v};
//		cout<<canh[i].u<<" "<<canh[i].v<<" "<<mpans[p]<<endl;
//	}
	
}
main(){
//	freopen("mst.inp","r",stdin);
//	freopen("mst.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	Makeset();
	cout<<endl<<endl;
	kruskal();
}

