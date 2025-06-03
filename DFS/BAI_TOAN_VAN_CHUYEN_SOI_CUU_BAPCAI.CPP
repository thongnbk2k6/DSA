#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define all(v) v.begin(),v.end()
#define pb push_back
#define pii pair<int,int>
#define getbit(n,i) ((n>>i)&1)
#define fi first
#define sc second
#define pdb pair<double,double>
#define db double
#define endl '\n'

const long long maxn=1e6+5;
const long long minn=-1e6;
const long long inf=1e18;

class State{
private:
	
public:
	int wolf,goat,cabbage,boatman;
	State(int wolf,int goat,int cabbage,int boatman) : wolf(wolf), goat(goat), cabbage(cabbage), boatman(boatman) {};
	bool isValid(){
		if(goat==wolf&&goat!=boatman) return false;
		if(goat==cabbage&&goat!=boatman) return false;
		return true;
	}
	bool operator == (const State& other){
		return wolf == other.wolf && goat == other.goat && cabbage == other.cabbage && boatman == other.boatman;
	}
	bool isGoal(){
		return (wolf==1&&goat==1&&cabbage==1&&boatman==1);
	}

};

void preprocess(){
	
}

void nhap(){
	
}
void dfs(State curState,vector<State>& path, vector<State>& solution, vector<State>& visited){
	if(curState.isValid()==false) return;
	for(State tmp: visited){
		if(tmp == curState) return;
	}
	visited.push_back(curState);
	path.push_back(curState);
	if(curState.isGoal()){
		solution = path;
		return;
	}
	vector<State> nextState;
	int newSide = 1 - curState.boatman;
	nextState.push_back({curState.wolf,curState.goat,curState.cabbage,newSide});
	if(curState.goat == curState.boatman){
		nextState.push_back({curState.wolf,newSide,curState.cabbage,newSide});
	}
	if(curState.wolf == curState.boatman){
		nextState.push_back({newSide,curState.goat,curState.cabbage,newSide});
	}
	if(curState.cabbage == curState.boatman){
		nextState.push_back({curState.wolf,curState.goat,newSide,newSide});
	}
	for(State tmp : nextState){
		dfs(tmp,path,solution,visited);
		if(solution.size()>0) return;
	}
	path.pop_back();




}
void solve(){
	vector<State> path,solution, visited;
	State start(0,0,0,0);
	dfs(start,path,solution,visited);
	for(State tmp: solution){
		cout<<tmp.boatman<<" "<<tmp.goat<<" "<<tmp.goat<<" "<<tmp.cabbage<<endl;
	}

}
int main(){
	faster
	solve();



	return 0;
}
