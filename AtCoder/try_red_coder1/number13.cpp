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
const ll infl = 1e15;
int inf = 2147483647;

int main(){
  int r,c; cin >> r >> c;
  vector<vector<int>>a(r,vector<int>(c));
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for (int bit = 0; bit < (1<<r); ++bit)
    {
      set<int> st;
      vector<vector<int>>b;
      b = a;
      for (int i = 0; i < r; ++i) {
          if (bit & (1<<i)) { 
            for (int j = 0; j < c; j++)
            {
              b[i][j] = 1 - b[i][j];
            }
          }
      }
      int tem = 0;
      for (int i = 0; i < c; i++)
      {
        int num = 0;
        for (int j = 0; j < r; j++)
        {
          if(b[j][i] == 0) num++;
        }
        
        tem += max(num, r-num);
      }
      ans = max(tem, ans);
    }
    cout << ans << endl;
    return 0;
}

// 全体から一部分を引けば残りの部分に変換できる。
// 各桁のbitをそれぞれ反転したい時は 1-a[i][j]とする。