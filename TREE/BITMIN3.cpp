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

const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;

int n,q,a[maxn],bit[maxn];
void build(int vt,int val){
	bit[vt]=min(bit[vt],val);
	vt+=(vt&-vt);
	while(vt<=n){
		bit[vt]=min(bit[vt],val);
		vt+=(vt&-vt);
	}
}
void nhap(){
	cin>>n;
	memset(bit,0x3f,sizeof(bit));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		build(i,a[i]);
	}
}

int getmin(int l,int r){
	int ans=inf;
	while(l<=r){
		int x=r-(r&-r)+1;
		if(l<=x){
			ans=min(ans,bit[r]);
			r-=r&-r;
		}else{
			ans=min(ans,a[x]);
			r--;
		}
	}
	return ans;
}
void solve(){
	cin>>q;
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op){
			int u,v;cin>>u>>v;
			cout<<getmin(u,v)<<endl;
		}else{
			int x,val;cin>>x>>val;
			a[x]=val;
			memset(bit,0x3f,sizeof(bit));
			for(int i=1;i<=n;i++){
				build(i,a[i]);
			}
		}
	}

}
int main(){
	faster
	nhap();
	solve();
	




	return 0;
}

