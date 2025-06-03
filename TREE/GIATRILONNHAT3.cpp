#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;
long long t[200000],lazy[200000],n,m;
void update(int id,int l,int r,int x,int y,int k){
	if(l>y||r<x) return;
	if(x<=l&&r<=y){
		t[id]+=k;
		lazy[id]+=k;
		return;
	}
	int mid=(l+r)/2;
//	if(lazy[id]){
//		update(id*2,l,mid,l,mid,k);
//		update(id*2+1,mid+1,r,mid+1,r,k);
//		lazy[id]=0;
//	}
	update(id*2,l,mid,x,y,k);
	update(id*2+1,mid+1,r,x,y,k);
	t[id]=max(t[id*2],t[id*2+1])+lazy[id];
}
long long get(int id,int l,int r,int x,int y){
	if(l>y||r<x) return 0;
	if(x<=l&&r<=y) return t[id];
	int mid=(l+r)/2;
//	if(lazy[id]){
//		t[id*2]+=lazy[id];
//		t[id*2+1]+=lazy[id];
//		lazy[id*2]+=lazy[id];
//		lazy[id*2+1]+=lazy[id];
//		lazy[id]=0;
//	}
	return max(get(id*2,l,mid,x,y),get(id*2+1,mid+1,r,x,y))+lazy[id];
} 
main(){
	memset(t,0,sizeof(t));
	memset(lazy,0,sizeof(lazy));
	cin>>n>>m;
	while(m--){
		int op,x,y,k;cin>>op>>x>>y;
		if(op){
			cout<<get(1,1,n,x,y)<<endl;
		}else{
			cin>>k;
			update(1,1,n,x,y,k);
		}
	}
}

