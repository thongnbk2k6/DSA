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
int n,m;
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
	queue<int>q;
	q.push(st);
	vs[st]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:ke[u]){
			if(!vs[v]){
				q.push(v);
				vs[v]=1;
			}
		}
	}
}
void solve(){
	int count=0;
	for(int i=1;i<=n;i++){
		if(!vs[i]){
			bfs(i);
			count++;
		}
	}
	cout<<count;

}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
