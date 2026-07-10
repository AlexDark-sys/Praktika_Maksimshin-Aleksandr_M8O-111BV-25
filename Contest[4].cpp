#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<long long> diff(N + 2, 0);
    
    for (int i = 0; i < Q; i++) {
        int l, r;
        long long v;
        cin >> l >> r >> v;
        
        diff[l] += v;
        diff[r + 1] -= v;
    }
    
    vector<long long> ans(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        ans[i] = ans[i - 1] + diff[i];
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}