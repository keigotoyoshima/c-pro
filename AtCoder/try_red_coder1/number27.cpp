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
Graph G;
int ma = 0;
int M, N; 
vector<int>piece={-1,1};

bool direction(int next_m, int next_n){
  if(next_m < 0 || next_m >= M || next_n < 0 || next_n >= N){
    return false;
  }
  return true;
}

void dfs(int pre_n, int pre_m, int m) {
  chmax(ma, m);
  int plus_x;
  int plus_y;
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      plus_x = 0; plus_y = 0;
      if(i == 0){
        plus_x = piece[j];
      }else{
        plus_y = piece[j];
      }
      
      int next_m = pre_m+plus_x;
      int next_n = pre_n+plus_y;
      if(pre_n == next_m && pre_m == next_n)continue;
      // 移動方法が確定

      if(direction(next_m,next_n)){

        if(G[next_n][next_m] == 1){ 
          
          G[next_n][next_m] = 0;
          dfs(next_n,next_m,m+1);
          G[next_n][next_m] = 1;
        }
        
      }
    }
    
  }
  
}

int main() {
    cin >> M >> N;
    G.resize(N);
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        int input; cin >> input;
        G[i].push_back(input);
      }
    }

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        if(G[i][j] == 1){
          G[i][j] = 0;
          dfs(i,j,1);
          G[i][j] = 1;
        }
      }
    }
    cout << ma << endl;
    return 0;
}

// 実行制限時間が長く設定してあるので、10の7乗を超えても気にしなくて大丈夫。