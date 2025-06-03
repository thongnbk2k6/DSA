#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
ll n,q,a[maxn],t[maxn*4],uocle[maxn];
void nhap(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
}
ll Uoc(ll n){
	if(n==0) return n;
	n=abs(n);
	while(n%2==0){
		n/=2;
	}
	return n;
}
void build_tree(int id,int l,int r){
	if(l==r){
		t[id]=a[Uoc(l)]+a[l];//t[id]=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build_tree(id*2,l,mid);
	build_tree(id*2+1,mid+1,r);
	t[id]=t[id*2]+t[id*2+1];
}
ll Get(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(u<=l&&r<=v) return t[id];
	int mid=(l+r)/2;
	return Get(id*2,l,mid,u,v)+Get(id*2+1,mid+1,r,u,v);
}
void Upd(int id,int l,int r,int u){
	if(l>u||r<u) return ;
	if(l==r){
		t[id]=a[l]+a[Uoc(l)];
		return;
	}
	int mid=(l+r)/2;
	Upd(id*2,l,mid,u);
	Upd(id*2+1,mid+1,r,u);
	t[id]=t[id*2]+t[id*2+1];
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	build_tree(1,1,n);
	while(q--){
		ll op,x,y;cin>>op>>x>>y;
		if(op==1){
			a[x]=y;
			Upd(1,1,n,x);
			if(x%2!=0) {
				while(x<=n){
					Upd(1,1,n,x);
				x*=2;
				}
			}
		
		}else if(op==2){
			cout<<Get(1,1,n,x,y)<<endl;
		}
	}
//	int n;cin>>n;
//	cout<<Uoc(n);
//	
}

