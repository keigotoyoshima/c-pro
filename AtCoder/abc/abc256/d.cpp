#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <math.h>
#include <string>
#include <assert.h>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second





// int main(){
//   int n; cin >> n;
//   vector<pair<int,int>>LR;
//   for (int i = 0; i < n; i++)
//   {
//     int l,r; cin >> l >> r;
//     LR.push_back(make_pair(l,r));
//   }
//   sort(LR.begin(), LR.end());

//   vector<pair<int, int>> ans;
//   int l = LR[0].first;
//   int r = LR[0].second;
//   if(n == 1){
//     ans.push_back(make_pair(l, r));
//   }
//   for (int i = 1; i < n; i++)
//   {
//     int tem_l = LR[i].first;
//     int tem_r = LR[i].second;
//     if(r < tem_l){
//       ans.push_back(make_pair(l,r));
//       l = LR[i].first;
//       r = LR[i].second;
//     }else{
//       if(r < tem_r){
//         r = tem_r;
//       }
//     }
//     if (i + 1 == n)
//     {
//       ans.push_back(make_pair(l, r));
//     }
//     // cout << l << " " << r << endl;

//   }
//   for (int i = 0; i < ans.size(); i++)
//   {
//     cout << ans[i].first << " " << ans[i].second << endl;
//   }
  

//   return 0;
// }

// 解法2
int main(){
  int n; cin >> n;
  vector<pair<int,int>>LR;
  for (int i = 0; i < n; i++)
  {
    int l,r; cin >> l >> r;
    LR.push_back((make_pair(l,r)));
  } 
  sort(LR.begin(), LR.end());

  vector<pair<int, int>> ans;
  for(auto [l,r] : LR){
    if (ans.size() == 0 || ans.back().second < l)
    {
      ans.push_back(make_pair(l,r));
    }
    else
    {
      chmax(ans.back().second, r);
    }
  }

  for(auto [l,r] : ans){
    cout << l << " " << r << endl;
  }
  return 0; 
}