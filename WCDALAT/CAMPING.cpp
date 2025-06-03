#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;
int ans=0,n,m,k;
long long a[1001][1001];
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
void khoitao(){
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=1;
		}
	}
	for(int i=1;i<=k;i++){
		int x,y;cin>>x>>y;
		a[x][y]=0;
	}
}
void xuly(int x,int y){
//	cout<<x<<" "<<y<<endl;
	a[x][y]=0;
	ans++;
	for(int i=0;i<4;i++){
		int i1=x+dx[i];
		int j1=y+dy[i];
		if(i1>=1&&i1<=m&&j1>=1&&j1<=n&&a[i1][j1]==1){
			xuly(i1,j1);
		}
	}
}
main(){
	khoitao();
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	return 0;
	int dem=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]){
				dem++;
				xuly(i,j);
			}
		}
	}
	cout<<ans-dem<<endl;
	
}

