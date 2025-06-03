#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define ii pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int n,q;
int a[maxn],b[maxn],c[maxn];
map<int,int>posa;
map<int,int>posb;
void nhap(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		posa[a[i]]=i;
	}
	for(int i=1;i<=n;i++) {
		cin>>b[i];
		posb[b[i]]=i;
	}
	memset(c,0,sizeof(c));
}
void xuly(){
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		swap(b[x],b[y]);
		for(int j=1;j<=n;j++){
			c[(posa[a[j]]-posb[b[j]]+n)%n]++;
//			cout<<(posa[j]-posb[j]+n)%n<<" ";
		}
		cout<<*max_element(c,c+n)<<endl;
		memset(c,0,sizeof(c));
	}
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	xuly();
}

