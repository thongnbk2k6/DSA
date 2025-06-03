#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
ll n,k;
int sub;
priority_queue<pair<int,int>,vector<pair<int,int>>>q;
void nhap(){
	cin>>sub>>n>>k;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		q.push({x,y});
	}
}
void xuly(){
	int k1=k;
	float s=0;
	while(k1>1){
		pair<int,int>top=q.top();q.pop();
		s+=top.first/2.0;
		k1--;
	}
	pair<int,int>x=q.top();q.pop();
	s=s+x.first/2.0;
	while(q.empty()){
		pair<int,int>top=q.top();q.pop();
		s+=top.first*1.0;
	}
	cout<<s<<endl;
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	while(!q.empty()){
		pair<int,int>top=q.top();q.pop();
		cout<<top.first<<" ";
	}
	
}

