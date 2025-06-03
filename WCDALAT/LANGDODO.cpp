#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int k;
int a[maxn];
vector<int>t[1001];
void build(int id,int l,int r){
	if(l==r){
		int tg=a[l];
		t[id].push_back(tg);
		return;
	}
	int mid=(l+r)/2;
	int tg1=a[mid];
	t[id].push_back(tg1);
	build(id+1,l,mid-1);
	build(id+1,mid+1,r);
	
}
void in(){
	for(int i=1;i<=k;i++){
		for(int x:t[i]) cout<<x<<" ";
		cout<<endl;
	}
}
main(){
	freopen("obilazak.inp","r",stdin);
	freopen("obilazak.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>k;
	int n=pow(2,k);
	for(int i=0;i<n-1;i++){
		cin>>a[i];
	}
//	for(int x:v) cout<<x<<" ";
	build(1,0,n-2);
	in();
}

