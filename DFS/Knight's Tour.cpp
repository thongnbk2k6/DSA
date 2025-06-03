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
int x,y,vs[9][9],arr[9][9];
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};
struct tri{
	int s,i,j;
};
bool cmp(tri a,tri b){
	return a.s<b.s;
}
void nhap(){
	cin>>x>>y;
	memset(vs,0,sizeof vs);
	swap(x,y);
	
}
void print_ans(){
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool check(int i,int j){
	return (i>=1&&j>=1&&vs[i][j]==0&&i<=8&&j<=8);
}
int num_moves(int i,int j){
	int dem=0;
	for(int k=0;k<8;k++){
		int i1=i+dx[k];
		int j1=j+dy[k];
		if(check(i1,j1)) dem++;
	}
	return dem;
}
void dfs(int i,int j,int cnt=1){
	vs[i][j]=1;
	arr[i][j]=cnt;
	if(cnt==64) {
		print_ans();
		exit(0);
	}
	vector<tri>potential_move;
	for(int k=0;k<8;k++){
		int i1=i+dx[k];
		int j1=j+dy[k];
		if(check(i1,j1)){
			potential_move.push_back({num_moves(i1,j1),i1,j1});
		}
	}
	sort(all(potential_move),cmp);
	for(tri tmp:potential_move){
		int i1=tmp.i;
		int j1=tmp.j;
		dfs(i1,j1,cnt+1);
	}
	vs[i][j]=0;


	
}
void solve(){
	dfs(x,y);

}
int main(){
	faster
	nhap();	
	solve();
	



	return 0;
}
