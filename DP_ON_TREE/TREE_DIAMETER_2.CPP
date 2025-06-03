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

const long long maxn=2e5+5;
const long long minn=-1e6;
const long long inf=1e18;
int n,toLeaf[maxn],maxLength[maxn],ans;
vector<int>adj[maxn];
void preprocess(){
	memset(toLeaf,0,sizeof toLeaf);
	memset(maxLength,0,sizeof maxLength);//mang maxLength[v]: do dai duong di dai nhat ma trong do dinh v la goc cay con
	ans = 0;
}

void nhap(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
}
void dfs(int v,int parent){
	for(int u:adj[v]){
		if(u==parent) continue;
		dfs(u,v);
		toLeaf[v] = max(toLeaf[v],toLeaf[u]+1);
	}
	int child_toLeaf_longest = 0,longest_length = -1,child_toLeaf_second_longest=0,second_longest_length = -1;
	for(int u:adj[v]){
		if(u==parent) continue;
		if(toLeaf[u]>=longest_length){
			second_longest_length = longest_length;
			child_toLeaf_second_longest = child_toLeaf_longest;
			longest_length = toLeaf[u];
			child_toLeaf_longest = u;
			

		}else if(toLeaf[u]>=second_longest_length){
			second_longest_length = toLeaf[u];
			child_toLeaf_second_longest = u;
		}
	}
	if(child_toLeaf_longest==0&&child_toLeaf_second_longest==0){//neu dinh v khong co con nao
		maxLength[v] = 0;
	}else if(child_toLeaf_second_longest==0){//cay con v chi 1 canh xuong con cua no
		maxLength[v] = longest_length + 1; 
		/*
			
	        * 'v'
	    -> / <- cong them canh nay vao vi mang maxLength chi tinh do sau nhat cua con u chua tinh canh di tu v->u
          * 'u'
         / \ 


		*/
	}
	else{
		maxLength[v] = longest_length + second_longest_length + 2;//tinh nhu binh thuong
	}
	//cong them 2 canh tu v den 2 con
	ans = max(ans,maxLength[v]);
}
void solve(){
	dfs(1,-1);
	
	cout<<ans<<endl;

}
int main(){
	faster
	preprocess();
	nhap();
	solve();




	return 0;
}
