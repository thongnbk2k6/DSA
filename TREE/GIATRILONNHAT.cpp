#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5;
const int minN=-1e5;
int t[maxN],lazy[maxN],n,q,a[maxN];
void push(int id){
	if(lazy[id]){
		t[id*2]+=lazy[id];
		t[id*2+1]+=lazy[id];
		lazy[id*2]+=lazy[id];
		lazy[id*2+1]+=lazy[id];
		lazy[id]=0;
	}
}
void build(int id,int l,int r){
	if(l==r){
		t[id]=a[l];
		lazy[id]=0;
		return ;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	t[id]=max(t[id*2],t[id*2+1]);
}
void update(int id,int l,int r,int u,int v,int x){
	if(l>v||r<u) return;
	if(l >= u && r <= v){
		t[id] += x;
		lazy[id] += x;
		return;
	}
	int mid=(l+r)/2;
	push(id);
	update(id*2,l,mid,u,v,x);
	update(id*2+1,mid+1,r,u,v,x);
	t[id]=max(t[id*2],t[id*2+1]);
}
long long get(int id,int l,int r,int u,int v){
	if(l>v||r<u) return -1e9;
	if(u<=l&&r<=v){
		return t[id];
	}
	int mid=(l+r)/2;
	push(id);
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
main(){
	memset(t,0,sizeof(t));
	memset(lazy,0,sizeof(lazy));
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	while(q--){
		int op,x,y,k;cin>>op>>x>>y;
		if(op){
			cin>>k;
			update(1,1,n,x,y,k);
		}
		else{
			cout<<get(1,1,n,x,y)<<endl;
		}
	}
}

