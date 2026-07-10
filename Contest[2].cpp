#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, u, v;
    cin >> n >> m >> u >> v;
    
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    
    vector<int> dist(n + 1, -1);
    queue<int> q;
    
    dist[u] = 0;
    q.push(u);
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (int to : g[x]) {
            if (dist[to] == -1) {
                dist[to] = dist[x] + 1;
                q.push(to);
            }
        }
    }
    
    if (dist[v] == -1) {
        cout << -1 << '\n';
        return 0;
    }
    
    vector<int> path;
    int cur = u;
    path.push_back(cur);
    
    while (cur != v) {
        for (int to : g[cur]) {
            if (dist[to] == dist[cur] + 1) {
                cur = to;
                path.push_back(cur);
                break;
            }
        }
    }
    
    for (int x : path) {
        cout << x << ' ';
    }
    cout << '\n';
    
    return 0;
}