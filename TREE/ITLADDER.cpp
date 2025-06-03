#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;
int n,m,t[maxN*4],lz[maxN*4],a[maxN];
void build(int id,int l,int r){
	if(l==r){
		t[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	t[id]=min(t[id*2],t[id*2+1]);
}
int get(int id,int l,int r,int u,int v,int k){
	if(l>pos||pos>r||t[id]<=k) return 1e6;
	if(l<=pos&&pos<=r&&t[id]>k){
		return t[id];
	}
	int mid=(l+r)/2;
	return min(get(id*2,l,mid,pos,k),get(id*2+1,mid+1,r,pos,k));
}
main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=m;j++){
		int op,l,i,v;cin>>op>>l>>i;
		if(op==2){
			cin>>v;
			cout<<get(1,1,n,l,i,v)<<endl;
		}
		if(op==1){
			update(1,1,n,l,i);
		}
	}
}

