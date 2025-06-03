#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define piii int,pair<int,int>
#define bit(n,i) ((n>>i)&1)
#define fi first
#define sc second
#define pdb pair<double,double>
#define db double
#define int long long
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
int n,q,a[maxn],bit[maxn];
void build(int x,int val){
	while(x<=n){
		bit[x]=min(bit[x],val);
		x+=x&-x;
	}
}
void update(int vt){
	if(vt>n) return;
	int pre=vt-1,left=vt-(vt&-vt)+1;
	bit[vt]=a[vt];
	while(left<=pre){
		bit[vt]=min(bit[vt],bit[pre]);
		pre-=pre&-pre;
	}
	update(vt+(vt&-vt));
}
int getmin(int l,int r){
	int ans=inf;
	while(l<=r){
		int x=r-(r&-r)+1;
		if(l<=x){
			ans=min(ans,bit[r]);
			r-=r&-r;
		}else{
			ans=min(ans,a[r]);
			r--;
		}
	}
	return ans;
}
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bit[i]=inf;
	}
	for(int i=1;i<=n;i++){
		build(i,a[i]);
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op){
			int l,r;cin>>l>>r;
			cout<<getmin(l,r)<<endl;
		}else{
			int x,val;cin>>x>>val;
			a[x]=val;
			update(x);
		}
	}
}
void solve(){


}
 main(){
	faster
	nhap();
	solve();
	




	return 0;
}

