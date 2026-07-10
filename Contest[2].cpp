#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    long long mass;
    cin >> n >> mass;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    vector<int> ans;
    int left = 0;
    
    while (left < n) {
        bool absorbed = false;
        while (left < n && a[left] < mass) {
            mass += a[left];
            ans.push_back(left + 1);
            left++;
            absorbed = true;
        }
        if (!absorbed && left < n) {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";
    for (int idx : ans) {
        cout << idx << ' ';
    }
    cout << '\n';
    
    return 0;
}