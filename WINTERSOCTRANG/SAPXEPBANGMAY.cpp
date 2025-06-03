#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
ll n,a[maxn],b[maxn];
map<int,int>mp;
map<int,int>cut;
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]=i;
		b[i]=a[i];
		cut[b[i]]=0;
	}
	sort(b+1,b+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<b[i]<<" "<<a[mp[b[i]]]<<endl;
//	}
//	cout<<endl;
}
void xuly(){
	int dem=0;
	for(int i=1;i<n;i++){
		if((b[i+1]==a[mp[b[i]]-1]||b[i+1]==a[mp[b[i]]+1])&&cut[b[i]]==0&&cut[b[i+1]]==0) {
			dem++;
			cut[b[i]]=1;
			cut[b[i+1]]=1;
		}
		else if(cut[b[i]]==0){
			dem++;
			cut[b[i]]=1;
		}
	
	}
	if(cut[mp[b[n]]]==0) dem++;
	cout<<dem;
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	xuly();
}

