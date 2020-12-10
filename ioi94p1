#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<int>>arr(n+1, vector<int>(n+1));
    vector<vector<int>>dp(n+1, vector<int>(n+1));
    int ans = 0;

    for(int i = 1;i <= n; i++){
        for(int j = 1; j<=n;j++){
            if(j>i)continue;
            cin >> arr[i][j];
        }
    }
    dp[1][1] = arr[1][1];
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n;j++){
            if(j>i || (j==1 & i==1))continue;

            dp[i][j] = max(dp[i-1][j] + arr[i][j], dp[i-1][j-1]+arr[i][j]);

            ans = max(ans, dp[i][j]);
        }
    }
    cout<<ans;
  
    return 0;
}
