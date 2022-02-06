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
  int n,m; cin >> n >> m;
  vector<vector<int>>a(n,vector<int>(n,inf));
  for (int i = 0; i < m; i++)
  {
    int k1; cin >> k1;
    int k2; cin >> k2;
    k1--;
    k2--;
    a[k1][k2] = 1;
    a[k2][k1] = 1;
  }
  int ans = 0;
  for (int bit = 0; bit < (1<<n); ++bit)
  {

      set<int> S;
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
          if (bit & (1<<i)) { 
              S.insert(i);
              cnt++;
          }
      }
      bool flag = true;


      // 決め打ちされたsetが全て友人関係を持っているか調査
      for(auto itr1 = S.begin(); itr1 != S.end(); ++itr1) {
        int index1 = *itr1;

        for(auto itr2 = S.begin(); itr2 != S.end(); ++itr2) {
          int index2 = *itr2;


          if(index1 == index2) continue;
          if(a[index1][index2] == inf){
            flag = false;
          }
        }
      }


      if(flag) {
        ans = max(ans, cnt);
      }
      
  }
  cout << ans << endl;
  return 0;
  
}