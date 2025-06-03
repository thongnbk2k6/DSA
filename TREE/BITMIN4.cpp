#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define piii int,pair<int,int>
#define bit(n,i) ((n>>i)&1)
#define fi first
#define sc second
#define pdb pair<double,double>
#define db double

const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
int n,q,a[maxn],t[maxn];
void build_tree(int vt,int val){
	t[vt]=min(t[vt],val);
	int pre=vt+(vt&-vt);
	while(pre<=n){
		t[pre]=min(t[pre],val);
		pre+=(pre&-pre);
	}
}
void update(int vt,int val){
	t[vt]=val;
	int l=vt-(vt&-vt)+1;
	int x=vt-1;
	while(x>=l){
		t[vt]=min(a[vt],t[x]);
		x-=(x&-x);
	}
	int parent=vt+(vt&-vt);
	update(parent,val);
}
int getmin(int l,int r){
	int res=inf;
	int x;
	while(l<=r){
		x=r-(r&-r)+1;
		if(l<=x){
			res=min(res,t[r]);
			r-=(r&-r);
		}else{
			res=min(res,t[r]);
			r-=1;
		}
	}
	return res;
}
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=inf;
	}
	for(int i=1;i<=n;i++){
		build_tree(i,a[i]);
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op){
			int l,r;cin>>l>>r;
			cout<<getmin(l,r)<<endl;
		}else{
			int x,val;cin>>x>>val;
			a[x]=val;
			update(x,val);
		}
	}

	
	
}

int main(){
	faster
	nhap();
	
	




	return 0;
}

