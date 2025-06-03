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
const int NUMNODES=27;
int n,m;
struct Trie{
	struct node{
		int child[26];
		int exist,cnt;
	}nodes[NUMNODES];
	int cur;
	Trie() : cur(0){
		memset(nodes[0].child,-1,sizeof(nodes[cur].child));
		nodes[0].exist=nodes[0].cnt=0;
	};
	int new_node(){
		cur++;
		memset(nodes[cur].child,-1,sizeof(nodes[cur].child));
		nodes[cur].exist=nodes[cur].cnt=0;
		return cur;
	}
	void add(string s){
		int pos=0;
		for(int i=0;i<s.length();i++){
			int c=s[i]-'a';
			if(nodes[pos].child[c]==-1){
				nodes[pos].child[c]=new_node();
			}
			pos=nodes[pos].child[c];
			nodes[pos].cnt++;
		}
		nodes[pos].exist++;
	}
	bool xoaxau1(int pos,string &s,int i){
		if(i!=s.length()){
			int c=s[i]-'a';
			bool deleted=xoaxau1(nodes[pos].child[c],s,i+1);
			if(deleted) nodes[pos].child[c]=-1;
		}else{
			nodes[pos].exist--;
		}
		if(pos!=0){
			nodes[pos].cnt--;
			if(nodes[pos].cnt==0) return 1;
		}
		return 0;
	}
	void xoaxau(string s){
		if(!kt(s)) return;
		xoaxau1(0,s,0);
	}
	bool kt(string s){
		int pos=0;
		for(int i=0;i<s.length();i++){
			int c=s[i]-'a';
			if(nodes[pos].child[c]==-1) return 0;
			pos=nodes[pos].child[c];
		}
		return nodes[pos].exist!=0;
	}
}caytrie;
void nhap(){
	
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		caytrie.add(s);
	}
	int cnt=0;
	cin>>m;
	for(int i=1;i<=m;i++){
		string s;cin>>s;
		if(caytrie.kt(s)) cnt++;
	}	
	cout<<cnt;

}
int main(){
	faster
	solve();




	return 0;
}

