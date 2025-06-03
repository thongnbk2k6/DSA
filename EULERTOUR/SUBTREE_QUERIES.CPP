#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define getBit(n,i) ((n>>i)&1)
#define fi first
#define sc second
#define pdb pair<double,double>
#define db double
#define endl '\n'

const long long maxn=1e6+5;
const long long minn=-1e6;
const long long inf=1e18;
template <class T> class BIT{
	
private:
	int size;
	vector<T>Bit;
	vector<T>nodeValue;
public:
	BIT(int size): size(size), Bit(size+1,0ll), nodeValue(size+1,0ll) {};
	// BIT(int size):: Bit
	void add(int id,int val){
		nodeValue[id] +=val;
		for(;id<=size;id+=id&-id) Bit[id] += val;//val o day la val1 - nodeValue[id]
		//nhu vay viec cong them val1 - nodeValue[id] se xoa gia tri nodeValue[id] trong cay Bit
		//va cap nhat gia tri moi
	}
	void set(int id,int val){//coi day la val1
		add(id, val - nodeValue[id]);
	}
	long long get(int id){//tinh tong tu 1 den id trong cay Bit
		long long res = 0;
		for(;id>=1;id&=id-1){
			res+=Bit[id];
		}
		return res;

	}

};
int n,q,val[maxn],timer,firstMeet[maxn],lastMeet[maxn];
vector<int>adj[maxn];
void preprocess(){
	timer = 0;
}
void nhap(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
void buildEulerTour(int v,int parent){
	firstMeet[v] = ++timer;
	for(int u:adj[v]){
		if(u==parent) continue;
		buildEulerTour(u,v);
	}
	lastMeet[v] = timer;
}
void solve(){
	buildEulerTour(1,-1);
	BIT<long long> bit(n);
	for(int i=1;i<=n;i++){
		bit.set(firstMeet[i],val[i]);
	}
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op==1){
			int s,x;cin>>s>>x;
			bit.set(firstMeet[s],x);
		}else{
			int u;cin>>u;
			cout<<bit.get(lastMeet[u]) - bit.get(firstMeet[u]-1)<<endl;
		}
	}

}
int main(){
	faster
	preprocess();
	nhap();
	solve();
	




	return 0;
}
