#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>
#include<math.h>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INFL = 1LL << 60;
const ll inf_ll = 1e15;
int inf_int = 2147483647;


// 深さ優先探索
using Graph = vector<vector<int>>;

vector<ll>ans;

void dfs(const Graph &G, int v, int from=-1) {
    for (auto next_v : G[v]) { 
      if(next_v == from) continue;
      ans[next_v] += ans[v];
      dfs(G, next_v, v);
    }
}

int main() {
    int N, Q; cin >> N >> Q;
    Graph G(N);
    
    ans.resize(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;--b;
        G[a].push_back(b);
        G[b].push_back(a);

    }
    for (int i = 0; i < Q; ++i) {
      int p, x;
      cin >> p >> x;
      --p;
      ans[p] += x;
    }
    dfs(G,0);
    
    for(auto v: ans){
      cout << v << " " ;
    }
    cout << endl;
    return 0;


}