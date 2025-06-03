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
int n,q,up[100001][18],f[100001],h[100001];
vector<pii>ke[100001];
void nhap(){
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int u,v,w;cin>>u>>v>>w;
		ke[u].pb({v,w});
		ke[v].pb({u,w});
	}
	memset(f,0,sizeof(f));
	memset(h,0,sizeof(h));
}
void dfs(int u){
	for(pii e:ke[u]){
		int v=e.fi,w=e.sc;
		if(v==up[u][0]) continue;
		h[v]=h[u]+1;
		f[v]=f[u]+w;
		up[v][0]=u;
		for(int j=1;j<=17;j++){
			up[v][j]=up[up[v][j-1]][j-1];
		}
		dfs(v);
	}
}
int totienthuk(int u,int k){
	for(int j=0;(1<<j)<=k;j++){
		if(k>>j&1) u=up[u][j];
	}
	return u;
}
int dis(int u,int v){
	return f[u]-f[v];
}
bool check(int u,int k,int dismax){
	int v=totienthuk(u,k);
	int kc=dis(u,v);
	return kc<=dismax;
}
int timv(int u,int dismax){
	int lo=1,hi=h[u];
	while(lo<hi){
		int mid=lo+(hi-lo+1)/2;
		if(check(u,mid,dismax)){
			lo=mid;
		}else hi=mid-1;
	}
	if(!check(u,lo,dismax)) return -1;
	return lo;
 

}
void solve(){
	dfs(1);
	for(int i=1;i<=q;i++){
		int u,X;cin>>u>>X;
		int k=timv(u,X);
		if(k==-1) cout<<"NO";
		else cout<<totienthuk(u,k)<<endl;
	}
}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
