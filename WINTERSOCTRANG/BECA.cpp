#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
int dong,cot,n,a[1001][1001],parent[maxn],Size[maxn],vtchan[1001][1001],vtle[1001][1001],dinh=0,vs[1001][1001];
map<pair<int,int>,pair<int,int>>mp;
struct edge{
	int u,v,w;
};
vector<edge>canh;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
char c[1001][1001];

void make_set(){
	for(int i=1;i<=dinh;i++){
		parent[i]=i;
		Size[i]=1;
	}
}
int find(int u){
	if(u==parent[u]) return u;
	return parent[u]=find(parent[u]);
}
bool Union(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v) return 0;
	else{
		if(Size[u]<Size[v]) swap(u,v);
		parent[v]=u;
		Size[u]+=Size[v];
		return 1;
	}
	
}
void solve(){
	cin>>dong>>cot;
	//nhap mang char
//	n=dong*cot+dong*(cot+1);
	memset(vs,0,sizeof(vs));
	for(int i=1;i<=dong;i++){
		for(int j=1;j<=cot;j++){
			cin>>c[i][j];
		}
	}
	//nhap mang trong so
	for(int i=1;i<=dong;i++){
		for(int j=1;j<=cot;j++){
			cin>>a[i][j];
		}
	}
	//tinh mang vi tri
	
	for(int i=1;i<=cot;i++){
		dinh++;
		vtchan[0][i]=dinh;
	}
	for(int i=1;i<=dong;i++){
		for(int j=1;j<=cot+1;j++){
			dinh++;
			vtle[i][j]=dinh;
		}
		for(int k=1;k<=cot;k++){
			dinh++;
			vtchan[i][k]=dinh;
		}
	}

}
void tinhdinhke(){
	for(int i=1;i<=dong;i++){
		for(int j=1;j<=cot;j++){
			if(c[i][j]=='/'){
				canh.push_back({vtle[i][j],vtchan[i][j],a[i][j]});
				pair<int,int>pkey={vtle[i][j],vtchan[i][j]};
				pair<int,int>pval={i,j};
				mp[pkey]=pval;
				Union(vtle[i][j],vtchan[i-1][j]);
				Union(vtle[i][j+1],vtchan[i][j]);
				
				
			}else if(c[i][j]=='\\'){
				canh.push_back({vtle[i][j],vtchan[i-1][j],a[i][j]});
				pair<int,int>pkey={vtle[i][j],vtchan[i-1][j]};
				pair<int,int>pval={i,j};
				mp[pkey]=pval;
				Union(vtle[i][j],vtchan[i][j]);
				Union(vtle[i][j+1],vtchan[i-1][j]);		
			}	
		}
	}
}
ll ans=0;
void kruskal(){
	sort(canh.begin(),canh.end(),cmp);
	int dem=0;
	for(int i=0;i<canh.size();i++){
		if(Union(canh[i].u,canh[i].v)){
			ans+=canh[i].w;
			pair<int,int>pkey={canh[i].u,canh[i].v};
			pair<int,int>p=mp[pkey];
			vs[p.first][p.second]=1;
			dem++;
//			cout<<p.first<<" "<<p.second<<endl;
//			cout<<canh[i].u<<" "<<canh[i].v<<" "<<canh[i].w<<endl;	
		}
		if(dem==dinh-1) break;
	}
//	cout<<endl<<endl;
}

main(){
//	freopen("aquarium.inp","r",stdin);
//	freopen("aquarium.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	make_set();
	tinhdinhke();
	kruskal();
	
//	for(int i=1;i<=cot;i++){
//		cout<<vtchan[0][i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=dong;i++){
//		for(int j=1;j<=cot+1;j++){
//			cout<<vtle[i][j]<<" ";
//		}
//		cout<<endl;
//		for(int k=1;k<=cot;k++){
//			cout<<vtchan[i][k]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl<<endl;
//	for(int i=1;i<=dinh;i++){
//		for(int j=1;j<=dinh;j++){
//			if(kt(i,j)&&i!=j) cout<<i<<" "<<j<<"YES"<<endl;
//		}
//	}
	cout<<ans<<endl;
	for(int i=1;i<=dong;i++){
		for(int j=1;j<=cot;j++){
			if(vs[i][j]) cout<<'.';
			else cout<<c[i][j];
		}
		cout<<endl;
	}
}

