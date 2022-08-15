#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
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
#include <functional>
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



bool isSame(vector<vector<int>>a, vector<vector<int>>b){
  if(a.size() != b.size() || a[0].size() != b[0].size()) return false;
  for(int i = 0; i < a.size(); i++){
    for(int j = 0; j < a[0].size(); j++){
      if(a[i][j] != b[i][j]) return false;
    }
  }
  return true;
}


int main(){
  int h1,w1; cin >> h1 >> w1;
  vector<vector<int>>a(h1,vector<int>(w1));
  for(int i = 0; i < h1; i++){
    for(int j = 0;j < w1; j++){
      cin >> a[i][j];
    }
  }
  int h2,w2; cin >> h2 >> w2;
  vector<vector<int>>b(h2,vector<int>(w2));
  for(int i = 0; i < h2; i++){
    for(int j = 0;j < w2; j++){
      cin >> b[i][j];
    }
  }
  
  for(int H = 0; H < (1<<h1); H++){
    for(int W = 0; W < (1<<w1); W++){
      int height = __builtin_popcount(H);
      int width = __builtin_popcount(W);

      vector<vector<int>>tem_grid;

      for(int i = 0; i < h1; i++){
        vector<int>tem_row;
        for(int j = 0; j < w1; j++){
          if((H>>i)&1 && (W>>j)&1) tem_row.push_back(a[i][j]);
        }
        if(tem_row.size() != 0){
          tem_grid.push_back(tem_row);
        }
      }
      // coutGrid(tem_grid);
      if(isSame(tem_grid, b)){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}