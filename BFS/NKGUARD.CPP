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
int n,m,result=0;
int a[701][701];
bool vs[701][701],tohon[701][701],vs1[701][701];
int dx[8]={-1,0,0,1,-1,1,1,-1};
int dy[8]={0,-1,1,0,-1,-1,1,1};
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			vs[i][j]=0;
			vs1[i][j]=0;
			tohon[i][j]=0;
		}
	}
}
bool check(int x1,int y1){
	return (x1>=1&&y1>=1&&x1<=n&&y1<=m&&!vs[x1][y1]);
}

void bfs1(int i,int j){
	vs[i][j]=1;
	queue<pii>q;
	tohon[i][j]=0;
	q.push({i,j});
	while(!q.empty()){
		pii top=q.front();q.pop();
		for(int k=0;k<8;k++){
			int x1=top.fi+dx[k];
			int y1=top.sc+dy[k];
			if(check(x1,y1)){
				vs[x1][y1]=1;
				q.push({x1,y1});
				if(a[x1][y1]>a[top.fi][top.sc]) tohon[x1][y1]=1;	
			}
		}
	}
	bool ok=1;
	for(int k=0;k<8;k++){
		int x1=i+dx[k];
		int y1=j+dy[k];
		if(x1>=1&&y1>=1&&x1<=n&&y1<=m){
			if(a[x1][y1]>a[i][j]){
				ok=0;
				break;
			}
		}

	}
	if(ok) tohon[i][j]=1;
	
}
int dx1[4]={-1,0,0,1};
int dy1[4]={0,-1,1,0};
bool kt(int x1,int y1){
	return (x1>=1&&y1>=1&&x1<=n&&y1<=m&&!vs1[x1][y1]&&tohon[x1][y1]);
}
void bfs(int i,int j){
	vs1[i][j]=1;
	queue<pii>q;
	q.push({i,j});
	while(!q.empty()){
		pii top=q.front();q.pop();
		for(int k=0;k<4;k++){
			int x1=top.fi+dx1[k];
			int y1=top.sc+dy1[k];
			if(kt(x1,y1)){
				vs1[x1][y1]=1;
				q.push({x1,y1});
			}
		}
	}
}
void solve(){
	bfs1(1,1);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(tohon[i][j]&&!vs1[i][j]){
				ans++;
				bfs(i,j);
			}
		}
	}
	cout<<ans;

}
int main(){
	faster
	nhap();
	solve();
	




	return 0;
}
