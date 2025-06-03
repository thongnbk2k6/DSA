#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int n,m,k,vs[1001][1001],a[1001][1001];


map<pair<int,int>,pair<int,int>>mp;
int  dx[2] = {0,1};
int  dy[2] = {1,0};
void nhap(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	memset(vs,0,sizeof(vs));
}
bool check(int i,int j){
	if(!vs[i][j]&&i<=n&&i>=1&&j<=m&&j>=1) return 1;
	else return 0;
}
void dfs(int i,int j){
	vs[i][j]=1;
	pair<int,int>x1={i,j};
	for(int k=0;k<2;k++){
		int i1=i+dx[k];
		int j1=j+dy[k];
		if(check(i1,j1)){
			pair<int,int>x2={i1,j1};
			mp[x2]=x1;
			dfs(i1,j1);
		}
	}
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	dfs(1,1);
	int best=0;
	pair<int,int>st={1,1};
	pair<int,int>ed={n,m};
	while(st!=ed){
		ed=mp[ed];
		best++;
	}
	cout<<best+1;
}

