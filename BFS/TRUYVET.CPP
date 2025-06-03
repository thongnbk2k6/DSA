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
vector<int>ke[100001];
int n,m,par[100001];
bool vs[100001];
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		ke[u].pb(v);
		ke[v].pb(u);
	}
	memset(vs,0,sizeof(vs));
}
void bfs(int st){
	vs[st]=1;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:ke[u]){
			if(!vs[v]){
				par[v]=u;
				vs[v]=1;
				q.push(v);
			}
		}
	}
}
void solve(){
	int st,ed;cin>>st>>ed;
	bfs(st);
	if(!vs[ed]) {
		cout<<"NO PATH FROM "<<st<<" TO "<<ed<<endl;
		return;
	}else{
		vector<int>path;
		while(ed!=st){
			path.pb(ed);
			ed=par[ed];
		}
		path.pb(st);
		reverse(all(path));
		for(int x:path) cout<<x<<" ";
	}



}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
