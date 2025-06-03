#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int n,m,isEnd[maxn*4],dem,child[maxn*4][26];

void Add(string &s){
	int u=0;
	
	for(int i=0;i<s.length();i++){
		int k=s[i]-'a';
		if(!child[u][k]) child[u][k]=dem++;
		u=child[u][k];
		
	}
	isEnd[u]=1;
	
}
bool check(string &s){
	int u=0;
	for(int i=0;i<s.length();i++){
		int k=s[i]-'a';
		if(!child[u][k]) return 0;
		u=child[u][k];
	}
	return isEnd[u];
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	dem=0;
	memset(child,0,sizeof(child));
	cin.ignore();
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		Add(s);
	}
	cin>>m;
	cin.ignore();
	for(int i=1;i<=m;i++){
		string s;cin>>s;
		cout<<check(s)<<endl;
	}
}

