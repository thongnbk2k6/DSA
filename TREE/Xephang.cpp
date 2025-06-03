#include<bits/stdc++.h>
using namespace std;
int Treemin[4001],Treemax[4001],a[1001],n,k;
void build_tree(int id,int l,int r){
	if(l==r){
		Treemax[id]=Treemin[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build_tree(id*2,l,mid);
	build_tree(id*2+1,mid+1,r);
	Treemin[id]=min(Treemin[id*2],Treemin[id*2+1]);
	Treemax[id]=max(Treemax[id*2],Treemax[id*2+1]);
}
int get(int id,int l,int r,int u,int v,bool b){
	if(l>v||r<u){
		if(b==1) return -1e7;
		if(b==0) return 1e7;
	}
	if(l>=u&&r<=v){
		if(b==1){
			return Treemax[id];
		}
		if(b==0){
			return Treemin[id];
		}
	}
	int mid=(l+r)/2;
	int t1=get(id*2,l,mid,u,v,b);
	int t2=get(id*2+1,mid+1,r,u,v,b);
	if(b) return max(t1,t2);
	else return min(t1,t2);
}
main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build_tree(1,1,n);
	for(int i=1;i<=k;i++){
		int u,v;cin>>u>>v;
		int tmax=get(1,1,n,u,v,1);
		int tmin=get(1,1,n,u,v,0);
		cout<<tmax-tmin<<endl;
	}
}

