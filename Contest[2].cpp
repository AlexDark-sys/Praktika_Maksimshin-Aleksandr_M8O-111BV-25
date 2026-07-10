#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1] + 1) {
            cout << "Scammed\n";
            return 0;
        }
    }
    
    cout << "Deck looks good\n";
    return 0;
}