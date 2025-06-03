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
int n,m,permutations[maxn],sz[maxn],parent[maxn],didNotBeDeleted[maxn];
vector<int>adj[maxn];
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i=1;i<=n;i++){
		cin>>permutations[i];
	}
	for(int i=1;i<=n;i++){
		sz[i]=1;
		parent[i]=i;
	}
	memset(didNotBeDeleted,0,sizeof didNotBeDeleted);
}
int get(int u){
	if(u==parent[u]) return u;
	return parent[u]=get(parent[u]);
}
bool Union(int u,int v){
	u=get(u);
	v=get(v);
	if(u==v) return 0;
	if(sz[u]<sz[v]) swap(u,v);
	sz[u]+=sz[v];
	parent[v]=u;
	return 1;
}
bool final_check(){
	int u=get(1);
	for(int i=2;i<=n;i++){
		if(u!=get(i)) return 0;
	}
	return 1;
}
void convert(int x){
	if(x==1){
		cout<<"YES"<<endl;
	}else cout<<"NO"<<endl;
}
void solve(){
	didNotBeDeleted[permutations[n]]=1;
	
	stack<int>ans;
	for(int i=n-1;i>=1;i--){
		int cnt=0;

		int u=permutations[i];
		for(int v:adj[u]){
			if(u==v) continue;
			if(didNotBeDeleted[v]==0) continue;
			else{
				if(Union(u,v)){
					cnt++;
				}
			}
		}
		if(cnt<2){
			ans.push(1);
		}else ans.push(0);
		
		didNotBeDeleted[u]=1;
		
	}
	if(final_check()){
		ans.push(1);
	}else ans.push(0);
	while(!ans.empty()){
		int tmp=ans.top();ans.pop();
		convert(tmp);
	}




}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
