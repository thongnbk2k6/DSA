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
int n,m,ga=0,cao=0;
bool vs[1001][1001];
char c[1001][1001];
int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
			vs[i][j]=0;
		}
	}
}
bool check(int x1,int y1){
	return (x1>=1&&y1>=1&&x1<=n&&y1<=m&&!vs[x1][y1]&&c[x1][y1]!='#');
}
void bfs(int i,int j){
	vs[i][j]=1;
	int ch=0,f=0;
	if(c[i][j]=='c') ch++;
	if(c[i][j]=='f') f++;
	queue<pii>q;
	q.push({i,j});
	while(!q.empty()){
		pii top=q.front();q.pop();
		for(int k=0;k<4;k++){
			int x1=top.fi+dx[k];
			int y1=top.sc+dy[k];
			if(check(x1,y1)){
				vs[x1][y1]=1;
				q.push({x1,y1});
				if(c[x1][y1]=='c') ch++;
				if(c[x1][y1]=='f') f++;
			}
		}
	}
	if(f>=ch){
		cao+=f;
	}else{
		ga+=ch;
	}
}
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((c[i][j]=='.'||c[i][j]=='c'||c[i][j]=='f')&&!vs[i][j]){
				bfs(i,j);
			}
		}
	}
	cout<<cao<<" "<<ga;

}
int main(){
	faster
	nhap();
	solve();

	return 0;
}
