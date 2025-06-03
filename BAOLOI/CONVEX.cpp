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
	db x,y;
};
vector<point>p;
void nhap(){
	cin>>n;
	for(int i=1;i<=n;i++){
		db u,v;cin>>u>>v;
		p.pb({u,v});
	}
}
bool ccw(const point &a,const point &b,const point &c){
	return ((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y)>0);
}
vector<point>tinh(){
	sort(all(p),[](const point &a,const point &b){
		if(a.x!=b.x) return a.x<b.x;
		return a.y<b.y;
	});
	vector<point>hull;
	hull.pb(p[0]);
	for(int i=1;i<n;i++){
		while(hull.size()>=2&&ccw(hull[hull.size()-2],hull[hull.size()-1],p[i])){
			hull.pop_back();
		}
		hull.pb(p[i]);
	}
	//bao loi duoi
	for(int i=n-2;i>=0;i--){
		while(hull.size()>=2&&ccw(hull[hull.size()-2],hull[hull.size()-1],p[i])){
			hull.pop_back();
		}
		hull.pb(p[i]);
	}
	//giu lai diem dau tien
	return hull;
}
db tinh(point a,point b){
	return 1.0*sqrt(1.0*pow(a.x-b.x,2.0)+1.0*pow(a.y-b.y,2.0));
}
void solve(vector<point>hull){
	db ans=0;
	for(int i=0;i<hull.size()-1;i++){
		ans+=1.0*tinh(hull[i],hull[i+1]);
	}
	cout<<fixed<<setprecision(2)<<ans;

}
int main(){
	freopen("CONVEX.INP","r",stdin);
	freopen("CONVEX.OUT","w",stdout);
	faster
	nhap();
	vector<point>hull=tinh();
	solve(hull);

	



	return 0;
}

