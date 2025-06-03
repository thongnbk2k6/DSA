#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int n;
int Lcm(int x,int y){
	return x*y/(__gcd(x,y));
}
void xuly(){
	if(n==1){
		cout<<1;
		return;
	}
	if(n==2){
		cout<<2;
		return;
	}
	if(n&1){
		cout<<Lcm(Lcm(n,n-1),n-2);
	}else{
		if(__gcd(n,n-3)==1){
			cout<<Lcm(Lcm(n,n-1),n-3);
		}else{
			cout<<Lcm(Lcm(n-1,n-2),n-3);
		}
	}
}
//int ans=0;
//void xuly2(){
//	for(int i=n-100;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			for(int k=j+1;k<=n;k++){
//				ans=max(ans,Lcm(Lcm(i,j),k));
//			}
//		}
//	}
//}
main(){
	freopen("lcm.inp","r",stdin);
	freopen("lcm.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	xuly();
//	cout<<ans;
}

