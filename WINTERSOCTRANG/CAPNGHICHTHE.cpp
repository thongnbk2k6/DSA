#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define  pb push_back
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
int tinh(vector<int>v){
	if(v.size()<=1) return 0;
	int mid=(v.size()-1)/2;
	vector<int>v1,v2;
	for(int i=0;i<=mid;i++){
		v1.pb(v[i]);
	}
//	for(int x:v1) cout<<x<<" ";
//	cout<<" _ ";
	for(int i=mid+1;i<v.size();i++){
		v2.pb(v[i]);
	}
//	for(int x:v2) cout<<x<<" ";
//	cout<<endl;
	int res=tinh(v1)+tinh(v2);
	int dem=0;
	for(int i=0;i<v1.size();i++){
		int j=0;
		while(j<v2.size()&&v1[i]>v2[j]){
//			cout<<v1[i]<<"lon hon"<<v2[j]<<" ";
			j++;
		}
		dem+=j;
	}
//	cout<<endl;
	return res+dem;
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	vector<int>v;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	cout<<tinh(v);
}

