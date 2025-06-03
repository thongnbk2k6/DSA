#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
ll n,m,b,a[maxn];
void nhap(){
	cin>>n>>m>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
}
int rmax=2,ans1=1,r;
void best(int l){

	r=l+1;
	int t=a[r]-a[l];
	
	while(t<=b&&r<n){
		if((t+a[r+1]-a[l+1])>b) return ;
		else{
			ans1++;
			r++;
			l++;
			t=t+a[r]-a[l];

		}
	}
	
}
void xuly(){
	int ans=1,l=1;
	for(int i=1;i<n;i++){
		best(i);
		if(ans1>ans){
			ans=ans1;
			rmax=r;
			l=i;

		}
		ans1=1;
	}
	cout<<l<<" "<<rmax;
}
main(){
//	freopen("fields.inp","r",stdin);
//	freopen("fields.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int sub;cin>>sub;
	nhap();
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
	xuly();
}

