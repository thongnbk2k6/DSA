#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;
int n,m,k;
long long f[11];
map<int,int>kitu;
bool kt(int n){
	return n>0;
}
int  xuly(){
	long long t=pow(2,m);
	int dem=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=26;j++){
			f[i]=((f[i-1]*33)^j)%t;
			if(f[i]==k) dem++;
		}
	}
	return dem;
}
main(){
	freopen("DECRYPTE.INP","r",stdin);
	freopen("DECRYPRE.INP","w",stdout);
	f[0]=0;
	cin>>n>>k>>m;
	
	cout<<xuly()<<endl;
//	for(int i=1;i<=10;i++){
//		cout<<char(kitu[i])<<" ";
//	}
}

