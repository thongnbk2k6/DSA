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
int n,childNum[maxn];

void preprocess(){
}
vector<int>adj[maxn];
void nhap(){
	cin>>n;
	for(int i=2;i<=n;i++){
		int u;cin>>u;
		adj[u].push_back(i);
		adj[i].push_back(u);
	}
	
}
void dfs(int v,int parent){
	childNum[v] = 1;
	for(int u:adj[v]){
		if(u==parent) continue;
		dfs(u,v);
		childNum[v] +=childNum[u];
	}


}
void solve(){
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		cout<<childNum[i]-1<<" ";
	}

}
int main(){
	faster
	preprocess();
	nhap();
	solve();
	




	return 0;
}
