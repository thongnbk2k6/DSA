#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int sub;
ll n,m,b,a[maxn],s[maxn];
long long Sum(int l,int r){
	return s[r]-s[l-1];
}
bool kt(int mid){
	for(int i=1;i+mid-1<=n;i++){
		int l=i;
		int r=i+mid-1;
		int m=(l+r)/2;
		ll SUM= (m-l+1)*a[m]-Sum(l,m)+Sum(m+1,r)-(r-m)*a[m];
		if(SUM<=b) return 1;
	}
	return 0;
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>sub>>n>>m>>b;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	s[0]=0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
//	for(int i=1;i<=n;i++) cout<<s[i]<<" ";
	int l=1,r=n,kq=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(kt(mid)){
			kq=mid;
			l=mid+1;
			//nguoc lai
		}
		else r=mid-1;
	}
	cout<<kq<<endl;
}

