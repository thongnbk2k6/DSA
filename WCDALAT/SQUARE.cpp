#include<bits/stdc++.h>
using namespace std;
const int maxN=1e6;
const int minN=-1e6;
int a[60][60],n;
bool kt(string s){
	int dem=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='X') dem++;
	}
	if(dem>2||dem==0) return 0;
	return 1;
}
int kt1(int x,int y,int u,int v){
	int dem=0;
	if(x==u||y==v) return 0;
	dem+=a[x][y]+a[x][v]+a[u][v]+a[u][y];
	if(dem==4) return 1;
	else return 0;
	
	
}
main(){
//	freopen("square.inp","r",stdin);
//	freopen("square.out","w",stdout);
	int tc;cin>>tc;
	for(int z=1;z<=tc;z++){
		cin>>n;
		cin.ignore();
		bool ok=1;
		char c[60][60];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>c[i][j];
				if(c[i][j]=='X') a[i][j]=1;
				else a[i][j]=0;
			}
		}
		
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<a[i][j]<<" ";
//			}
//			cout<<endl;
//		}
//		return 0;
		
		for(int i=1;i<=n;i++){
			string t1="";
			for(int j=1;j<=n;j++){
				t1+=a[i][j];
			}
			if(!kt(t1)){
				cout<<"IMPOSSIBLE"<<endl;
				ok=0;
				break;
			}
		}
		if(!ok) continue;
		for(int j=1;j<=n;j++){
			string t1="";
			for(int i=1;i<=n;i++){
				t1+=a[i][j];
			}
			if(!kt(t1)){
				cout<<"IMPOSSIBLE"<<endl;
				ok=0;
				break;
			}
		}
		if(!ok) continue;
		int hv=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int u=i;u<=n;u++){
					for(int v=j;v<=n;v++){
						hv+=kt1(i,j,u,v);
					}
				}
				
			}
		}
		cout<<hv;return 0;
		if(hv==n/2) cout<<"POSSIBLE"<<endl;
		else cout<<"IMPOSSIBLE"<<endl;
	}

}

