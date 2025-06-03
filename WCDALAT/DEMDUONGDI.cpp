#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int n,p,vs[maxn];
vector<ll>ke[100001];
void nhap(){
	cin>>n>>p;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		ke[u].push_back(v);
		ke[v].push_back(u);
	}
	memset(vs,0,sizeof(vs));
}
queue<int>q;

bool bfs(int s,int t){
	int dem=0;
	q.push(s);vs[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		dem++;
		for(int v:ke[u]){
			if(!vs[v]){
				vs[v]=1;
				if(v==t) {
					if(dem%p==0) return 1;
					else return 0;
				}
				q.push(v);
			}
		}
	}
	
}
void xuly(){
	for(int i=1;i<=n;i++){
		int dem=0;
		for(int j=i+1;j<=n;j++){
			if(bfs(i,j)) dem++;
			memset(vs,0,sizeof(vs));
			while(!q.empty()) q.pop();
		}
		cout<<dem<<" ";
	}
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	xuly();
	
}

