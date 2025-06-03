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

const long long maxn=300005;
const long long minn=-1e6;
const long long inf=1e18;
struct DSUROLLBACK{
	int n;
	int par[maxn],sz[maxn];
	vector<pii>stack;
	int cur=-1;
	int comp;
	int compsz[maxn];
	void khoitao(int n){
		cur=-1;
		comp=n;
		for(int i=1;i<=n;i++){
			par[i]=i;
			sz[i]=1;
		}
	}
	int find(int u){
		if(u==par[u]) return u;
		return find(par[u]);
	}
	void merge(int a,int b){
		a=find(a);b=find(b);
		if(a!=b){
			if(sz[a]<sz[b]) swap(a,b);
			par[b]=a;
			sz[a]+=sz[b];
			stack.pb({b,a});
			cur++;
			compsz[cur]=comp;
			comp--;
		}
	
	}
	void rollback(int st){
		while(cur>st){
			par[stack[cur].fi]=stack[cur].fi;
			sz[stack[cur].sc]-=sz[stack[cur].fi];
			comp=compsz[cur];
			cur--;
			stack.pop_back();
		}
	}
}curuf;
vector<pii>ans;
vector<pii>t[1200005];
int query[300005];
pii tmp;
void update(int id,int l,int r,int u,int v){
	if(l>v||r<u) return;
	if(u<=l&&r<=v){
		t[id].pb({tmp});
		return;
	}
	int mid=(l+r)>>1;
	update(id<<1,l,mid,u,v);
	update(id<<1|1,mid+1,r,u,v);

}
void dfs(int id,int l,int r){
	int pre=curuf.cur;
	for(pii v:t[id]){
		curuf.merge(v.fi,v.sc);
	}
	if(l==r){
		if(query[l]!=-1){
			ans.pb({query[l],curuf.comp});
		}
	}else{
		int mid=(l+r)>>1;
		dfs(id<<1,l,mid);
		dfs(id<<1|1,mid+1,r);
	}
	curuf.rollback(pre);
}


void solve(){
	int n,k;cin>>n>>k;
	curuf.khoitao(n);
	map<pii,int>mp;
	// memset(query,-1,sizeof(query));
	for(int i=0;i<k;i++){
		int op;cin>>op;
		if(op==1){
			int a,b;cin>>a>>b;
			if(a>b) swap(a,b);
			mp[{a,b}]=i;
			query[i]=i;
		}else if(op==2){
			int a,b;cin>>a>>b;
			if(a>b) swap(a,b);
			tmp={a,b};
			update(1,0,k,mp[tmp],i);
			if(mp.find(tmp)!=mp.end()) mp.erase(mp.find(tmp));
			query[i]=i;
		}
	}
	for(auto x:mp){
		tmp=x.fi;
		update(1,0,k-1,x.sc,k-1);
	}
	dfs(1,0,k-1);
	sort(all(ans));
	for(pii x:ans) cout<<x.fi<<" "<<x.sc<<endl;

}
int main(){
	faster
	solve();




	return 0;
}
