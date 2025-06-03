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
#define MASK(i) (1ll<<(i))

const long long maxn=3e5+5;
const long long minn=-1e6;
const long long inf=1e18;
const int LOG=19;
int n,a[maxn],minseg[maxn][LOG];
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) minseg[i][0]=a[i];
}
void preprocess(){
	for(int j=1;j<=LOG;j++){
		for(int i=1;i<=n-MASK(j)+1;i++){
			minseg[i][j]=min(minseg[i][j-1],minseg[i+MASK(j)][j-1]);
		}
	}
}
int getmin(int l,int r){
	int k=31- __builtin_clz(r-l+1);
	return min(minseg[l][k],minseg[r-MASK(k)+1][k]);
}
void solve(){
	int q;cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		cout<<getmin(l,r)<<endl;
	}

}
int main(){
	faster
	nhap();
	preprocess();
	solve();

	




	return 0;
}
