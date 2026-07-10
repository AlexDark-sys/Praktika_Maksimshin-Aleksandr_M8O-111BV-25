#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, m;
    cin >> n >> k >> m;
    
    vector<int> dangerous(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        dangerous[x] = 1;
    }
    
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    
    long long window_sum = dp[0];
    
    for (int i = 1; i <= n; i++) {
        if (dangerous[i]) {
            dp[i] = 0;
        } else {
            dp[i] = window_sum;
        }
        
        window_sum = (window_sum + dp[i]) % MOD;
        if (i - k >= 0) {
            window_sum = (window_sum - dp[i - k] + MOD) % MOD;
        }
    }
    
    cout << dp[n] << '\n';
    
    return 0;
}