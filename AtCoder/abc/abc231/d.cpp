#include <iostream>
#include <vector>
#include <queue>
#include <deque>  
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n;
bool flag = true;
vector<vector<int>>vec;
vector<bool>seen;


bool dfs(int v) {
  seen[v] = true;
  int cnt = 0;
  for (auto next_v : vec[v]) { 
    if (seen[next_v]) {
      ++ cnt;
      continue;
    }
    dfs(next_v); 
  } 
  if(cnt > 1) flag = false;
  return 0;
}
// dpfでの解法
// int main(){
//   int m; cin >> n >> m;
//   vec.resize(n);
//   seen.assign(n,false);
//   for (int i = 0; i < m; i++) 
//   {
//     int a,b; cin >> a >> b;
//     --a; --b;
//     vec[a].push_back(b);
//     vec[b].push_back(a);
//   }
  
//   for (int i = 0; i < n; i++)
//   {
//     int size = vec[i].size();
//     if(size > 2) {
//       flag = false;
//       break;
//     }
//     if(seen[i] == true) continue;
//     dfs(i);
//   }
  

//   if (flag == true)
//   {
//     cout << "Yes" << endl;
//   } else{
//     cout << "No" << endl;
//   }
//   return 0;
// }

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int main(){
  int m; cin >> n >> m;
  vec.resize(n);
  seen.assign(n,false);
  UnionFind uni(n);
  uni.init(n);
  vector<int>deg(n,0);
  for (int i = 0; i < m; i++) 
  {
    int a,b; cin >> a >> b;
    --a;--b;
    if(uni.issame(a,b)){
      cout << "No" << endl;
      return 0;
    }
    uni.merge(a,b);
    deg[a] ++;
    deg[b] ++;
  }
  for (int i = 0; i < n; i++)
  {
    if(deg[i] > 2){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}