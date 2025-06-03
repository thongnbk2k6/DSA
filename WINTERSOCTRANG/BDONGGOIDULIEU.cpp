#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int n,x,a[maxn],ans=0;
priority_queue<int,vector<int>,greater<int>>q1;
priority_queue<int>q2;
void nhap(){
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		int t;cin>>t;
		q1.push(t);
		q2.push(t);
	}
}
void xuly(){
	if(n%2==0){
		while(q2.size()>=n/2){
			int x1=q1.top();
			int x2=q2.top();
			if(x1+x2<=x){
				ans++;
				q1.pop();
				q2.pop();
			}else{
				ans++;
				q2.pop();
			}
			
		}
	}else{
		while(q2.size()>=n/2+1){
//			cout<<q2.size()<<endl;
			int x1=q1.top();
			int x2=q2.top();
			if(x1+x2<=x){
				ans++;
				q1.pop();
				q2.pop();
				ans++;
				q2.pop();
			}
			
		}
	}

}
main(){
	freopen("data.inp","r",stdin);
	freopen("data.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	xuly();
	cout<<ans;
//	cout<<q2.size();
//	while(!q1.empty()){
//		cout<<q1.top()<<" "<<q2.top()<<endl;
//		q1.pop();q2.pop();
//	}
}

