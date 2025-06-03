#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n, m;
int sg[4*N], lz[4*N];

void update(int id, int l, int r, int u, int v){
	if(l > v || r < u) return;
	if(l >= u && r <= v){
		sg[id] = (r - l + 1) - sg[id];
		lz[id] ^= 1;
		return;
	}
	int m = (l + r) / 2;
	if(lz[id]){
		update(id*2, l, m, l, m);
		update(id*2+1, m+1, r, m+1, r);
		lz[id] = 0;
	}
	update(id*2, l, m, u, v);
	update(id*2+1, m+1, r, u, v);
	sg[id] = sg[id*2] + sg[id*2+1];
}

int get(int id, int l, int r, int u, int v){
	if(l > v || r < u) return 0;
	if(l >= u && r <= v){
		return sg[id];
	}
	int m = (l + r) / 2;
	if(lz[id]){
		update(id*2, l, m, l, m);
		update(id*2+1, m+1, r, m+1, r);
		lz[id] = 0;
	}
	int t1 = get(id*2, l, m, u, v);
	int t2 = get(id*2+1, m+1, r, u, v);
	return t1 + t2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	while(m--){
		int t, x, y;
		cin >> t >> x >> y;
		if(t==0){
			update(1, 1, n, x, y);
		}else{
			cout << get(1, 1, n, x, y) << '\n';
		}
	}
		
	
	return 0;
}
