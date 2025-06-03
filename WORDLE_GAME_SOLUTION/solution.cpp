#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define bit(n,i) ((n>>i)&1)
#define fi first
#define sc second
#define pdb pair<double,double>
#define db double
#define endl '\n'

const long long maxn=1e6+5;
const long long minn=-1e6;
const long long inf=1e18;

vector<string>words[26];
int main(){
	faster
	freopen("text.inp","r",stdin);
	string s;
	while(cin>>s){
		int c=int(s[0])-97;
		words[c].pb(s);
	}
	cout<<"hi";

	return 0;
}
