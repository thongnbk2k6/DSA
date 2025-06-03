#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define bit(n,i) ((n>>i)&1)
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
int n,a[maxn],t[maxn*4];
void build(int id,int l,int r){
	if(l==r){
		t[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	t[id]=t[id*2]+t[id*2+1];
}
int Get(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(u<=l&&r<=v) return t[id];
	int mid=(l+r)/2;
	return Get(id*2,l,mid,u,v)+Get(id*2+1,mid+1,r,u,v);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	cout<<Get(1,1,n,1,n);



	return 0;
}

