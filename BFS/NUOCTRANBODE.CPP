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
int n,m,a[101][101],caonhat,thapnhat,bienmin,tc=0;
bool vs[101][101],bien[101][101],vs1[101][101],vs2[101][101];
int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};
void nhap(){
	caonhat=INT_MIN;
	thapnhat=0;
	bienmin=INT_MAX;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			caonhat=max(caonhat,a[i][j]);
			vs1[i][j]=0;
			vs2[i][j]=0;
			if((i==1||i==n||j==1||j==m)&&a[i][j]) {
				// cout<<i<<" "<<j<<endl;
				bien[i][j]=1;
				bienmin=min(a[i][j],bienmin);
			}
			else bien[i][j]=0;
			// if(a[i][j]!=0) thapnhat=min(thapnhat,a[i][j]);
		}
	}

}
bool checksea(int x1,int y1){
	return (!a[x1][y1]&&(x1==1||x1==n||y1==1||y1==m));
}
bool kt1(int x1,int y1){
	return (x1>=1&&y1>=1&&x1<=n&&y1<=m&&!vs1[x1][y1]&&!a[x1][y1]);
}
bool bfs1(int x1,int y1){
	
	if(checksea(x1,y1)) return 1;
	vs1[x1][y1]=1;
	queue<pii>q;
	q.push({x1,y1});
	while(!q.empty()){
		pii top=q.front();q.pop();
		for(int k=0;k<4;k++){
			int hoanh=top.fi+dx[k];
			int tung=top.sc+dy[k];
			if(kt1(hoanh,tung)){
				if(checksea(hoanh,tung)) return 1;
				vs1[hoanh][tung]=1;
				q.push({hoanh,tung});
			}
		}
	}
	return 0;
}
bool kt2(int x1,int y1){
	return (x1>=1&&y1>=1&&x1<=n&&y1<=m&&!vs2[x1][y1]&&!a[x1][y1]);

}
bool ktbien(int x1,int y1){
	return (x1>=1&&y1>=1&&x1<=n&&y1<=m&&a[x1][y1]>0&&!vs2[x1][y1]);
}
void bfs2(int x1,int y1){
	vs2[x1][y1]=1;
	queue<pii>q;
	q.push({x1,y1});
	while(!q.empty()){
		pii top=q.front();q.pop();
		for(int k=0;k<4;k++){
			int hoanh=top.fi+dx[k];
			int tung=top.sc+dy[k];
			if(kt2(hoanh,tung)){
				vs2[hoanh][tung]=1;
				q.push({hoanh,tung});

			}
			if(ktbien(hoanh,tung)) {
				// cout<<hoanh<<" "<<tung<<endl;
				bien[hoanh][tung]=1;
				bienmin=min(bienmin,a[hoanh][tung]);
			}
		}
	}

}
void khoitao(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!a[i][j]&&!vs2[i][j]){
				bool b=bfs1(i,j);
				if(b){
					bfs2(i,j);
				}
			}
		}
	}

}
bool kt3(int x1,int y1,int k){
	return (x1>=1&&y1>=1&&x1<=n&&y1<=m&&!vs[x1][y1]&&a[x1][y1]-k>0);
}
void bfs3(int x1,int y1,int k){
	vs[x1][y1]=1;
	queue<pii>q;
	q.push({x1,y1});
	while(!q.empty()){
		pii top=q.front();q.pop();
		for(int i=0;i<4;i++){
			int hoanh=top.fi+dx[i];
			int tung=top.sc+dy[i];
			if(kt3(hoanh,tung,k)){
				vs[hoanh][tung]=1;
				q.push({hoanh,tung});
			}
		}
	}


}
bool check(int k){
	memset(vs,0,sizeof(vs));
	if(k<bienmin) return 0;
	int count=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]-k>0&&!vs[i][j]){
				// cout<<i<<" "<<j<<" "<<k<<endl;
				count++;
				if(count>1) return 1;
				bfs3(i,j,k);
			}
		}
	}
	return 0;



}
void solve(){
	int lo=thapnhat,hi=caonhat;
	while(lo<hi){
		int mid=lo+(hi-lo)/2;
		// cout<<mid<<endl;
		if(check(mid)) {
			// cout<<mid<<endl;
			hi=mid;
		}
		else lo=mid+1;
		// cout<<mid<<endl;
	}
	if(lo==caonhat) cout<<"Case "<<tc<<": Island never splits."<<endl;
	else cout<<"Case "<<tc<<": Island splits when ocean rises "<<lo<<" feet."<<endl;

}
int main(){
	faster
	while(cin>>n>>m){
		tc++;
		if(n==m&&n==0) return 0;
		nhap();
		khoitao();
		solve();
		// cout<<caonhat<<" "<<thapnhat;
		// cout<<bienmin;
		// for(int i=1;i<=n;i++){
		// 	for(int j=1;j<=m;j++){
		// 		cout<<bien[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<n<<" "<<m<<endl;
		// cout<<thapnhat<<" "<<caonhat<<endl;
	}
	




	return 0;
}
