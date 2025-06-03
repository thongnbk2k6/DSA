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
int n,m;
vector<pii>adj[maxn];
vector<ll>dis;
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		adj[u].pb({v,w});
	}
}
void solve(){
	dis.assign(n+1,inf);
	dis[1]=0;
	priority_queue<pll,vector<pll>,greater<pll>>pq;
	pq.push({0,1});
	while(!pq.empty()){
		int u=pq.top().sc,kc=pq.top().fi;pq.pop();
		if(dis[u]<kc) continue;
		for(pii x:adj[u]){
			int v=x.fi,w=x.sc;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<dis[i]<<" ";

}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
