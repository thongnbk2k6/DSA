#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
const int minn=-1e6;
int a[maxn],t[maxn*4],n,q;
void build(int id,int l,int r){
	if(l==r){
		t[id]=a[l];
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	t[id]=min(t[id*2],t[id*2+1]);
}
void update(int id,int l,int r,int pos,int k){
	if(pos>r||pos<l){
		return;
	}
	if(l==r){
		t[id]=k;
		a[l]=k;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,k);
	update(id*2+1,mid+1,r,pos,k);
	t[id]=min(t[id*2],t[id*2+1]);
}
int get(int id,int l,int r,int u,int v,int k){
	if(l>v||r<u) return 1e6;
	if(u<=l&&r<=v){
		return t[id];
	}
	int mid=(l+r)/2;
	return min(get(id*2,l,mid,u,v,k),get(id*2+1,mid+1,r,u,v,k));
}
main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=q;j++){
		int op,x,y,k;cin>>op>>x>>y;
		if(op==1){
			cin>>k;
			update(1, 1, n,x , y);
//			for(int i=x;i<=y;i++){
//				if(i == k) continue;
//				update(1, 1, n, i, k);
//			}
		}
		if(op=2){
			cout<<get(1,1,n,x,y, k)<<endl;
		}
	}
}

