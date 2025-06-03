#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;
int n,m,a[10001],t[40001],vs[40001];
//void build(int id,int l,int r){
//	if(l==r){
//		t[id]=a[l];
//		return;
//	}
//	int mid=(l+r)/2;
//	build(id*2,l,mid);
//	build(id*2+1,mid+1,r);
//	t[id]=min(t[id*2],t[id*2+1]);
//}
main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	build(1,1,n);
	int s=0;
	bool vs[n+1];
	memset(vs,0,sizeof(vs));
	for(int i=1;i<=n-m+1;i++){
		priority_queue<int,vector<int>,greater<int>>q;
		for(int j=i;j<=i+m-1;j++){
			q.push(a[j]);
		}
		for(int k=1;k<=2;k++){
			int x=q.top();q.pop();
			if(vs[x]) continue;
			else{
				vs[x]=1;
				s+=x;
			}
		}
	}
	cout<<s<<endl;
}

