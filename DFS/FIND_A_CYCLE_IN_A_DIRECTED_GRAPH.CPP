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
int n,m,start_cycle=-1,end_cycle=-1,parent[maxn];
vector<int>adj[maxn];
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		adj[u].pb(v);
	}
	parent[1]=1;
}
vector<int>color;
bool dfs(int u){
	color[u]=1;
	for(int v:adj[u]){
		if(color[v]==0){
			parent[v]=u;
			if(dfs(v)) return 1;
		}else if(color[u]==1){
			end_cycle=u;
			start_cycle=v;
			return true;
		}
	}
	color[u]=2;
	return 0;
}
void solve(){
	color.assign(n+1,0);
	for(int i=1;i<=n;i++){
		if(color[i]==0&&dfs(i)) break;
	}
	if(start_cycle==-1){
		cout<<"NO";
		return;
	}
	cout<<"YES"<<endl;
	stack<int>st;
	for(int v=end_cycle;v!=start_cycle;v=parent[v]){
		// cout<<v<<endl;
		st.push(v);
	}
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
