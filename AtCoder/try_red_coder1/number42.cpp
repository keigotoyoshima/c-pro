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
const long long INF = 1LL << 60;
const ll inf_ll = 1e15;
int inf_int = 2147483647;
using mpair = pair<int,int>;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};


// dp[i+1][j] :=  i日目までに都市jまで進んでいる場合の疲労度の最小値
ll dp[1010][1010];
int main(){
  int n, m; cin >> n >> m;
  vector<int>dis(n);
  vector<int>stress(m);
  for (int i = 0; i < n; i++)
  {
    cin >> dis[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> stress[i];
  }

  // 初期化
  for (int i = 0; i < 1010; i++)
  {
    for (int j = 0; j < 1010; j++)
    {
      dp[i][j] = INF;
    }
    
  }
  // 初期値
  dp[0][0] = 0;
  // m日以内
  for (int i = 0; i < m; i++)
  {
    // n回移動
    for (int j = 0; j < n; j++)
    {
      for (int forward = 0; forward < 2; forward++)
      {

        if(forward == 0){
          //  進まない場合
          chmin(dp[i+1][j+forward], dp[i][j]);
        } else{
          //  進む場合
          chmin(dp[i+1][j+forward], dp[i][j] + (stress[i]*dis[j]));
        }
      }
    }
  }
  
  ll min_ans = INF;
  for (int i = 0; i <= m; i++)
  {
    chmin(min_ans, dp[i][n]);
  }
  cout << min_ans << endl;

  // for (int i = 0; i < m; i++)
  // {
  //   for (int j = 0; j <= n; j++)
  //   {
  //     cout << dp[i][j] << " ";
  //   }
  //     cout << endl;
  // }
  
  
  return 0;
}