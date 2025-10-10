
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n , m ;
    cin>>n>>m;
    vector<int> a(n) ; 
    for(int i = 0 ; i<n ;i++){
        cin>>a[i];
    }
    vector<int> count_m(m+1,0) ; 
    int count = 0 ;
    int ans = INT_MAX ;
    int i = 0 , j =0 ;
    sort(a.begin() , a.end());
    while(i<n  ){
        while(j<n && count <m){
            
            for(int k = 1 ; k*k <= a[j] && k<=m ; k++){
                if(a[j]%k ==0){
                    // cout<<a[j]<<' '<<k<<endl;

                    int fac1 = k , fac2 = a[j]/k ;
                    if(count_m[fac1]==0)
                        count++;
                    count_m[fac1]++;
                    if(fac2<=m && fac2!=fac1 ){
                        if(count_m[fac2]==0){
                            count++;
                        }
                        count_m[fac2]++;
                    }
                }
            }
            
            if(count==m)
                break ;
            j++;
        }
        if(count == m)
            ans = min(ans , a[j]-a[i]);
        
        for(int k = 1 ; k*k <= a[i] && k<=m ; k++){
            if(a[i]%k ==0){
                int fac1 = k , fac2 = a[i]/k ;
                count_m[fac1]--;
                if(fac1!=fac2 && fac2<=m){
                    count_m[fac2]--;
                }
                if(count_m[fac1]==0){
                    count-- ;
                }
                if(fac2<=m && fac2!=fac1 && count_m[fac2]==0){
                    count--;
                }
            }
        }
        
        i++;


    }
    if (ans == INT_MAX ){
        ans = -1;
    }
    cout<<ans<<endl;
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