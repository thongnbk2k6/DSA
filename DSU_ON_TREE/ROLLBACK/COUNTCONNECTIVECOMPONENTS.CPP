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

const long long maxn=1e4+5;
const long long minn=-1e6;
const long long inf=1e18;
int n,q,ans[maxn];
vector<int>queries[maxn];
map<pii,vector<pii>>graph;
int par[maxn],r[maxn];
int *t[maxn],v[maxn];
int thaydoi[maxn];
int nc,sz=0;
void nhap(){
	cin>>n>>q;
	for(int i=0;i<q;i++){
		int k,u,v;cin>>k>>u>>v;
		queries[i].pb(k);
		queries[i].pb(u);
		queries[i].pb(v);
	}
}
void proprocess(){
	nc=n;
	for(int i=0;i<q;i++){
		int k=queries[i][0],u=queries[i][1],v=queries[i][2];
		if(u>v) swap(u,v);
		if(k==1){
			graph[{u,v}].pb({i,q});
		}else{
			graph[{u,v}].back().second=i-1;

		}
	}


}
int setv(int *a,int b,int toadd){
	t[sz]=a;
	v[sz]=*a;
	*a=b;
	thaydoi[sz]=toadd;
	++sz;
	return b;
}
void rollback(int x){
	for(;sz>x;){
		--sz;
		*t[sz]=v[sz];
		nc+=thaydoi[sz];
	}
}
int find(int u){
	return par[u]?find(par[u]):u;
}
bool merge(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b) return 0;
	nc--;
	if(r[b]>r[a]) swap(a,b);
	setv(r+b,r[a]+r[b],0);
	return setv(par+b,a,1),1;
}

void solve(int l,int r){
	int tmp=sz;
	for(auto it=graph.begin();it!=graph.end();it++){
		int u=it->fi.fi;
		int v=it->fi.sc;
		for(auto it2=it->sc.begin();it2!=it->sc.end();it2++){
			int w=it2->fi,c=it2->sc;
			if(w<=l&&c>=r){
				merge(u,v);
				break;
			}
		}
	}
	if(l==r){
		ans[l]=nc;
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid);
	solve(mid+1,r);
	rollback(tmp);

}
int main(){
	faster
	nhap();
	proprocess();
	solve(0,q);
	for(int i=0;i<q;i++){
		cout<<ans[i]<<" ";
	}




	return 0;
}
