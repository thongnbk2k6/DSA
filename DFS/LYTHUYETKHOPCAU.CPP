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
int n,m,cnt=0,numchild[10001],low[10001],num[10001];
pii canh[50001];
bool used[50001],khop[10001],cau[50001];
vector<int>edge[10001];
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		canh[i]={u,v};
		edge[u].pb(i);
		edge[v].pb(i);
		used[i]=0;
	}
	memset(numchild,0,sizeof(numchild));
}
void dfs(int u){
	low[u]=maxn+1;
	num[u]=++cnt;
	numchild[u]=0;
	for(int id:edge[u]){
		if(!used[id]){
			used[id]=1;
			int v=canh[id].fi+canh[id].sc-u;
			if(!num[v]){
				dfs(v);
				numchild[u]++;
				low[u]=min(low[u],low[v]);
				if(low[v]>num[u]) cau[id]=1;
				if(low[v]>=num[u]) khop[u]=1;
			}else low[u]=min(low[u],num[v]);
		}
	}

}
void solve(){
	for(int i=1;i<=n;i++){
		dfs(i);
		if(numchild[i]==1)	khop[i]=0;
	}
	// cout<<endl;
	int demkhop=0,demcau=0;
	for(int i=1;i<=n;i++){
		if(khop[i])  demkhop++;
	}
	for(int i=1;i<=m;i++){
		if(cau[i]) demcau++;
	}
	cout<<demkhop<<" "<<demcau;
	// for(int i=1;i<=n;i++){
	// 	cout<<i<<" "<<numchild[i]<<endl;
	// }
	
}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
