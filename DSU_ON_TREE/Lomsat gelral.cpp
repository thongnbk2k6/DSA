#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define piii int,pair<int,int>
#define bit(n,i) ((n>>i)&1)
#define fi first
#define sc second
#define pdb pair<double,double>
#define db double
#define endl '\n'

const long long maxn=1e5+5;
const long long minn=-1e6;
const long long MOD=1e9+7;
const long long inf=1e18;
int n,ans[maxn],Sz[maxn],c[maxn];
vector<int>ke[maxn];
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		ke[u].pb(v);
		ke[v].pb(u);
	}
}
void dfs(int u,int pre,map<int,int>&large){
	ans[u]=c[u];
	large[c[u]]++;
	Sz[u]=1;
	for(int v:ke[u]){
		if(v==pre) continue;
		map<int,int>small;
		dfs(v,u,small);
		if(large.size()<small.size()) {
			swap(small,large);
			Sz[u]=Sz[v];
			ans[u]=ans[v];
		}
		for(pii p:small){
			large[p.fi]+=p.sc;
			int val=large[p.fi];
			if(val>Sz[u]){
				ans[u]=p.fi;
				Sz[u]=val;
			}else if(val==Sz[u]) ans[u]+=p.fi;
		}
		
	}
	
}
void solve(){
	map<int,int>mp;
	dfs(1,1,mp);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}

}
int main(){
	faster
	nhap();
	solve();




	return 0;
}

