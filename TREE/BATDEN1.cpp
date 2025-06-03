#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;
int n,m,t[40001],lazy[400001];
void update(int id,int l,int r,int u,int v){
	if(l>v||r<u) return;
	if(u<=l&&r<=v){
		t[id]=(r-l+1)-t[id];
		lazy[id]^=1;	
		return;
	}
	int mid=(l+r)/2;
	if(lazy[id]){
		update(id*2,l,mid,l,mid);
		update(id*2+1,mid+1,r,mid+1,r);
		lazy[id]=0;
	}
	update( id*2,l,mid,u,v);
	update( id*2+1,mid+1,r,u,v);
	t[id]=t[id*2]+t[id*2+1];
}
int get(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(u<=l&&r<=v){
		return t[id];
	}
	int mid=(l+r)/2;
	if(lazy[id]){
		update(id*2,l,mid,l,mid);
		update(id*2+1,mid+1,r,mid+1,r);
		lazy[id]=0;
	}
	int t1=get(id*2,l,mid,u,v);
	int t2=get(id*2+1,mid+1,r,u,v);
	return t1+t2;
}
main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int k,x,y;cin>>k>>x>>y;
		if(k){
			update(1,1,n,x,y);
		}else{
			cout<<get(1,1,n,x,y)<<endl;
		}
	}
}

