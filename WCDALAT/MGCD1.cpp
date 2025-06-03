#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;

main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	int a[n+1];
	bool b[maxn];
	map<int,int>mp;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			mp[a[i]]++;
		}
		b[a[i]]=1;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		if(a[i]==1) continue;
		for(int j=a[i]*2;j*j<=n;j+=a[i]){
			if(b[j]){
				ans*=a[i];
			}
		}
	}
	for(pair<int,int>x:mp){
		ans*=pow(x.first,x.second);
	}
//	ans%=1e9+7;
	cout<<ans;
	
	
}

