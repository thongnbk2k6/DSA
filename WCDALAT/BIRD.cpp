#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;

main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	vector<int>v(n+2,0);
	map<int,int>mp;
	map<ll,vector<int>>cc;
	priority_queue<int>q;
	priority_queue<int>q1;
	set<int>se;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		q.push(v[i]);
		if(!se.count(v[i])){
			q1.push(v[i]);
			se.insert(v[i]);
			mp[v[i]]=i;
		}
		
		cc[v[i]].push_back(i);//luu cac vi tri cac phan tu cung giong nhau
	}
	//o(n)
	bool b[maxn];
	ll power=0;
	memset(b,0,sizeof(b));
	while(!q.empty()){
		int x=q.top();q.pop();
		if(b[mp[x]]){
//			for(int i=mp[x]+1;i<=n+1;i++){
//				if(v[i]==x){
//					mp[x]=i;
//					break;
//				}
//			}
			for(int it:cc[x]){
				if(!b[it]){
					mp[x]=it;
					break;
				}
			}
		}
		power+=x;
		int l=mp[x]-1;
		int r=mp[x]+1;
		while(b[l]){
			l--;
		}
		while(b[r]){
			r++;
		}
		b[mp[x]]=1;
		power+=v[l]+v[r];
	}
	cout<<power;
}

