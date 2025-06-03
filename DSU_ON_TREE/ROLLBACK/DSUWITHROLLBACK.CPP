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
	int cur=-1;
	int sz[maxn],par[maxn];
	vector<pii>stack;
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
	void merge(int u,int v){
		u=find(u);v=find(v);
		if(u!=v){
			if(sz[u]<sz[v]) swap(u,v);
			sz[u]+=sz[v];
			par[v]=u;
			stack.pb({v,u});
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
int query[maxn];
vector<pii>t[1200005];
vector<pii>ans;
pii tmp;
vector<pii>dem;
void update(int id,int l,int r,int u,int v){
	if(l>v||r<u) return;
	if(l>=u&&r<=v){
		t[id].pb(tmp);
		return;
	}
	int mid=(l+r)>>1;
	update(id<<1,l,mid,u,v);
	update(id<<1|1,mid+1,r,u,v);
}
void dfs(int id,int l,int r){
	int pre=curuf.cur;
	for(pii x:t[id]){
		curuf.merge(x.fi,x.sc);
	}
	if(l==r){
		ans.pb({query[l],curuf.comp});
		
	}else{
		int mid=(l+r)>>1;
		dfs(id<<1,l,mid);
		dfs(id<<1|1,mid+1,r);
	}
	curuf.rollback(pre);
}



void solve(){
	int n,q;cin>>n>>q;
	curuf.khoitao(n);
	map<pii,int>mp;
	for(int i=0;i<q;i++){
		int k,u,v;cin>>k>>u>>v;
		if(u>v) swap(u,v);
		if(k==1){
			mp[{u,v}]=i;
		}else{
			tmp={u,v};
			update(1,0,q,mp[tmp],i);
			if(mp.find(tmp)!=mp.end()) mp.erase(mp.find(tmp));
		}
		query[i]=i;
	}
	for(auto x:mp){
		tmp=x.fi;
		update(1,0,q-1,x.sc,q-1);
	}
	dfs(1,0,q-1);
	sort(all(ans));
	for(pii x:ans){
		cout<<x.sc<<endl;
	}

}
int main(){
	faster
	solve();




	return 0;
}
