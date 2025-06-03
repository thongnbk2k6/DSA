#include<bits/stdc++.h>
using namespace std;
int Tree[4001],a[1001],n,k,t0=0;
void buildtree(int id,int l,int r){
	if(l==r) {
		t0=max(t0,id);
		Tree[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	buildtree(id*2,l,mid);
	buildtree(id*2+1,mid+1,r);
	Tree[id]=min(Tree[id*2],Tree[id*2+1]);
}
int get(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 1e6;
	if(u<=l&&r<=v) return Tree[id];
	int mid=(l+r)/2;
	int t1=get(id*2,l,mid,u,v);
	int t2=get(id*2+1,mid+1,r,u,v);
	return min(t1,t2);
}
void update(int id,int l,int r,int pos){
	if(pos<l||pos>r ) return;
	if(l==r) {
		Tree[id]=a[pos];
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos);
	update(id*2+1,mid+1,r,pos);
	Tree[id]=min(Tree[id*2],Tree[id*2+1]);
}
main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	buildtree(1,1,n);
//	for(int i=1;i<=t0;i++) cout<<Tree[i]<<" ";
	cin>>k;
	for(int i=1;i<=k;i++){
		int x,u,v;cin>>x>>u>>v;
		if(x){
			a[u]=v;
			update(1,1,n,u);
		}
		else {
			cout<<get(1,1,n,u,v)<<endl;
		}
	}
}

