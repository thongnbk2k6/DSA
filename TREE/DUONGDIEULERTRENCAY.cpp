#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define bit(n,i) ((n>>i)&1)
#define fi first
#define sc second
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
int n,m=0,goc=1,tour[maxn],st[maxn],ed[maxn],h[maxn];
vector<int>ke[1001];
void nhap(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		ke[u].push_back({v});
		ke[v].push_back({u});
	}
	memset(h,0,sizeof(h));
}
void add(int u){
	tour[++m]=u;
	ed[u]=m;
}
void dfs(int u,int pre){
	h[u]=h[pre]+1;
	add(u);
	st[u]=m;
	for(int v:ke[u]){
		if(v!=pre){
			dfs(v,u);
		}
	}
	if(u!=goc) add(pre);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	dfs(1,0);
	for(int i=1;i<=m;i++){
		cout<<tour[i]<<" ";
	}
	





	return 0;
}

