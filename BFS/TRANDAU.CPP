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
vector<int>ke[251];
set<int>se;
int n,m;
bool vs[251][251],edge[251][251];
int numarea[63001];
int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=m;j++){
			cin>>edge[i][j];
			vs[i][j]=0;
		}
	}
	for(int i=1;i<=2;i++){
		int tg;cin>>tg;
	}
	memset(numarea,0,sizeof(numarea));
}
bool check(int x1,int y1){
	return (x1>=1&&y1>=1&&x1<=n&&y1<=m&&!vs[x1][y1]&&edge[x1][y1]);
}
int bfs(int x1,int y1){
	int total=1;
	vs[x1][y1]=1;
	queue<pii>q;
	q.push({x1,y1});
	while(!q.empty()){
		pii top=q.front();
		q.pop();
		for(int k=0;k<4;k++){
			int hoanh=top.fi+dx[k];
			int tung=top.sc+dy[k];
			if(check(hoanh,tung)){
				vs[hoanh][tung]=1;
				q.push({hoanh,tung});
				total++;
			} 
		}
	}
	return total;

	
}
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(edge[i][j]){
				if(!vs[i][j]){
					int result=bfs(i,j);
					numarea[result]++;
					se.insert(result);
				}
			}
		}
	}
	for(auto it=se.begin();it!=se.end();it++){
		cout<<*it<<" "<<numarea[*it]<<endl;
	}

}
int main(){
	faster
	nhap();
	// cout<<endl;
	solve();
	// for(int i=1;i<=n;i++){
	// 	for(int x:ke[i]) cout<<x<<" ";
	// 	cout<<endl;
	// }
	




	return 0;
}
