#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;
int m,n,k;
main(){
	cin>>m>>n>>k;
	int s=(n-1)*m+(m-1)*n;
	int tru=0;
	for(int i=1;i<=k;i++){
		int x,y;cin>>x>>y;
		if(x==m&&y==1||x==1&&y==n||x==1&&y==1||x==m&&y==n){
			tru+=2;
		}
		else{
			if(x==1||x==m||y==1||y==n){
				tru+=3;
			}else{
				tru+=4;
			}
		}
	}
	cout<<s-tru<<endl;
}

