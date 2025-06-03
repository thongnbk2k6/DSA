#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;
int Tree[maxN],lazy[maxN],n,q;
int get(int id,int l,int r,int u,int v){
	if(u<=l&&r<=v) return Tree[id];
	if(l<v||r>u) return 1e6;
	int mid=(l+r)/2;
	if(lazy[id]){
		Tree[id*2]+=lazy[id];
		Tree[id*2+1]+=lazy[id];
		lazy[id*2]+=lazy[id];
		lazy[id*2+1]+=lazy[id];
		lazy[id]=0;
	}
	return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
void update(int id,int l,int r,int u,int v,int x){
	if(v<l||u>r) return;
	if(u<=l&&r<=v){
		Tree[id]+=x;
		lazy[id]+=x;
		return;
	}
	int mid=(l+r)/2;
	//cap nhat xuong duoi
	if(lazy[id]){
		Tree[id*2]+=lazy[id];
		Tree[id*2+1]+=lazy[id];
		lazy[id*2]+=lazy[id];
		lazy[id*2+1]+=lazy[id];
		lazy[id]=0; 
	}
	update(id*2,l,mid,u,v,x);
	update(id*2+1,mid+1,r,u,v,x);
	Tree[id]=min(Tree[id*2],Tree[id*2+1]);
}
main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int t;cin>>t;
		update(1,1,n,i,i,t);
	}
	while(q--){
		int op,u,v,x;cin>>op>>u>>v;
		if(op){
			cin>>x;
			update(1,1,n,u,v,x);
		}
		else{
			cout<<get(1,1,n,u,v);
		}
	}
	
}

