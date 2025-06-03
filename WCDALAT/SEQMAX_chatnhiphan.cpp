#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int n,k,a[maxn],s[maxn];
float kq1=0.0;
void nhap(){
	s[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
}
bool ok=0;
bool kt(int m){
	for(int i=m;i<=n;i++){
		if(i-m+1>=k&&s[i]-s[m-1]>kq1){
			kq1=s[i]-s[m-1];
			ok=1;
		}
	}
	return ok;
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	int l=1,r=n;
	float kq=0.0;
	while(l<=r){
		int mid=(l+r)/2;
		if(kt(mid)){
			l=mid+1;
			float tg=1.0*(s[r]-s[l-1])/k;
			kq=max(kq,tg);
			ok=0;
		}
		else r=mid-1;
	}
	cout<<kq;
}

