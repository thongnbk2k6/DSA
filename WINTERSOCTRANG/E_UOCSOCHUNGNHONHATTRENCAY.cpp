#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int sub,n,a[maxn];
ll s=0;
vector<int>ke[6001];
vector<int>path;
bool vs[6001];
void nhap(){
	cin>>sub>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		ke[u].push_back(v);
		ke[v].push_back(u);
	}
	memset(vs,0,sizeof(vs));
	cout<<endl<<endl;
}
void dfs(int u,int v,int tg){
	tg=__gcd(tg,a[u]);
	cout<<u<<" "<<v<<" "<<tg<<endl;
	if(u==v) {
		s+=tg;
		return;
	}
	vs[u]=1;
	for(int x:ke[u]){
		if(!vs[x]) dfs(x,v,tg);
	}
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			dfs(i,j,a[i]);
			cout<<endl;
		}
		memset(vs,0,sizeof(vs));
		cout<<endl<<endl;
	}
	cout<<s;
//	dfs(1,5,a[1]);
//	cout<<endl<<s;
}

