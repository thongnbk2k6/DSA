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

const long long maxn=1e6+5;
const long long minn=-1e6;
const long long inf=1e18;
int n,m,ans_length=2505;
vector<int>adj[2505];
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
}
vector<int>dis;
void solve(){
	queue<int>q;
	for(int i=1;i<=n;i++){
		dis.assign(n+1,1e9+7);
		dis[i]=0;
		q.push(i);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int v:adj[u]){
				if(dis[v]==1e9+7){
					dis[v]=dis[u]+1;
					q.push(v);
				}else if(dis[v]>=dis[u]){
					ans_length=min(ans_length,dis[u]+dis[v]+1);//them 1 canh giua u va v
				}
			}
		}
	}
	if(ans_length==2505) cout<<-1;
	else cout<<ans_length;

}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
