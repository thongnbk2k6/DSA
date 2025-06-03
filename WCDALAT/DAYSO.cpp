#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int n,a[maxn],t[maxn],b[maxn],ans=0;
void xuly(){
	for(int i=1;i<=n;i++){
		map<int,int>mp;
		int s=0;
		for(int j=i;j<=n;j++){
			
			s+=a[j];
			mp[a[j]]++;
			bool ok=1;
			for(pair<int,int>x:mp){
				if(x.second%2!=0) {
					ok=0;
					break;
				}
			}
			if(ok&&s>0) ans++;
		}
	}
	cout<<ans<<endl;
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	xuly();
	
}

