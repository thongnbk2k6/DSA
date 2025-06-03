#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define bit(n,i) ((n>>i)&1)
#define fi first
#define sc second
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
int n,q,a[maxn],t[maxn*4];
void build_tree(int id,int l,int r){
	if(l==r) {
		t[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build_tree(id*2,l,mid);
	build_tree(id*2+1,mid+1,r);
	t[id]=t[id]*2+t[id*2+1];
}
void up(int id,int l,int r,int pos){
	if(r<pos||l>pos) return;
	if(l==r){
		t[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	up(id*2,l,mid,pos);
	up(id*2+1,mid+1,r,pos);
	t[id]=t[id*2]+t[id*2+1];
	
	
	
}
int get(int id,int l,int r,int pos){
	if(r<pos||l>pos) return 0;
	if(l==r){
		return t[id];
	}
	int mid=(l+r)/2;
	return get(id*2,l,mid,pos)+get(id*2+1,mid+1,r,pos);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build_tree(1,1,n);
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op==1) {
			int s,x;cin>>s>>x;
			a[s]=x;
			up(1,1,n,s);
		}
		else{
			int x;cin>>x;
			cout<<get(1,1,n,x)<<endl;
		}
	}




	return 0;
}

