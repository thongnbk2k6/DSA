#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define piii int,pair<int,int>
#define bit(n,i) ((n>>i)&1)
#define fi first
#define sc second
#define pdb pair<double,double>
#define db double

const long long maxn=1e6+5;
const long long minn=-1e6;
const long long MOD=1e9+7;
const long long inf=1e18;
int n,a[maxn],lz[maxn*4],sg[maxn*4];
void push(int id){
	if(lz[id]){
		sg[id*2]+=lz[id];
		sg[id*2+1]+=lz[id];
		lz[id*2]+=lz[id];
		lz[id*2+1]+=lz[id];
		lz[id]=0;
	}
}
void update(int id,int l,int r,int u,int v,int val){
	if(l>v||r<u){
		return;
	}
	if(u<=l&&r<=v){
		sg[id]+=val;
		lz[id]+=val;
		return;
	}
	int mid=(l+r)/2;
	push(id);
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	sg[id]=sg[id*2]+sg[id*2+1];
}
int getsum(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(u<=l&&r<=v){
		return sg[id];
	}
	int mid=(l+r)/2;
	push(id);
	return getsum(id*2,l,mid,u,v)+getsum(id*2+1,mid+1,r,u,v);
}
void nhap(){	
	cin>>n;
	memset(sg,0,sizeof(sg));
	memset(lz,0,sizeof(lz));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(1,1,n,i,i,a[i]);
	}
}
void solve(){
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op==1){
			int u,v;cin>>u>>v;
			cout<<getsum(1,1,n,u,v)<<endl;
		}
		if(op==2){
			int u,v,val;cin>>u>>v>>val;
			update(1,1,n,u,v,val);
		}
	}

}
int main(){
	faster
	nhap();
	solve();
	




	return 0;
}

