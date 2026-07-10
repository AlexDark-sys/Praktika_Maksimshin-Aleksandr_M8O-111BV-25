#include <iostream>
#include <vector>
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
    
    long long min_price = 0;
    int min_pos = 1;
    
    long long max_profit = LLONG_MIN;
    int buy_pos = -1, sell_pos = -1;
    
    long long current_price = 0;
    
    for (int i = 0; i < n; i++) {
        current_price += a[i];
        
        long long profit = current_price - min_price;
        
        if (profit > max_profit) {
            max_profit = profit;
            buy_pos = min_pos;
            sell_pos = i + 2;
        }
        
        if (current_price < min_price) {
            min_price = current_price;
            min_pos = i + 2;
        }
    }
    
    if (max_profit <= 0) {
        cout << "-1 -1\n";
    } else {
        cout << buy_pos << ' ' << sell_pos << '\n';
    }
    
    return 0;
}