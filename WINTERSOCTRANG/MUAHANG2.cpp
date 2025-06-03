#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
int n,m;
ll p[maxn];
vector<pll>ke[100001];
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		ke[0].push_back({i,p[i]});
//		ke[i].push_back({0,p[i]});
	}
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		ke[u].push_back({v,w*2});
		ke[v].push_back({u,w*2});
	}
}
void dijkstra(int st){
	priority_queue<pll,vector<pll>,greater<pll>>q;
	vector<ll>d(n+1,inf);
	d[st]=0;
	q.push({d[st],st});
	while(!q.empty()){
		pll top=q.top();q.pop();
		ll u=top.second,kc=top.first;
		if(d[u]<kc) continue;
		for(pll x:ke[u]){
			ll v=x.first,w=x.second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<d[i]<<" ";
	}
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	dijkstra(0);
}

