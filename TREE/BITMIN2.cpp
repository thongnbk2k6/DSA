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

int n,q,a[maxn],bit[maxn],f[1001][1001],g[1001][1001];
int getsum(int vt){
	int s=0;
	while(vt){
		s+=bit[vt];
		vt-=(vt&-vt);
	}
	return s;
	
}
int getsumdoan(int l,int r){
	return getsum(r)-getsum(l-1);
}
void update(int vt,int val){
	while(vt<=n){
		bit[vt]+=val;
		vt+=(vt&-vt);
	}
}
void updatedoan(int l,int r,int val){
	
}
int getmin(int l,int r){
	int k=log2(r-l+1);
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
int getmax(int l,int r){
	int k=log2(r-l+1);
	return max(g[l][k],g[r-(1<<k)+1][k]);
}
void nhap(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[i][0]=f[i][0]=a[i];
		update(i,a[i]);
		
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			g[i][j]=max(g[i][j-1],g[i+(1<<j-1)][j-1]);
			f[i][j]=min(f[i][j-1],g[i+(1<<j-1)][j-1]);
		}
	}
}
void solve(){
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		cout<<getsumdoan(l,r);
		
	}

}
int main(){
	faster
	nhap();
	solve();




	return 0;
}

