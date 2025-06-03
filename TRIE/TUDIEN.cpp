#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define piii int,pair<int,int>
#define bit(n,i) ((n>>i)&1)
#define fi first
#define sc second
#define pdb pair<double,double>
#define db double

const long long maxn=1e6;
const long long minn=-1e6;
const long long MOD=1e9+7;
const long long inf=1e18;
//vector<string>vec;
map<string,int>mp;
int n,p;
void solve(){
	cin>>n;
	cin.ignore();
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		mp[s]=1;
	}
	cin>>p;
	cin.ignore();
	int cnt=0;
	for(int i=1;i<=p;i++){
		string s;cin>>s;
		if(mp[s]==1) cnt++;
	}
	cout<<cnt;
}

int main(){
	freopen("TUDIEN.INP","r",stdin);
	freopen("TUDIEN.OUT","w",stdout);
	faster
	solve();




	return 0;
}

