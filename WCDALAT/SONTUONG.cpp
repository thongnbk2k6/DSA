#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;

main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a1,a2,b1,b2;cin>>a1>>a2>>b1>>b2;
	int s=0;
	if(a2<a1) swap(a1,a2);
	if(b2<b1) swap(b1,b2);
	int t1=a2-a1;
	int t2=b2-b1;
	s=t1+t2;
	// hinh nho nam hoan toan trong hinh lon
	if(a1>=b1&&a2<=b2){
		s-=t1;
	}
	else{
		if(a1<=b1&&a2>=b2){
			s-=t2;
		}else{
			if(a2>b1&&b2>b1&&b2>a2) s-=(a2-b1);
			else {
				if(b2>a1&&a2>b1&&a2>b2) s-=(b2-a1);
			}
		}
	}
	cout<<s<<endl;
	//hai hinh khong  giao nhau khong can tinh
	//hai hinh giao nhau
	
	
}

