#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
ll n,m,k,parent[maxn];
vector<pll>ke[maxn];
vector<pll>dinh[maxn];
map<pair<int,int>,int>mp;
void nhap(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v;
		w=pow(2,i);
		ke[u].push_back({v,w});
		ke[v].push_back({u,w});
	}
	for(int i=1;i<n;i++){
		pair<int,int>x1={i,i+1};
		pair<int,int>x2={i+1,i};
		mp[x1]=i;
		mp[x2]=i;
	}
}

void dijkstra(int s,int t){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	vector<int>d(n+1,inf);
	d[s]=0;
	q.push({d[s],s});
	while(!q.empty()){
		pair<int,int>top=q.top();q.pop();
		int kc=top.first;
		int u=top.second;
		if(d[u]<kc) continue;
		for(pair<int,int> x:ke[u]){
			int v=x.first;
			int w=x.second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({d[v],v});
				parent[v]=u;
			}
		}
	}
//	map<int,int>mp;
//	while(s!=t){
//		mp[t]++;
//		t=parent[t];
//	}
//	mp[s]++;
//	for(int i=1;i<=n;i++){
//		cout<<mp[i]<<" ";
//	}
	vector<int>v;
	while(s!=t){
		v.push_back(t);
		t=parent[t];
	}
	v.push_back(s);
	reverse(v.begin(),v.end());
	vector<int>v1(n+1,0);
	for(int i=0;i<v.size()-1;i++){
		int x1=v[i],x2=v[i+1];
		pair<int,int>x={x1,x2};
		v1[mp[x]]=1;
	}
	for(int i=1;i<=n;i++){
		cout<<v1[i]<<" ";
	}
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	for(int i=1;i<=k;i++){
		int x,y;cin>>x>>y;
		dijkstra(x,y);
	}

}

