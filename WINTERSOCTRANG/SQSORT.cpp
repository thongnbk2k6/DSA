#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
const long long maxn=1e6;
const long long minn=-1e6;
const long long inf=1e9+7;
vector<int>data[45];
int n,k,s=0;

void nhap(){
	cin>>n>k;
	for(int i=1;i<=k;i++){
		int x;cin>>x;
		s+=x;
		data[45].push_back(x);
	}
}
int trungvi(vector<int>v){
	sort(v.begin(),v.end());
	return v[(v.size()-1)/2];
}
void tinh(int tong){
	stack<int>st;
	queue<int>q;
	
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
}

