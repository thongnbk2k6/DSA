#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;
int Tree[maxN],a[10001],n,k,k0=0;
int add(int i,int j){
	return (a[i]>a[j])?i:j;
//	if(a[i]>a[j]) return i;
//	else return j;
}
void buildtree(int id,int l,int r){
	if(l==r) {
		Tree[id]=l;
		k0=max(k0,id);
		return;
	}
		
	int mid=(l+r)/2;
	buildtree(id*2,l,mid);
	buildtree(id*2+1,mid+1,r);
	Tree[id]=add(Tree[id*2],Tree[id*2+1]);
}
void sonsung(int id,int u,int v,int pos){
	if(pos<u||pos>v) return;
	if(u<=pos&&pos<=v){
		Tree[id]=pos;
		return;
	}
	int mid=(u+v)/2;
	sonsung(id*2,u,mid,pos);
	sonsung(id*2+1,mid+1,v,pos);
	Tree[id]=add(Tree[id*2],Tree[id*2+1]);
}
int get(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(u<=l&&r<=v) return Tree[id];
	int mid=(l+r)/2;
	int t1=get(id*2,l,mid,u,v);
	int t2=get(id*2+1,mid+1,r,u,v);
	return add(t1,t2);
}
//const long long M=1e18;
int solve(int a,int b,long long M){
	if(b==0) return 0;
	int t=solve(a,b/2,M)*2;
	if(b%2) t+=a;
	return t%M;
}
main(){
	a[0]=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	buildtree(1,1,n);
	cin>>k;
	while(k--){
		int x,u,v;cin>>x>>u>>v;
		if(x){
			long long M;cin>>M;
			int p1=get(1,1,n,u,v);
			int p2=add(get(1,1,n,u,p1-1),get(1,1,n,p1+1,v));
//			cout<<p2;return 0;
			cout<<solve(a[p1],a[p2],M)<<endl;
		}
		else{
			a[u]=v;
			sonsung(1,1,n,u);
		}
	}
}

