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
#define fi first
#define se second
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int MOD = 1000000007;
// const int dx[] = {-1, 0, 1, 0};
// const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<string>G;
vector<vector<int>> dp;

const int dw[] = {0,1};
const int dh[] = {1,0};
int h,w;

void add(int &a, int b){
  cout << a << " : " << b << endl;
  a += b;
  // a %= MOD;
}

// void rec(int current_h, int current_w){
//   for (int i = 0; i < 2; i++)
//   {
//     int next_w = current_w + dw[i];
//     int next_h = current_h + dh[i];
//     // cout << "next_h " << next_h << " " << "next_w " << next_w << endl;
//     if(next_w >= w ||  next_h >= h) continue;
//     if (G[next_h][next_w] == '#') continue;
//     add(dp[next_h][next_w],dp[current_h][current_w]);
//     if(next_h == 2 && next_w == 3){
//       cout << "current_h " << current_h << " " << "current_w " << current_w << " dp " << dp[current_h][current_w] << endl;
//       cout << "next_h "<< next_h << " next_w " << next_w << " dp "<< dp[next_h][next_w] << endl;
//     }
//     rec(next_h, next_w);
//   }
// }

int main(){
  cin >> h >> w;
  G.resize(h);
  dp.assign(h,vector<int>(w,0));
  for (int i = 0; i < h; i++)
  {
    string input;
    cin >> input;
    G[i] = input;
  }

  dp[0][0] = 1;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {

      for (int k = 0; k < 2; k++)
      {
        int next_j = j + dw[k];
        int next_i = i + dh[k];
        if(next_j >= w ||  next_i >= h) continue;
        if (G[next_i][next_j] == '#') continue;
        dp[next_i][next_j] += dp[i][j] ;
        dp[next_i][next_j] %= MOD;
      }
    }
  }
  
  

  // for(auto v: dp){
  //   for(auto nv: v){
  //     cout << nv << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  cout << dp[h-1][w-1] << endl;

  return 0;
}