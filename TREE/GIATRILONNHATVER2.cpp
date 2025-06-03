#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;
int t[50001],lazy[50001],n,m,t0=0;
void push(int id){
	t[id*2]+=lazy[id];
	t[id*2+1]+=lazy[id];
	lazy[id*2]+=lazy[id];
	lazy[id*2+1]+=lazy[id];
	lazy[id]=0;
}
void update(int id,int l,int r,int u,int v,int x){
	if(l==r){
//		t0=max(t0,id);
		t[id]+=x;
		lazy[id]+=x;
		return;
	}
	if(l>v||r<u) return;
	if(lazy[id]) push(id);
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v,x);
	update(id*2+1,mid+1,r,u,v,x);
	t[id]=max(t[id*2],t[id*2+1]);
}
long long get(int id,int l,int r,int u,int v){
	if(l>v||r<u) return -1e6;
	if(u<=l&&l<=v) return t[id];
	if(lazy[id]) push(id);
	int mid=(l+r)/2;
	return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		update(1,1,n,i,i,x);
	}
//	for(int i=1;i<=t0;i++){
//		cout<<t[i]<<" ";
//	}
	while(m--){
		int op,x,y,k;cin>>op>>x>>y;
		if(op){
			cin>>k;
			update(1,1,n,x,y,k);
		}
		else {
			cout<<get(1,1,n,x,y)<<endl;
		}
	}
}

