#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int n,m,q,t[maxn*4],lz[maxn*4];
void push(int id){
	if(lz[id]){
		t[id*2]+=lz[id];
		t[id*2+1]+=lz[id];
		lz[id*2]+=lz[id];
		lz[id*2+1]+=lz[id];
		lz[id]=0;
	}
}
void upd(int id,int l,int r,int u,int v,int val){
	if(l>v||r<u) return;
	if(u<=l&&r<=v){
		t[id]+=val;
		lz[id]+=val;
		return;
	}
	int mid=(l+r)/2;
	push(id);
	upd(id*2,l,mid,u,v,val);
	upd(id*2+1,mid+1,r,u,v,val);
	t[id]=max(t[id*2],t[id*2+1]);
}
int Get(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(u<=l&&r<=v){
		return t[id];
	}
	int mid=(l+r)/2;
	push(id);
	return max(Get(id*2,l,mid,u,v),Get(id*2+1,mid+1,r,u,v));
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	memset(t,0,sizeof(t));
	memset(lz,0,sizeof(lz));
	for(int i=1;i<=m;i++){
		int u,v,k;cin>>u>>v>>k;
		upd(1,1,n,u,v,k);
	}
	cin>>q;
	while(q--){
		int u,v;cin>>u>>v;
		cout<<Get(1,1,n,u,v)<<endl;
	}
}

