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
int n,q,rmq[18][maxn];
void nhap(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>rmq[0][i];
	}
	for(int j=1;j<=17;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			rmq[j][i]=min(rmq[j-1][i],rmq[j-1][i+(1<<(j-1))]);
		}
	}
}
int getmin(int l,int r){
	int k=__lg(r-l+1);
	return min(rmq[k][l],rmq[k][r-(1<<k)+1]);
}
void solve(){
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		l++;
		r=min(r,n);
		cout<<getmin(l,r)<<endl;
	}
}
int main(){
	faster
	nhap();
	solve();
//	cout<<getmin(1,2);




	return 0;
}

