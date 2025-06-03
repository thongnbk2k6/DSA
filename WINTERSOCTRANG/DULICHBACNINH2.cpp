#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
const int inf=1e7;
int n,p;
ll a[maxn];
vector<pair<int,ll>>ke[100001];
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>p;
	for(int i=1;i<=p;i++){
		int u,v,w;cin>>u>>v>>w;
		ke[u].push_back({v,w});
		ke[v].push_back({u,w});
	}
}
void dijkstra(int st){
	priority_queue<pll,vector<pll>,greater<pll>>q;
	vector<ll>d(n+1,inf);
	d[st]=0;
	q.push({d[st],st});
	while(!q.empty()){
		pll top=q.top();q.pop();
		int u=top.second;
		ll kc=top.first;
//		if(d[u]<kc) continue;
		for(pll x:ke[u]){
			int v=x.first;
			ll w=x.second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
	if(d[n]==inf) cout<<"impossible";
	else cout<<d[n]<<" "<<0;
}
main(){
//	freopen("quanho.inp","r",stdin);
//	freopen("quanho.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	dijkstra(1);
}

