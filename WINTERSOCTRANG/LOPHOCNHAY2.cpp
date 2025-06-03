#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e18;
int n,k;
ll dp[1001][1001],a[1001];
void nhap(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][0]=0;
	}
	dp[0][0]=0;
	sort(a+1,a+n+1);
}
void xuly(){
	for(int i=2;i<=n;i++){
		for(int j=1;j<=k;j++){
			ll ans=1e18;
			if(i>=2){
				ans=dp[i-2][j-1]+a[i]-a[i-1];
			}else if(i-1>=k*2){
				ans=min(ans,dp[i-1][j]);
			}
			dp[i][j]=ans;
		}
	}
	cout<<dp[n][k];
}

main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
//	cout<<tinh(n,m);
	xuly();
}

