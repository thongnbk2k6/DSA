#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+1;
int Tree[maxN];
int n,k,a[maxN],k0=0;
//int timmin(int l,int r){
//	
//	if(r-l==1||r-l==0) {
//		return min(a[r],a[l]);
//	}
//	int mid=(l+r)/2;
//	return min(timmin(l,mid),timmin(mid+1,r));
//}
void tree(int k,int l,int r){
		
	if(l==r){
		k0=max(k0,k);
		Tree[k]=min(a[l],a[r]);
		return;
	}
	int mid=(l+r)/2;
	tree(k*2,l,mid);
	tree(k*2+1,mid+1,r);
	Tree[k]=min(Tree[k*2],Tree[k*2+1]);
	
}
int ans=1e6;
void truyvan(int k,int be,int ed,int u,int v){
	if(be>v||ed<u) return;
	if(be>=u&&ed<=v) {
		ans=min(ans,Tree[k]);
		return;
	}
	int mid=(be+ed)/2;
	truyvan(2*k,be,mid,u,v);
	truyvan(2*k+1,mid+1,ed,u,v);
	
}
main(){
	freopen("INTERVALTREE.inp","r",stdin);
	cin>>n>>k;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	tree(1,1,n);
//	for(int i=1;i<=k0;i++){
//		cout<<Tree[i]<<" ";
//	}
	while(k--){
		int x,u,v;cin>>x>>u>>v;
		if(x==1){
			truyvan(1,1,n,u,v);
			cout<<ans<<endl;
			ans=1e6;
		}
	}
		
}
