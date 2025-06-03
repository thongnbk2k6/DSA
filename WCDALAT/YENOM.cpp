#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;

int a[maxn+1], dp[maxn+1];
main(){
//	freopen("
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n,T;cin>>n>>T;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		memset(dp,0,sizeof(dp));
	}
//	for(int i=0;i<=n;i++) dp[i][0]=1;
//	for(int j=0;j<=T;j++) dp[0][j]=0;

	//goi dp[i] : 0/1 -> co the nhan duoc hay ko
	dp[0] = 1;
	
//	1, 2, 4
//	7 -> 6 + 1
//	7 -> 5 + 2
//	7 -> 3 + 4
	
	for(int i=1;i<=T;i++){
		for(int j=1;j<=n;j++){
			if(i >= a[j] && dp[i - a[j]] == 1) dp[i] = 1;
		}
	}
	
	int ans = 0;
	for(int i=0;i<=T;i++) ans += dp[i];
	cout << ans;
}

