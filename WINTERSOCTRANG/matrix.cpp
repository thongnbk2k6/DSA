#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
const long long MOD=1e9+7;
ll m,n,gt[maxn];
void giaithua(){
	gt[0]=1;
	gt[1]=1;
	for(int i=2;i<=maxn;i++){
		gt[i]=gt[i-1]*i%MOD;
	}	
}
ll luythua(int a,int b){
	ll res=1;
	while(b){
		if(b%2!=0){
			res*=a;
			res%=MOD;
		}
		b/=2;
		a*=a;
	}
	return res;
}
main(){
//	freopen("matrix.inp","r",stdin);
//	freopen("matrix.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	giaithua();
	cin>>n>>m;
	if(n>m) swap(n,m);
	int dc=abs(n-m)+1;
	int ans=1;
	for(int i=2;i<n;i++){
		ans*=luythua(gt[i],2);
		ans%=MOD;
	}
	ans*=luythua(gt[n],dc);
	cout<<ans;
	
	
}

