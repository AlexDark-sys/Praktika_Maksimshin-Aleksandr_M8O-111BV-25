#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    long long ans = 1;
    for (int i = 0; i < N; i++) {
        long long t;
        cin >> t;
        ans = lcm(ans, t);
    }
    
    cout << ans << '\n';
    
    return 0;
}