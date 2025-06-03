#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
int n,l,r,giatri[maxn];
vector<string>v;
bool cmp(string a,string b){
	return a+b>b+a;
}
void xuly(){
	cin>>n>>l>>r;
	cin.ignore();
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		v.push_back(s);
	}
	sort(v.begin(),v.end(),cmp);
	string f[r+1];
	f[0]="";
	
	for(int i=1;i<=n;i++){
		//do dai
		for(int j=r;j>=v[i-1].size();j--){
			f[j]=max(f[j],f[j-v[i-1].size()]+v[i-1]);
		}
	}
	if(f[r].size()>=l&&f[r].size()<=r) cout<<f[r]<<endl;
	else cout<<-1;
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	xuly();
}

