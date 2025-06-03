#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;
int n,q,tmax[10001],tmin[1001],lazy[10001],t0=0;
void update(int id,int l,int r,int u,int v,int x){
	if(l==r) {
		t0=max(t0,id);
		tmin[id]+=x;
		tmax[id]+=x;
		lazy[id]+=x;
		return;
	}
	if(l>v||r<u) return;
	int mid=(l+r)/2;
	if(lazy[id]){
		tmax[id*2]+=lazy[id];
		tmax[id*2+1]+=lazy[id];
		tmin[id*2+1]+=lazy[id];
		tmin[id*2]+=lazy[id];
		lazy[id*2]+=lazy[id];
		lazy[id*2+1]+=lazy[id];
		lazy[id]=0;
	}
	update(id*2,l,mid,u,v,x);
	update(id*2+1,mid+1,r,u,v,x);
	tmin[id]=min(tmin[id*2],tmin[id*2+1]); 
	tmax[id]=max(tmax[id*2],tmax[id*2+1]);
}
long long get(int id,int l,int r,int u,int v,bool b){
	if(l>v||r<u) {
		if(b){
			return -1e6;
		}
		else return 1e6;
	}
	if(u<=l&&r<=v){
		if(b){
			return tmax[id];
		}
		else return tmin[id];
	}
	int mid=(l+r)/2;
	if(lazy[id]){
		if(b){
			tmax[id*2]+=lazy[id];
			tmax[id*2+1]+=lazy[id];
		}
		else{
			tmin[id*2]+=lazy[id];
			tmin[id*2+1]+=lazy[id];
		}
		lazy[id*2]+=lazy[id];
		lazy[id*2+1]+=lazy[id];
		lazy[id]=0;
	}
	if(b){
		return max(get(id*2,l,mid,u,v,b),get(id*2+1,mid+1,r,u,v,b));
	}
	else return min(get(id*2,l,mid,u,v,b),get(id*2+1,mid+1,r,u,v,b));
	
}
main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		update(1,1,n,i,i,x);
	}
//	for(int i=1;i<=t0;i++){
//		cout<<tmin[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=t0;i++){
//		cout<<tmax[i]<<" ";
//	}
//	return 0;
	while(q--){
		int l,r,x;cin>>l>>r>>x;
		update(1,1,n,l,r,x);
		long long t1=get(1,1,n,l,r,1);
		long long t2=get(1,1,n,l,r,0);
		cout<<t1-t2<<endl;
	}
	
}

