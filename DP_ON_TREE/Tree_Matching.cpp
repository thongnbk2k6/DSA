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
int n,dp[2][maxn];
vector<int>adj[maxn];
void preprocess(){
	memset(dp,0,sizeof dp);
}

void nhap(){
	cin>>n;
	for(int i = 1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
void dfs(int v,int parent){
	for(int u:adj[v]){
		if(u==parent) continue;
		dfs(u,v);
		dp[0][v] += max(dp[0][u],dp[1][u]);
	}
	for(int u:adj[v]){
		if(u==parent) continue;
		dp[1][v] = max(dp[1][v],dp[0][u] + dp[0][v] + 1 - max(dp[0][u],dp[1][u]));
	}
}
void solve(){
	dfs(1,0);
	cout<<max(dp[0][1],dp[1][1]);

}
int main(){
	faster
	preprocess();
	nhap();
	solve();
	




	return 0;
}
