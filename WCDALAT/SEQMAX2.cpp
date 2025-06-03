#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e60;
int n,k,a[maxn],s[maxn];
void nhap(){
	s[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		s[i]=s[i-1]+a[i];
	}
}
bool kt(float mid){
	
	
}
void xuly(){
	float l=*min_element(a+1,a+n+1),r=*max_element(a+1,a+n+1),kq=0.0;
	while(r-l>0.00001){
		float mid=1.0*(l+r)/2;
		if(kt(mid)){
			l=mid;
		}else mid=r;
	}
	cout<<fixed<<setprecision(5)<<l;
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	xuly();
}

