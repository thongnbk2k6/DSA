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
set<int>se[30001];
bool vs[30001];
int p,c,n;
int par[30001];
void nhap(){
	cin>>p>>c>>n;
	for(int i=1;i<=c;i++){
		int u,v;cin>>u>>v;
		se[u].insert(v);
		se[v].insert(u);
	}
	memset(vs,0,sizeof(vs));
}
void bfs(int st){
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:se[u]){
			if(!vs[v]){
				vs[v]=1;
				q.push(v);
				par[v]=u;
			}
		}
	}
	for(int i=2;i<=p;i++){
		int count=0;
		if(se[i].size()==1){
			// int u=i;
			// while(u!=1){
			// 	u=par[u];
			// 	count++;
			// 	if(u==n){
			// 		cout<<++count;
			// 		return;
			// 	}
			// }
			cout<<i<<endl;
		}
	}
}
void solve(){
	bfs(1);

}
int main(){
	faster
	nhap();
	solve();	




	return 0;
}
