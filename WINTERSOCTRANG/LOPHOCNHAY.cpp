#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
const int inf=1e7;
int n,k,a[maxn],vs[maxn];
void xuly1(){
	ll ctn=0,cktn=0;
	
	priority_queue<int,vector<int>,greater<int>>tn;	
	priority_queue<int,vector<int>,greater<int>>ktn;
	//tinh cap trung nhau
	for(int i=1;i<n;i++){
		tn.push(a[i+1]-a[i]);
	}
	for(int i=1;i<=n;i+=2){
		ktn.push(a[i+1]-a[i]);
	}
	for(int i=1;i<=k;i++){
		ctn+=tn.top();tn.pop();
		cktn+=ktn.top();ktn.pop();
	}
	cout<<min(ctn,cktn);
}
void xuly2(){
	int ctn=0,cktn1=0,cktn2=0;
	priority_queue<int,vector<int>,greater<int>>tn;
	priority_queue<int,vector<int>,greater<int>>ktn1;
	priority_queue<int,vector<int>,greater<int>>ktn2;
	for(int i=1;i<n;i++){
		tn.push(a[i+1]-a[i]);
	}
	for(int i=1;i<=n;i+=2){
		ktn1.push(a[i+1]-a[i]);
	}
	for(int i=n;i>=1;i-=2){
		ktn2.push(a[i]-a[i-1]);
	}
	for(int i=1;i<=k;i++){
		ctn+=tn.top();tn.pop();
		cktn1+=ktn1.top();ktn1.pop();
		cktn2+=ktn2.top();ktn2.pop();
	}
	cout<<min({ctn,cktn2,cktn2});
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+n+1);
	if(n%2==0){
		xuly1();
	}
	if(n%2!=0){
		xuly2();
	}
}

