#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int sub,n,m,a[1001][1001],vs[1001][1001];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
void nhap(){
	cin>>sub>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	memset(vs,0,sizeof(vs));
}
bool kt(int i,int j,int d){
	if(i<=m&&i>=1&&j<=n&&j>=1&&a[i][j]%d==0&&!vs[i][j]) return 1;
	else return 0;
}
queue<pair<int,int>>q;
int bfs(int i,int j,int d){
	int ans=0;
	vs[i][j]=1;
	q.push({i,j});
	while(!q.empty()){
		ans++;
		pair<int,int>p=q.front();q.pop();
		vs[p.first][p.second]=1;
		for(int k=0;k<4;k++){
			int i1=p.first+dx[k];
			int j1=p.second+dy[k];
			if(kt(i1,j1,d)){
				q.push({i1,j1});
			}
		}
	}
	return ans;
}
void xuly(){
	int ans=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			ans=max(ans,bfs(i,j,a[i][j]));
			memset(vs,0,sizeof(vs));
		}
	}
	cout<<ans<<endl;
}
main(){
	freopen("numtable.inp","r",stdin);
	freopen("numtable.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	xuly();
}
