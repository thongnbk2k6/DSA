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
int n,q,h[maxn],f[maxn],up[19][maxn],dis[19][maxn];
vector<pair<int,int>>adj[maxn];
void preprocess(){
	h[1] = 0;
	f[1] = 0;
	
}

void nhap(){
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int u,v,w;cin>>u>>v>>w;
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}

}
void dfs(int v){
	for(pair<int,int> cur_node:adj[v]){
		int u = cur_node.first;
		int w = cur_node.second;
		if(u == up[0][v]) continue;
		h[u] = h[v] + 1;
		f[u] = f[v] + w;
		up[0][u] = v;
		for(int j=1;j<=18;j++){
			up[j][u] = up[j-1][up[j-1][u]]; 
		}
		dfs(u);
	}

}
void dis_array_processing(){
	for(int i=1;i<=n;i++){
		for(int k=0;k<=18;k++){
			dis[k][i] = f[i] - f[up[k][i]];
		}
	}


}
int tinh(int u,int x){
	int cur_dist = 0;
	for(int j = __lg(h[u]);j>=0;j--){
		if((h[u]>=(1<<j))&&cur_dist+ dis[j][u]<=x){
			cur_dist += dis[j][u];
			u = up[j][u];
		}
	}
	return u;
}
void solve(){
	dfs(1);//tinh mang up
	dis_array_processing();//tinh mang dis
	for(int i=1;i<=q;i++){
		int u,x;cin>>u>>x;
		cout<<tinh(u,x)<<endl;
	}



}
int main(){
	faster
	preprocess();
	nhap();
	solve();
	




	return 0;
}
