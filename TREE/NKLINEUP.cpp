#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6+1;
int tmin[maxN],tmax[maxN],a[maxN],n,k;
void buildtree(int id,int l,int r){
	if(l==r){
		tmin[id]=a[l];
		tmax[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	buildtree(id*2,l,mid);
	buildtree(id*2+1,mid+1,r);
	tmin[id]=min(tmin[id*2],tmin[id*2+1]);
	tmax[id]=max(tmax[id*2],tmax[id*2+1]);
}
int get(int id,int l,int r,int u,int v,bool b){
	if(l>v||r<u) {
		if(b) return -1e5;
		if(b==0) return 1e5;
	}
	if(u<=l&&r<=v){
		if(b==1){
			return tmax[id];
		}
		if(b==0){
			return tmin[id];
		}
	}
	int mid=(l+r)/2;
	int t1=get(id*2,l,mid,u,v,b);
	int t2=get(id*2+1,mid+1,r,u,v,b);
	if(b==0) return min(t1,t2);
	if(b) return max(t1,t2);
}
main(){
	freopen("nklineup.inp","r",stdin);
	freopen("NKLINEUP.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	buildtree(1,1,n);
	for(int i=1;i<=k;i++){
		int u,v;cin>>u>>v;
		int t1=get(1,1,n,u,v,1);
		int t2=get(1,1,n,u,v,0);
		cout<<t1-t2<<endl;
	}
}

