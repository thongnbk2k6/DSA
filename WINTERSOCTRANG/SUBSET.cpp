#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
const int inf=1e7;
ll a[maxn],n,l,r,sum[maxn];
int x[maxn];
bool ok=0;
void tinh(){
	vector<int>vt;
	ll s=0;
	for(int i=1;i<=n;i++){
		if(x[i]){
			vt.push_back(i);
			s+=a[i];
		}
	}
	if(s>=l&&s<=r) {
		ok=1;
		cout<<vt.size()<<endl;
		for(int it:vt) cout<<it<<" ";
	}
}
void Try(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n){
			tinh();
			if(ok) return;
		}else Try(i+1);
	}
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>l>>r;
	map<ll,int>mp;
	bool ok4=1,ok5=1,ok6=1;
	sum[0]=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]=i;
		sum[i]=sum[i-1]+a[i];
		a[0]=a[i];
		if(a[i]!=i) ok5=0;
		if(a[i]!=a[i-1]) ok4=0;
	}
	//sub1
	if(n<=40&&!ok4&&!ok5){
		Try(1);
	}
	//sub4
	if(ok4){
		for(int k=1;k<=n;k++){
			if(sum[k]>=l&&sum[k]<=r){
				cout<<k<<endl;
				for(int i=1;i<=k;i++){
					cout<<i<<" ";
				}
				return 0;
			}
		}
	}
	if(ok5){
		
//		cout<<"yes"<<endl;
		ll s=n*(n+1)/2;
		ll s1;
		stack<ll>st;
		for(int i=n;i>=1;i--){
			if(s-i>=l){
				s-=i;
				st.push(i);
			}
			if(s>=l&&s<=r){
				s1=s;
			}
		}
		cout<<s1<<endl;
		for(int i=1;i<=st.top();i++) cout<<i<<" ";
		st.pop();
		while(!st.empty()){
			cout<<st.top()<<" ";
			st.pop();
		}
		
	}
	if(n>80&&!ok4&&!ok5){
		ll sum2[n+1],ans=0;
		sum2[0]=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			sum2[i]=sum2[i-1]+a[i];
		}
		for(int k=1;k<=n;k++){
			 ans=sum[n]-sum[n-k]+sum[k];
			if(ans>=l&&ans<=r){
				cout<<k*2<<endl;
				for(int i=1;i<=k;i++){
					cout<<mp[a[i]]<<" ";
				}
				for(int j=n-k+1;j<=n;j++){
					cout<<mp[a[j]]<<" ";
				}
			}
			
		}
	}
	
}

