#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
set<char>se;
int kt(string s){
	int ans=0;
	for(int i=1;i<=s.length();i++){
//		if(se.count(s[i])&&se.count(s[i-1])) continue;
		if(se.count(s[i])&&!se.count(s[i-1])) ans++;
	}
	if(s[s.length()-1]=='e') ans--;
	if(s[s.length()-1]=='e'&&s[s.length()-2]=='l'&&!se.count(s[s.length()-3])) ans++;
	
	if(ans<1) return 1;
	else return ans;
}
main(){
	freopen("syllable.inp","r",stdin);
	freopen("syllable.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	se.insert('a');
	se.insert('o');
	se.insert('e');
	se.insert('u');
	se.insert('i');
	string s;getline(cin,s);
	s='x'+s;
	cout<<kt(s)<<endl;
}

