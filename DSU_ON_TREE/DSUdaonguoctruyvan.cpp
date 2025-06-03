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

const long long maxn=1e5+5;
const long long minn=-1e6;
const long long inf=1e18;
int n,a[maxn],p[maxn],par[maxn],sz[maxn],sum[maxn],ans[maxn],res=0;
bool check[maxn];
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		par[i]=i;
		sz[i]=1;
		sum[i]=a[i];
		ans[i]=0;
		check[i]=0;
	}
	for(int i=1;i<=n;i++) cin>>p[i];
}
int get(int u){
	if(u==par[u]) return u;
	return par[u]=get(par[u]);
}
void Union(int u,int v){
	u=get(u);
	v=get(v);
	if(u==v) return;
	if(sz[u]<sz[v]) swap(u,v);
	par[v]=u;
	sz[u]+=sz[v];
	sum[u]+=sum[v];
	
}
void solve(){
	for(int i=n;i>=1;i--){
		check[p[i]]=1;
		if(p[i]>1&&check[p[i]-1]) Union(p[i],p[i]-1);
		if(p[i]<n&&check[p[i]+1]) Union(p[i],p[i]+1);
		ans[i-1]=max(ans[i-1],sum[get(p[i])]);
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;

}
int main(){
	faster
	nhap();
	solve();




	return 0;
}
