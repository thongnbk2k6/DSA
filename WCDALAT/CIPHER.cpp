#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;

main(){
	int tc;cin>>tc;
	cin.ignore();
	map<int,char>mp;
	int x=65;
	for(int i=0;i<=25;i++){
		mp[i]=char(x);
		x++;
	}
	while(tc--){
		string s;cin>>s;
		int n=s.length();
		int a[n],b[n];
		for(int i=0;i<n;i++){
			a[i]=s[i]-65;
			b[i]=a[i];
		}
		b[1]=a[0];
		b[n-1]=a[n-1];
		for(int i=1;i<=n-2;i+=2){
			if(i==1){
				b[i]=a[i-1];
				continue;
			}
			if(i==n-2){
				b[i]=a[n-1];
				continue;
			}
			if(b[i]>a[i+1]){
				b[i+2]=26-a[i+1]+b[i];	
			}
			else{
				b[i+2]=26-a[i+1]-b[i];
			}
		}
		if(a[n-2]<b[n-3]){
			b[n-1]=26-a[n-2]-b[n-1];
		}
		else{
			b[n-1]=26-a[n-2]+b[n-1];
		}
		for(int i=n-2;i>=0;i-=2){
			if(a[i-1]<b[i]){
				b[i-2]=26-a[i-1]+b[i];
			}
			else{
				b[i-2]=26-a[i-1]-b[i];
			}
		}
		for(int x:b) cout<<char(x)<<" ";
	}
	
}

