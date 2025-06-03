#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e6;
const int minn=-1e6;
ll n,q,lz[maxn*4],t[maxn*4],a[maxn];
void build(int id,int l,int r){
	if(l==r) {
		t[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	t[id]=max(t[id*2],t[id*2+1]);
}
void push(int id){
	if(!lz[id]) return;
	else{
		t[id*2]+=lz[id];
		t[id*2+1]+=lz[id];
		lz[id*2]+=lz[id];
		lz[id*2+1]+=lz[id];
		lz[id]=0;
	}
	
}
void update(int id,int l,int r,int u,int v,int val){
//	push(id);
	if(l>v||r<u) return;
	if(u<=l&&r<=v){
		t[id]+=val;
		lz[id]+=val;
		return;
	}
	int mid=(l+r)/2;
	push(id);
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(u<=l&&r<=v) {
		return t[id];
	}
	int mid=(l+r)/2;
	push(id);
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(lz,0,sizeof(lz));
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	cin>>q;
	for(int i=1;i<=q;i++){
		int op,x,y,v;cin>>op>>x>>y;
		if(op==1){
			cin>>v;
			update(1,1,n,x,y,v);
		}else{
			if(op==2) cout<<get(1,1,n,x,y)<<endl;
		}
	}
	return 0;

}

