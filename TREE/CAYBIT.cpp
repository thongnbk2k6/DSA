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
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
int n,q,bit[maxn],a[maxn];
int get(int vt){
	int s=0;
	while(vt>0){
		s+=bit[vt];
		vt-=(vt&-vt);
	}
	return s;
}
void update(int vt,int val){
	
	while(vt<=n){
		bit[vt]+=val;
		vt+=(vt&-vt);
	}
}
void updatedoan(int l,int r,int val){
	update(l,val);
	update(r+1,-val);
}
int main(){
	faster
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(i,a[i]);
	}
	for(int i=1;i<=n;i++){
		cout<<bit[i]<<" ";
	}
	cout<<endl;
	cin>>q;
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op==1){
			int vt;cin>>vt;
			cout<<get(vt)<<endl;
		}
		if(op==2){
			int v,vt;cin>>vt>>v;
			update(vt,v-a[vt]);
			a[vt]=v;
			for(int i=1;i<=n;i++){
				cout<<bit[i]<<" ";
			}
			cout<<endl;
		}
		if(op==3){
			int l,r,val;cin>>l>>r>>val;
			updatedoan(l,r,val);
			for(int i=1;i<=n;i++){
				cout<<bit[i]<<" ";
				
			}
			cout<<endl;
		}
	}





	return 0;
}

