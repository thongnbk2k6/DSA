#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int n;
vector<int>ke[101];
void nhap(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		ke[u].push_back(v);
		ke[v].push_back(u);
	}
}
int xuly(){
	int ans=0;
	for(int i=1;i<=n;i++){
		int t=ke[i].size();
		ans=max(ans,t);
	}
	return ans;
}
main(){
	freopen("cc.inp","r",stdin);
	freopen("cc.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	cout<<xuly()<<endl;
}

