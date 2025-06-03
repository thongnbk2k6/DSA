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
int n,m;
struct node{
	node* child[26];
	bool isEnd;
	node(){
		memset(child,NULL,sizeof(child));
		isEnd=0;
	}
};
node *root =new node();
void ADD(string &s){
	node *u=root;
	for(int i=0;i<s.length();i++){
		int k=s[i]-'a';
		if(u->child[k]==NULL) u->child[k]=new node();
		u=u->child[k];
	}
	u->isEnd=1;
}
bool kt(string &s){
	node *u=root;
	for(int i=0;i<s.length();i++){
		int k=s[i]-'a';
		if(u->child[k]==NULL) return 0;
		u=u->child[k];
	}
	return u->isEnd;
}
void nhap(){
	
}
void solve(){
	cin>>n;
	cin.ignore();
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		ADD(s);
	}
	cin>>m;
	cin.ignore();
	int cnt=0;
	for(int i=1;i<=m;i++){
		string s;cin>>s;
		if(kt(s)) cnt++;
	}
	cout<<cnt;

}
int main(){
	faster
	solve();




	return 0;
}

