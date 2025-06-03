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
int n,m,color[maxn],st_cyc=-1,ed_cyc,parent[maxn];
vector<int>adj[maxn];
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		adj[u].pb(v);
	}
	memset(color,0,sizeof color);

}
bool dfs(int u){
	color[u]=1;
	for(int v:adj[u]){
		if(color[v]==1){
			st_cyc=v;
			ed_cyc=u;
			return 1;
		}
		if(color[v]==0){
			parent[v]=u;
			if(dfs(v)) return 1;
		}
	}
	color[u]=2;
	return 0;
}
void solve(){
	for(int i=1;i<=n;i++){
		if(color[i]==0&&dfs(i)) break;
	}
	if(st_cyc==-1){
		cout<<"IMPOSSIBLE";
		return;
	}
	int k=1;
	stack<int>st;
	st.push(st_cyc);
	while(ed_cyc!=st_cyc){
		st.push(ed_cyc);
		k++;
		ed_cyc=parent[ed_cyc];
	}
	st.push(st_cyc);
	k++;
	cout<<k<<endl;
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
}
int main(){
	faster
	nhap();
	solve();



	return 0;
}
