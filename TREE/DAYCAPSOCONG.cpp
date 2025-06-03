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
#define endl '\n'
#define int long long
const long long maxn=1e6+5;
const long long minn=-1e6;
const long long MOD=1e9+7;
const long long inf=1e18;
int n,q;
ll a[maxn],rmqmi[22][maxn],rmqma[22][maxn],rmqsu[22][maxn];
void nhap(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		rmqmi[0][i]=rmqma[0][i]=rmqsu[0][i]=a[i];
	}
}
void khoitao(){
	for(int j=1;j<=20;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			rmqmi[j][i]=min(rmqmi[j-1][i],rmqmi[j-1][i+(1<<j-1)]);
			rmqma[j][i]=max(rmqma[j-1][i],rmqma[j-1][i+(1<<j-1)]);
			rmqsu[j][i]=rmqsu[j-1][i]+rmqsu[j-1][i+(1<<j-1)];
		}
	}
}
ll getsum(int l,int r){
	int len=r-l+1;
	ll sum=0;
	for(int j=0;(1<<j)<=len;j++){
		if(len>>j&1){
			sum+=rmqsu[j][l];
			l+=(1<<j);
		}
	}
	return sum;
}
ll getmin(int l,int r){
	int k=__lg(r-l+1);
	return min(rmqmi[k][l],rmqmi[k][r-(1<<k)+1]);
}
ll getmax(int l,int r){
	int k=__lg(r-l+1);
	return max(rmqma[k][l],rmqma[k][r-(1<<k)+1]);
}
bool check(int l,int r){
	int len=r-l+1;
	ll tong=getsum(l,r);
	ll tonhat=getmax(l,r);
	ll nhonhat=getmin(l,r);
	return tong*2==len*(tonhat+nhonhat);
}
void solve(){
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		if(check(l,r)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

}
 main(){
	faster
	nhap();
	khoitao();
	solve();



	return 0;
}

