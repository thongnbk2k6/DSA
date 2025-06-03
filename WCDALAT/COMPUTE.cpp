#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
#define ll long long
#define pll pair<long long,long long>
const long long maxn=1e6;
const long long minn=-1e6;
stack<string>st;
vector<string>v;
string s;
string stoxau(int n){
	string t="";
	while(n>0){
		t+=n%10+'0';
		n/=10;
	}
	reverse(t.begin(),t.end());
	return t;
}
bool kt(string s){
	for(int i=0;i<s.length();i++){
		if(s[i]=='X') return true;
	}
	return false;
}
int C(string s){
	int ans=1;
	for(int i=0;i<s.length();i++){
		if(s[i]=='X') continue;
		ans*=(s[i]-48);
	}
	return ans;
}
int x;
void xuly(){
	getline(cin,s);
	string t;
	stringstream ss(s);
	while(ss>>t){
		if(t[0]>='0'&&t[0]<='9'){
			st.push(t);
		}else{
			if(t[0]=='X'){
				string t1=st.top();st.pop();
				t1=t1+t;
				st.push(t1);
			}else{
				if(t=="*"){
					string t1=st.top();st.pop();
					string t2=st.top();st.pop();
					if(kt(t1)){
						int x1=C(t1);
						st.push(stoxau(x1*stoi(t2)));
					}
					else if(kt(t2)){
						int x2=C(t2);
						st.push(stoxau(stoi(t1)*x2));
					}
				}
			}
		}
	}
	if(st.size()==1){
		string t1=st.top();st.pop();
		if(!kt(t1)){
			cout<<"none"<<endl;
		}
	}
	
	if(st.size()==2){
		string t1=st.top();st.pop();
		string t2=st.top();st.pop();
		if(kt(t1)){
			int x2=stoi(t2);
			int x1=C(t1);
			if(x2==0&&x1==0) {
				cout<<"multiple"<<endl;
				return;
			}
			if(x1==0&&x2!=0) {
				cout<<"none"<<endl;
				return;
			}
			while(__gcd(x1,x2)!=1){
				int tg=__gcd(x1,x2);
				x2/=tg;
				x1/=tg;
			}
			cout<<x2<<" "<<x1<<endl;
		}
		else 
			if(kt(t2)){
				int x1=stoi(t1);
				int x2=C(t2);
				if(x2==0&&x1==0) {
					cout<<"multiple"<<endl;
					return;
				}
				if(x1==0&&x2!=0) {
					cout<<"none"<<endl;
					return;
				}
				while(__gcd(x1,x2)!=1){
				int tg=__gcd(x1,x2);
				x2/=tg;
				x1/=tg;
			}
			cout<<x1<<" "<<x2<<endl;
				
			}else{
				cout<<"none"<<endl;
				return;
			}
	}
		
}
main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	xuly();
	
}

