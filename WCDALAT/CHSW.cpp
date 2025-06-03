#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;

main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int k;cin>>k;
	cin.ignore();
	while(k--){
		string s,t;
		getline(cin,s);
		getline(cin,t);
		if(s.length()==1&&s!=t&&s[0]=='1') {
				cout<<-1<<endl;
		}else{
			vector<int>v;
			int dem=0;
			for(int i=0;i<s.length();i++){
				if(s[i]!=t[i]&&s[i]!='?') v.push_back(i);
				if(s[i]=='?') dem++;
			}
			int ans1=0;
			if(v.size()%2==0){
				for(int i=0;i<v.size();i+=2){
					int x1=v[i],x2=v[i+1];
					if(s[x2]==t[x1]&&s[x1]==t[x2]) ans1++;
					else{
						ans1+=2;
					}
				}
				
			}
			if(v.size()%2!=0){
				int ans2=0,ans3=0;
				for(int i=0;i<v.size();i+=2){
					int x1=v[i],x2=v[i+1];
					if(s[x2]==t[x1]&&s[x1]==t[x2]) ans2++;
					else{
						ans2+=2;
					}
				}
				ans2++;
				for(int j=v.size()-1;j>=0;j-=2){
					int x1=v[j],x2=v[j-1];
					if(s[x2]==t[x1]&&s[x1]==t[x2]) ans3++;
					else{
						ans3+=2;
					}
				}
				ans3++;
				ans1=min(ans2,ans3);
			}
			cout<<ans1+dem<<endl;
		}
	}

}

