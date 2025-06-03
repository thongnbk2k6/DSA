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

const long long maxn=2e5+5;
const long long minn=-1e6;
const long long inf=1e18;
int n,longest_length[maxn],second_longest_length[maxn],ans[maxn];
vector<int>adj[maxn];
void preprocess(){
	memset(longest_length,0,sizeof longest_length);
	memset(second_longest_length,0,sizeof second_longest_length);
	memset(ans,0,sizeof ans);
	
}

void nhap(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
void dfs1(int v,int parent){
	// cout<<v<<endl;
	for(int u:adj[v]){
		if(u==parent) continue;
		dfs1(u,v);
		if(longest_length[u]+1>longest_length[v]){
			second_longest_length[v] = longest_length[v];
			longest_length[v] = longest_length[u] + 1;

		}else if(longest_length[u]+1>second_longest_length[v]){
			second_longest_length[v] = longest_length[u] + 1;
		}
	}
}
void dfs2(int v,int parent,int to_par ){
	ans[v] = max(longest_length[v],to_par);
	for(int u:adj[v]){
		if(u==parent) continue;
		if(longest_length[u]+1==longest_length[v]) dfs2(u,v,max(second_longest_length[v],to_par)+1);
		else dfs2(u,v,ans[v] +1);
	}
}
void solve(){
	dfs1(1,-1);
	dfs2(1,-1,0);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}


}
int main(){
	faster
	preprocess();
	nhap();
	solve();




	return 0;
}
