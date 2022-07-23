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
#include <iomanip>
#include <math.h>
#include <string>
#include <assert.h>
using namespace std;
using ll = long long;
#define fi first
#define se second
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int MOD = 1000000007;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};





int main(){
  int n; cin >> n;
  vector<vector<char>>G(n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      char input;
      cin >> input;
      G[i].push_back(input);
    }
    
    
  }

  // for(auto v: G){
  //   for(auto nv : v){
  //     cout << nv << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  int start = 1;
  bool flag = false;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = start; j < n; j++)
    {
      char right = G[i][j];
      char left = G[j][i];
      // cout << i << ":" << j << endl;
      // cout << left << ":" << right << endl;
      if((right == 'W' && left == 'L') || ( right == 'L' && left == 'W')) continue;
      if((right == 'D' && left == 'D') || ( right == 'D' && left == 'D' )) continue;
      cout <<  "incorrect" << endl;
      return 0;
    }
    
    start++;
  }
  cout << "correct" << endl;
  return 0;
}