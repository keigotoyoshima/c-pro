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

// dp[i+1][j]=i日目にj番目のの派手さを選んだ際の，絶対値の合計
ll dp[210][210];

// 計算量はおそらくDK=200*200
int main(){
  int d,k; cin >> d >> k;
  vector<int>day(d);
  for (int i = 0; i < d; i++)
  {
    cin >> day[i];
  }
  vector<pair<int,int>>len(k);
  vector<int>c(k);
  for (int i = 0; i < k; i++)
  {
    cin >> len[i].first  >> len[i].second;
    cin >> c[i];
  }
  for (int i = 0; i < 210; i++)
  {
    for (int j = 0; j < 210; j++)
    {
      dp[i][j] = -1;
    }
    
  }
  // 初期値

  // for (int i = 0; i < k; i++)
  // {
  //   dp[0][i] = 0;
  // }
  dp[0][0] = 0;
  // 初期値を考える時，遷移がうまくいけば，なんでもいい

  for (int i = 0; i < d; i++)
  {
    for (int pre_j = 0; pre_j < k; pre_j++)
    {
      // i-1日目にpre_j番目の服を選ぶ 
      if(dp[i][pre_j]==-1) continue;
      for (int j = 0; j < k; j++)
      {
        // i日目にj番目の服を選ぶ
        int from = len[j].first;
        int to = len[j].second;
        int tem = day[i];
        if(tem < from || to < tem) continue;
        if(i == 0){
          chmax(dp[i+1][j], dp[i][pre_j]);
        }else{
          chmax(dp[i+1][j], dp[i][pre_j] + abs(c[pre_j]-c[j]));
        }
      }
    }
  }

  ll max_abs =  0;
  for (int i = 0; i < k; i++)
  {
    chmax(max_abs, dp[d][i]);
  }

  cout << max_abs << endl;

  // for (int i = 0; i <= d; i++)
  // {
  //   for (int j = 0; j < k; j++)
  //   {
  //     cout << dp[i][j] << " " ;
  //   }
  //   cout << endl;
  // }
  
  
  
  return 0;
  
}