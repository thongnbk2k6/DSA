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
int n,q,a[maxn],dp[maxn][22];
int getmin(int l,int r){
	int k=log2(r-l+1);
	return min(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][0]=a[i];
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			dp[i][j]=min(dp[i][j-1],dp[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		if(r+1<=n) r++;
		if(l+1<=n) l++;
		cout<<getmin(l,r)<<endl;
	}
//	int l,r;cin>>l>>r;
//	if(r+1<=n) r++;
//	if(l+1<=n) l++;
//	cout<<getmin(l,r);
//4 10
//2 10 1 100
//0 1
//0 2
//0 3
//0 4
//1 2
//1 3
//1 4
//2 3
//2 4
//3 4



	return 0;
}

