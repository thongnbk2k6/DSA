#include<bits/stdc++.h>
using namespace std;
const long long inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int n,p,parent[maxn];
bool vs[maxn],vs1[1001];
bool oksub1=1;
ll a[maxn];
vector<pair<int,ll>>ke[100001];
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
//		if(a[i]!=0) oksub1=0;
	}
	cin>>p;
	for(int i=1;i<=p;i++){
		int u,v,w;cin>>u>>v>>w;
		ke[u].push_back({v,w});
		ke[v].push_back({u,w});
	}
	memset(vs,0,sizeof(vs));
	memset(vs,0,sizeof(vs1));
//	cout<<endl<<endl;
//	for(int i=1;i<=n;i++){
//		sort(ke[i].begin(),ke[i].end(),cmp);
//		for(edge x:ke[i]) {
//			cout<<i<<" "<<x.v<<" "<<x.w<<" "<<x.banh<<endl;
//		}
//		cout<<endl;
//	}
	
}
ll ansbanh=0;
void xuly2(ll trongso,ll ts,ll banh,int u){
	vs[u]=1;
	if(u==n){
		ansbanh=max(ansbanh,banh+a[n]);
		return;
	}
	for(pair<int,ll>x:ke[u]){
		if(ts+x.second<=trongso&&!vs[x.first]){
			xuly2(trongso,ts+x.second,banh+a[u],x.first);
			vs[x.first]=0;
		}
	}
	
}
void xuly(int st,int ed){
	priority_queue<pll,vector<pll>,greater<pll>>q;
	vector<ll>d(n+1,inf);
	d[st]=0;
	q.push({d[st],st});
	while(!q.empty()){
		pll top=q.top();q.pop();
		ll kc=top.first;
		int u=top.second;
		if(u==n) continue;
		if(vs1[u]) continue;
		
		vs1[u]=1;
		for(pll x:ke[u]){
			
				
			int v=x.first;
			ll w=x.second;
			if(!vs1[v]&&d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({d[v],v});
//					parent[v]=u;
			}
		}
			
	}
	
	if(d[ed]==inf) cout<<"impossible"<<endl;
	else{
		xuly2(d[ed],0,0,1);
		cout<<d[ed]<<" "<<ansbanh;
	}
}
main(){
//	freopen("quanho.inp","r",stdin);
//	freopen("quanho.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	xuly(1,n);
}

