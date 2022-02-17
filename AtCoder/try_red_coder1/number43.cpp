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

// dp[i+1][j] := i番目にj番目の色を使った場合の塗り替えた色の総数の最小値
ll dp[1010][5];
int main(){
  int n; cin >> n;
  vector<string>s(5);
  for (int i = 0; i < 5; i++)
  {
    cin >> s[i];
  }

  // 初期化
  for (int i = 0; i < 1010; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      dp[i][j] = INF;
    }
  }
  for (int i = 0; i < 3; i++)
  {
    dp[0][i] = 0;
  }
  
  // n=列数
  for (int i = 0; i < n; i++)
  {

    for (int pre_j = 0; pre_j < 3; pre_j++)
    {
      for (int j = 0; j < 3; j++)
      {
        if(pre_j == j) continue;
        int cnt = 0;
        char tem;
        if (j == 0)
        {
          tem = 'R';
        }
        else if (j == 1)
        {
          tem = 'B';
        }
        else if (j == 2)
        {
          tem = 'W';
        }
        for (int color = 0; color < 5; color++)
        { 
          if (tem != s[color][i]) cnt++;
        }
        chmin(dp[i + 1][j], dp[i][pre_j] + cnt);
      }
    } 
  }
  ll min_ans = INF;
  for (int i = 0; i < 3; i++)
  {
    chmin(min_ans, dp[n][i]);
  }

  cout << min_ans << endl;
  
  return 0;
}