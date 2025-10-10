
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());
    vector<int> cnt(m + 1, 0);
    int covered = 0, ans = INT_MAX;
    int j = 0;

    auto add = [&](int x) {
        for (int k = 1; k * k <= x; k++) {
            if (x % k == 0) {
                int d1 = k, d2 = x / k;
                if (d1 <= m) {
                    if (cnt[d1] == 0) covered++;
                    cnt[d1]++;
                }
                if (d2 <= m && d2 != d1) {
                    if (cnt[d2] == 0) covered++;
                    cnt[d2]++;
                }
            }
        }
    };
    auto remove = [&](int x) {
        for (int k = 1; k * k <= x; k++) {
            if (x % k == 0) {
                int d1 = k, d2 = x / k;
                if (d1 <= m) {
                    cnt[d1]--;
                    if (cnt[d1] == 0) covered--;
                }
                if (d2 <= m && d2 != d1) {
                    cnt[d2]--;
                    if (cnt[d2] == 0) covered--;
                }
            }
        }
    };

    for (int i = 0; i < n; i++) {
        while (j < n && covered < m) {
            add(a[j]);
            j++;
        }
        if (covered == m) ans = min(ans, a[j - 1] - a[i]);
        remove(a[i]);
    }

    cout << (ans == INT_MAX ? -1 : ans) << "\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t ;
    cin>>t ;
    while(t--){
        solve() ;
    }
	return 0;
}