#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pair<long long,long long>  ii
const long long maxn=1e6;
const long long minn=-1e6;
int n,q;
vector<int>a;
vector<int>b;
void nhap(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a.push_back(i);
	}
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		b.push_back(x);
	}
	
}

void xuly(){
	for(int i=1;i<=q;i++){
		int ans=0;
		int x,y;cin>>x>>y;
		swap(b[x-1],b[y-1]);
//		for(int it:b) cout<<it<<" ";return;
		vector<int>hv=a;
//		for(int j=0;j<n;j++){
//			if(hv[j]==b[j]) ans1++;
//		}
		for(int j=0;j<n;j++){
			int tg=hv[n-1],t=0;
			for(int k=0;k<n;k++){
				if(b[k]==hv[k]) t++;
			}
			ans=max(ans,t);
			hv.pop_back();
			hv.insert(hv.begin(),tg);
			
		}
		cout<<ans<<endl;
	}
	
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nhap();
	xuly();
}

