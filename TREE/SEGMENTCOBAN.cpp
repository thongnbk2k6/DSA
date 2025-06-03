#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define piii pair<int,int>,int
#define bit(n,i) ((n>>i)&1)
#define fi first
#define sc second
#define pdb pair<double,double>
#define db double

const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
int n,q,a[maxn],t[maxn*4];
void update(int id,int l,int r,int pos){
	if(l>pos||r<pos) return ;
	if(l==r){
		t[id]=a[pos];
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos);
	update(id*2+1,mid+1,r,pos);
	t[id]=t[id*2]+t[id*2+1];
}
ll getsum(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(u<=l&&r<=v) return t[id];
	int mid=(l+r)/2;
	return getsum(id*2,l,mid,u,v)+getsum(id*2+1,mid+1,r,u,v);
}

void solve(){
	memset(t,0,sizeof(t));
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op==1){
			int x,y;cin>>x>>y;
			a[x]=y;
			update(1,1,n,x);
		}else{
			int l,r;cin>>l>>r;
			cout<<getsum(1,1,n,l,r)<<endl;
		}
	}

}
int main(){
	faster

	solve();




	return 0;
}

