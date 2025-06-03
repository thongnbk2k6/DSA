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

const long long maxn=1e6+5;
const long long minn=-1e6;
const long long inf=1e18;
int n,m,sz[1001],parent[1001],num_group,node[1001];
bool met[1001];
vector<int>group[1001];
void preprocess(){
	num_group = 0;
	memset(met,0,sizeof met);
}

void nhap(){
	cin>>n>>m;

	
}
int find(int u){
	if(u==parent[u]) return u;
	return parent[u] = find(parent[u]);
}
bool Union(int u,int v){
	 u = find(u);
	 v=  find(v);
	 if(u==v) return 0;
	 if(sz[u]<sz[v]) swap(u,v);
	 if(u>v) swap(u,v);
	 //2 thao tac nay lam u vua co so thu tu nho nhat vua lam size cua u lon nhat
	 sz[u]+=sz[v];
	 parent[v] = u;
	 return true;

}
void solve(){
	for(int i=1;i<=n;i++){
		sz[i]=1;
		parent[i] = i;
	}
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		Union(u,v);
	}
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		int u = i;
		u = find(u);
		if(!met[u]){
			met[u] = 1;
			node[u] = ++cnt;
			group[node[u]].pb(u);	
		}
		if(i!=u){
			group[node[u]].pb(i);
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		for(int v:group[i]){
			cout<<v<<" ";
		}
		cout<<endl;
	}


}
int main(){
	faster
	preprocess();
	nhap();
	solve();




	return 0;
}
