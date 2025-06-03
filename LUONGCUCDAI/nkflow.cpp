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

const long long maxn=1e6+5;
const long long minn=-1e6;
const long long MOD=1e9+7;
const long long inf=1e18;
int n,m,st,ed,f[1001][1001],c[1001][1001],maxflow,trace[maxn];
vector<int>ke[100001];
void nhap(){
	cin>>n>>m>>st>>ed;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		cin>>c[u][v];
		c[v][u]=c[u][v];
		ke[u].pb(v);
		ke[v].pb(u);
	}
}
void bfs(){
	memset(trace,0,sizeof(trace));
	trace[st]=1;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:ke[u]){
			if(trace[v]) continue;
			if(f[u][v]-c[u][v]==0) continue;
			trace[v]=u;
			q.push(v);
		}
	}
}
void tangluong(){
	int del=1e9+1;
	int v=ed;
	while(v!=st){
		int u=trace[v];
		del=min(del,c[u][v]-f[u][v]);
		v=u;
	}
	maxflow+=del;
	v=ed;
	while(v!=st){
		int u=trace[v];
		f[u][v]+=del;
		f[v][u]-=del;
		v=u;
	}
	

}
int main(){
	faster
	nhap();
	maxflow=0;
	do{
		bfs();
		if(trace[ed]) tangluong();
	}while(trace[ed]);
	cout<<maxflow;



	return 0;
}

