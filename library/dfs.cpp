#include <iostream>
#include <vector>
using namespace std;



// 深さ優先探索
vector<bool> seen;
vector<vector<int>> G;

void dfs(int v) {
    seen[v] = true; 
    for (auto nv : G[v]) { 
        if (seen[nv]) continue; 
        dfs(nv); 
    }
}

int main() {
    int N, M; cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    seen.assign(N, false); 
    // s == startのindex
    dfs(s);
    if (seen[t]) cout << "Yes" << endl;
    else cout << "No" << endl;
}