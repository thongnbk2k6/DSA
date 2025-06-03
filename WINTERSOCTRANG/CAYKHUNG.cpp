#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
ll n,q,parent[maxn],Size[maxn],w[maxn];
struct edge{
	ll u,v,w;
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
bool Union(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v) return 0;
	else {
		if(Size[u]<Size[v]) swap(u,v);
		parent[v]=u;
		Size[u]+=Size[v];
		return 1;
	}
}
void nhap(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	sort(w+1,w+n+1);
}
void kruskal(int t){
	
		make_set();
		ll ts=(w[1]+t)*(w[n]+t)-t*t;
		Union(1,n);
		if(w[n]+t<=0){
			for(int i=2;i<n;i++){
				 Union(2,n);
				 ts=ts+(w[i]+t)*(w[n]+t)-t*t;
//				canh.push_back({i,n,ts});
			}
		}else{
			for(int i=2;i<n;i++){
				if(w[i]+t>0){
					 if(Union(i,1)){
					 	ts=ts+(w[i]+t)*(w[1]+t)-t*t;
					 }
					
				}else {
					 if(Union(i,n)){
					 	ts=ts+(w[i]+t)*(w[n]+t)-t*t;
					 }
				
				}
			}
		}
	cout<<ts<<" ";


}
void xuly(){
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		kruskal(t);
	}
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	make_set();
	xuly();
}

