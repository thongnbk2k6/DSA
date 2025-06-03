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
int n,m;
bool vs[100001];
vector<int>ke[10001];
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
		int u=q.front();q.pop();
		for(int v:ke[u]){
			if(!vs[v]){
				vs[v]=1;
				q.push(v);
			}
		}
	}
}
void solve(){
	bfs(1);
	bool bongoan=1;
	for(int i=1;i<=n;i++){
		if(!vs[i]) {
			cout<<i<<endl;
			bongoan=0;
		}
	}
	if(bongoan) cout<<0<<endl;

}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
