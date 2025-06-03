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

const long long maxn=1e6+5;
const long long minn=-1e6;
const long long MOD=1e9+7;
const long long inf=1e18;
int n,a[6][6],b[6][6],tmp[6][6];
int x1,x2;
bool vs[6][6];
int dx[4]={0,-1,1,0};
int dy[4]={-1,0,0,1};
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
			if(b[i][j]==n*n){
				x1=i;
				x2=j;
			}
			tmp[i][j]=b[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=(i-1)*n+j;
		}
	}
	memset(vs,0,sizeof(vs));
}
vector<pii>path;
bool kt(int i,int j){
	return (i>=1&&i<=n&&j>=1&&j<=n&&!vs[i][j]);
}
bool ktmang(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(tmp[i][j]!=a[i][j]) return 0;
		}
	}
	return 1;
}
void dfs(int i,int j){
	vs[i][j]=1;
	path.pb({i,j});
	if(i==n&&j==n){
//		cout<<i<<" "<<j<<endl;
		if(ktmang()){
			cout<<path.size()-1<<endl;
			for(int i=0;i<path.size()-1;i++){
				cout<<path[i].fi<<" "<<path[i].sc<<" "<<path[i+1].fi<<" "<<path[i+1].sc<<endl;
			}
			return;
		}
	}else{
		for(int k=0;k<4;k++){
			int i1=i+dx[k];
			int j1=j+dy[k];
			if(kt(i1,j1)){
				swap(tmp[i][j],tmp[i1][j1]);
				dfs(i1,j1);
				swap(tmp[i][j],tmp[i1][j1]);
			}
		}
	}
	vs[i][j]=0;
	path.pop_back();
}
int main(){
	freopen("CTAB.INP","r",stdin);
	freopen("CTAB.OUT","w",stdout);
	faster
	nhap();
	dfs(x1,x2);





	return 0;
}

