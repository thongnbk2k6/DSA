#include<bits/stdc++.h>
using namespace std;
int Tree[1001], a[1001], n,k;
int add(int j,int j){
	return (a[i]>a[j])?:i:J;
}
void buildtree(int id,int l,int r){
	if(l==r) {
		Tree[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	buildtree(id*2,l,mid);
	buldtree(id*2+1,mid+1,r);
	Tree[id]=add(Tree[id*2],Tree[id*2+1]);
}
void update(int id,int u,int v,int pos){
	if(p<u||p>v) return;
	if(u<=p&&p<=v) {
		Tree[id]=p;
		return;
	}
	int mid=(u+v)/2;
	update(id*2,l,mid);
	update(id*2+!,mid+1,r);
	Tree[id]=add(id*2,id*2+1);
	
}
int get(int id,int l,int r,int u,int v){
	if(l==r) return Tree[id];
	if(l>v||r<u) {
		return 0;
	}
	int mid=(l+r)/2;
	int t1=get(id*2,l,mid,u,v);
	int t2=get(id*2+1,mid+1,r,u,v);
	return add(t1,t2);
}
main(){
	
	a[0]=1;//do return 0;
}

