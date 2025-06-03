#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;

main(){
//	freopen("easy.inp","r",stdin);
//	freopen("easy.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll k;cin>>k;
	cin.ignore();
	string s;
	while(cin>>s){
		if(s.length()>k){
			cout<<s[0]<<s.length()-2<<s[s.length()-1]<<" ";
		}else cout<<s<<" ";
	}
}

