#include<bits/stdc++.h>
using namespace std;
int Tree[4001];
int a[1001];
int n,tlength=0;
void build_tree(int id,int l,int r){
	tlength=max(tlength,id);
	if(l==r) {
		Tree[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build_tree(id*2,l,mid);//quang li phan doan ben trai
	build_tree(id*2+1,mid+1,r);//quang li phan doan ben phai
	Tree[id]=Tree[id*2]+Tree[id*2+1];
//	cout<<l<<" "<<r<<": "<<Tree[id]<<endl;
	
}
int tinh(int id,int be,int ed,int u,int v){
	if(be>v||ed<u) return 0;
	if(u<=be&&ed<=v) {
		return Tree[id];
	}
	int mid=(be+ed)/2;
	return tinh(id*2,be,mid,u,v)+tinh(id*2+1,mid+1,ed,u,v);
}
void update(int id,int be,int ed,int p){
	if(p<be||p>ed) return;
	if(be==ed) {
		Tree[id]=a[p];
		return;
	}
	
	int mid=(be+ed)/2;
	update(id*2,be,mid,p);
	update(id*2+1,mid+1,ed,p);
	Tree[id]=Tree[id*2]+Tree[id*2+1];
//	cout<<be<<" "<<ed<<": "<<Tree[id]<<endl;
}
void incay(int id,int be,int ed){
	if(be==ed) {
//		cout<<be<<" "<<Tree[id]<<endl;
		return;
	}
	int mid=(be+ed)/2;
	incay(id*2,be,mid);
	incay(id*2+1,mid+1,ed);
	cout<<Tree[id*2]+Tree[id*2+1]<<endl;
	
}
main(){
//	freopen("CAYPHANDOAN.inp","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	build_tree(1,1,n);
//	cout<<tlength<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<Tree[i]<<" ";
//	}
//	cout<<tinh(1,1,n,3,7);
	int val,p;cin>>p>>val;
	a[p]=val;
	update(1,1,n,p);
	incay(1,1,n);
}

