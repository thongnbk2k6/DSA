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
bool a[101][101],vs[101][101];
int n,m;
int dx[8]={-1,0,0,1,-1,1,1,-1};
int dy[8]={0,1,-1,0,-1,-1,1,1};
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;cin>>c;
			if(c=='.') a[i][j]=0;
			else a[i][j]=1;
			vs[i][j]=0;
		}
	}
}
bool check(int x1,int y1){
	return (x1>=1&&y1>=1&&x1<=n&&y1<=m&&!vs[x1][y1]&&a[x1][y1]);
}
void bfs(int x1,int y1){
	vs[x1][y1]=1;
	queue<pii>q;
	q.push({x1,y1});
	while(!q.empty()){
		pii top=q.front();
		q.pop();
		for(int k=0;k<8;k++){
			int hoanh=top.fi+dx[k];
			int tung=top.sc+dy[k];
			if(check(hoanh,tung)){
				vs[hoanh][tung]=1;
				q.push({hoanh,tung});
			}
		}
	}
}
void solve(){
	int result=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]&&!vs[i][j]){
				bfs(i,j);
				// cout<<i<<" "<<j<<endl;
				result++;
			}
		}
	}
	cout<<result;

}
int main(){
	faster
	nhap();
	solve();
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }




	return 0;
}
