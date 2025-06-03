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
const long long MOD=1e9+7;
const long long inf=1e18;
int n,k,r,t,bit[maxn];
bool a[maxn];
void nhap(){
	cin>>n>>k>>r>>t;
	memset(a,0,sizeof(a));
	for(int i=1;i<=k;i++){
		int x;cin>>x;
		a[x]=1;
	}
}
ll getsum(int vt){
	ll s=0;
	while(vt>0){
		s+=bit[vt];
		vt-=(vt&-vt);
	}
	return s;
}
void update(int vt,int val){
	while(vt<=n){
		bit[vt]+=val;
		vt+=vt&-vt;
	}
}
void build(){
	for(int i=1;i<=n;i++){
		update(i,a[i]);
	}
}
ll getsumdoan(int l,int r){
	return getsum(r)-getsum(l-1);
}
void solve(){
	ll cnt=0;
	vector<int>ans;
	for(int i=1;i<=n;i+=r){
		if(i+r-1>n) break;
		int dem=getsumdoan(i,i+r-1);
		if(dem>=t) continue;
		stack<int>st;
		if(dem<t){
			
		}
		
	}
	cout<<cnt<<endl;
	for(int x:ans) cout<<x<<" ";
}
int main(){
	faster
	nhap();
	build();
	solve();
	




	return 0;
}

