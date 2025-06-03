#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll cs = 2e5 + 7;
const ll mod = 1e9 + 7;
const ll INF = mod;
const ll maxN = 5e3 + 7;
const int block_size = 350;

int typeoftest;
ll n,lim,cost;
ll a[cs];

ll Prefix[cs];

ll GetSum(int left,int right) {
    return Prefix[right] - Prefix[left - 1];
}

bool check(int mid) {
    for (int i = 1;i + mid - 1 <= n;i++) {
        int l = i;
        int r = i + mid - 1;
        int m = (l + r) / 2;
        ll sum = (m - l + 1) * a[m] - GetSum(l,m) + GetSum(m + 1,r) -   (r - m) * a[m];
        if (sum <= cost) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> typeoftest >> n >> lim >> cost;
    for (int i = 1;i<=n;i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n+ 1);
    for (int i = 1;i<=n;i++) {
        Prefix[i] = Prefix[i - 1] + a[i];
    } 
    int l = 1;
    int r = n;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            res = mid;
            cout<<res<<endl;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res;
    return 0;
}
