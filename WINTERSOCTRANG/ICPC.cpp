#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;

main(){
	freopen("icpc.inp","r",stdin);
	freopen("icpc.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	vector<int>t;
	map<int,char>mp;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		mp[x]=char(65+i-1);
		t.push_back(x);
	}
	sort(t.begin(),t.end());
	int s=0;
	int cnt=0;
	string s1="";
	for(int i=0;i<t.size();i++){
		if(s+t[i]>300) break;
		s+=t[i];
		cnt++;
	}
	int pnt=0; 
	for(int i=0;i<cnt;i++){
		pnt +=t[i]*(cnt-i);
		s1+=mp[t[i]];
	}
	cout<<cnt<<" "<<pnt<<" "<<s<<endl;
	cout<<s1;
	
}

