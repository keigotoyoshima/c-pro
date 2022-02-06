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
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INFL = 1LL << 60;
const ll inf = 1e15;

int main() {
  int n,m; cin >> n >> m;
  
  vector<int>k(m);
  vector<vector<int>>a(m);
  for (int i = 0; i < m; i++)
  {
    int kk; cin >> kk;
    k[i] = kk;
    for (int j = 0; j < kk; j++)
    {
      int t; cin >> t;
      --t;
      a[i].push_back(t);
    }
  }
  vector<int>p(m);
  for (int i = 0; i < m; i++)
  {
    cin >> p[i];
  }
  int cnt = 0;
  // スイッチの状態を決めうち
  for (int bit = 0; bit < (1<<n); ++bit)
  {
    //  オンのスイッチ番号を保持
      set<int>st;
      bool flag = true;
      for (int i = 0; i < n; ++i) {
          if (bit & (1<<i)) { 
              st.insert(i);
          }
      }
      for (int j = 0; j < m; j++)
      {
        int num_k = k[j];
        int tem = 0;
        for (int l = 0; l < num_k; l++)
        {
          if(st.find(a[j][l]) != st.end())tem++;
        }
        tem = tem%2;
        if(tem != p[j]) {
          flag = false;
          break;
        }
        
      }
      if(flag) ++cnt;
      
  }
  cout << cnt << endl;

  return 0;
}