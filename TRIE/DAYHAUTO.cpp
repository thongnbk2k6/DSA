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
int n;
vector<string>vec;
struct Trie{
	struct node{
		int child[26];//0->25 ki tu
		int exist,cnt;
	}nodes[27];
	int cur;
	Trie() :cur(0){
		memset(nodes[0].child,-1,sizeof(nodes[cur]));
		nodes[0].cnt=nodes[0].exist=0;
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
	cin>>n;
	cin.ignore();
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		caytrie.add(s);
		vec.pb(s);
	}
}
int tinh(string s){
	int res=0;
	for(int i=0;i<s.size();i++){
		string tmp="";
		int tg=0;
		for(int j=i;j<s.size();j++){
			tmp+=s[i];
			if(caytrie.kt(tmp)) tg+=tmp.size();
		}
		res=max(res,tg);
	}
	return res;
}
void solve(){
	int ans=0;
	for(int i=0;i<vec.size();i++){
		ans=max(ans,tinh(vec[i]));
	}
	cout<<ans;
	
	

}
int main(){
	freopen("DAYHAUTO.INP","r",stdin);
	freopen("DAYHAUTO.OUT","w",stdout);
	faster
	nhap();
	solve();




	return 0;
}

