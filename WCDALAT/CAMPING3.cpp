#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;

main(){
	freopen("camping.inp","r",stdin);
	freopen("camping.out","w",stdout);
	int m,n,k;cin>>m>>n>>k;
	long long a[m+1][n+1];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=1;
		}
	}
	while(k--){
		int x,y;cin>>x>>y;
		a[x][y]=0;
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<n;j++){
			if(a[i][j]&&a[i][j+1]) ans++;
		}
	}
	for(int i=1;i<m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]&&a[i+1][j]) ans++;
		}
	}
	cout<<ans<<endl;
}

