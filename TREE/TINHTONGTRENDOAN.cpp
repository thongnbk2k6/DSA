#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;
int n,q,t0=0;
long long sg[40001],a[100001];
void build(int id,int l,int r){
	if(l==r){
		t0=max(t0,id);
		sg[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	sg[id]=sg[id*2]+sg[id*2+1];
	
}
void update(int id,int l,int r,int pos,int val){
	if(l>pos||r<pos) return;
	if(l==r){
		sg[id]=val;
		a[l]=val;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	sg[id]=sg[id*2]+sg[id*2+1];
}
long long get(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(u<=l&&r<=v) return sg[id];
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	while(q--){
		int k,x,y;cin>>k>>x>>y;
		if(k==1){
			update(1,1,n,x,y);
		}
		if(k==2){
			cout<<get(1,1,n,x,y)<<endl;
		}
	}
}

