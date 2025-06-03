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
int n,m,parent[2505],start_cycle=-1,end_cycle;
vector<int>adj[2505];
bool vs[2305];
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(vs,0,sizeof vs);
}
bool dfs(int u,int pre){
	vs[u]=1;
	for(int v:adj[u]){
		if(v==pre) continue;
		if(vs[v]){
			start_cycle=v;
			end_cycle=u;
			return 1;
		}
		parent[v]=u;
		if(dfs(v,u)) return 1;
	}
	return 0;


}
void solve(){
	for(int i=1;i<=n;i++){
		if(!vs[i]&&dfs(i,i)) break;
	}
	if(start_cycle==-1){
		cout<<"NO";
		return;
	}
	stack<int>st;
	for(int v=end_cycle;v!=start_cycle;v=parent[v]) st.push(v);
	st.push(start_cycle);
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
