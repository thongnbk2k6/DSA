#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
const ll inf=1e9+7;
int n,m;
ll d[1001][1001],p[maxn],minprice=inf,vt;
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(minprice>p[i]){
			vt=i;
			minprice=p[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]=inf;
		}
	}
	
	
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		d[u][v]=w;
		d[v][u]=w;
	}
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				if(d[u][v]>d[u][k]+d[k][v]){
					d[u][v]=d[u][k]+d[k][v];
				}
			}
		}
	}
}
void xuly(){
	for(int i=1;i<=n;i++){
		if(p[i]==minprice) cout<<p[i]<<" ";
		else{
			ll minp=1e17;
			for(int j=1;j<=n;j++){
				minp=min({p[i],d[i][j]*2+p[j],minp});
			}
			cout<<minp<<" ";
		}
	}
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	floyd();
	xuly();
}

