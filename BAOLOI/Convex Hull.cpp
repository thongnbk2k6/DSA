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
const long long MOD=1e9+7;
const long long inf=1e18;
int n;
struct point{
	ll x,y;
};

//di theo chieu nguoc chieu kiem dong ho
bool ccw(const point &a,const point &b,const point &c){
	return (1ll*(b.x-a.x)*(c.y-a.y)-1ll*(c.x-a.x)*(b.y-a.y)>0);
}
vector<point>tinh(vector<point>p){
	sort(all(p),[](const point &a,const point &b){
		if(a.x!=b.x) return a.x<b.x;
		return a.y<b.y;
	});
	vector<point>ans;
	ans.pb(p[0]);
	//dung bao tren
	for(int i=1;i<n;i++){
		while(ans.size()>=2&&ccw(ans[ans.size()-2],ans[ans.size()-1],p[i])){
			ans.pop_back();
		}
		ans.pb(p[i]);
	}
	//dung bao duoi
	for(int i=n-2;i>=0;i--){
		while(ans.size()>=2&&ccw(ans[ans.size()-2],ans[ans.size()-1],p[i])){
			ans.pop_back();
		}
		ans.pb(p[i]);
	}
	if(n>1) ans.pop_back();
	return ans;
	
}
int main(){
	faster
	cin>>n;
	vector<point>p(n);
	for(int i=0;i<n;i++){
		int u,v;cin>>u>>v;
		p[i]={u,v};
	}
	vector<point>hull=tinh(p);
	cout<<hull.size()<<endl;
	for(int i=0;i<hull.size();i++){
		cout<<hull[i].x<<" "<<hull[i].y<<endl;
	}



	return 0;
}

