#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define bit(n,i) ((n>>i)&1)
const int maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
int n,q,dp1[maxn][22],dp2[maxn][22],a[maxn];
int getmin(int l,int r){
	int k=log2(r-l+1);
	return min(dp1[l][k],dp1[r-(1<<k)+1][k]);
}
int getmax(int l,int r){
	int k=log2(r-l+1);
	return max(dp2[l][k],dp2[r-(1<<k)+1][k]);
}
main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp1[i][0]=a[i];
		dp2[i][0]=a[i];
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			dp1[i][j]=min(dp1[i][j-1],dp1[i+(1<<(j-1))][j-1]);
			dp2[i][j]=max(dp2[i][j-1],dp2[i+(1<<(j-1))][j-1]);
		}
	}
//	int q;cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		cout<<getmin(l,r)<<endl;
	}
}

