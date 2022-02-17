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
#include <math.h>
using namespace std;
using ll = long long;
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}
const long long INF = 1LL << 60;
const ll inf_ll = 1e15;
int inf_int = 2147483647;
using mpair = pair<int, int>;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};


int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];

  vector<vector<int>> dp(N, vector<int>(N, 0));
  // 残り[i,j]の状況からはじめたときのJOIくんの取り分の最大値

  // 初期化
  if (N % 2 == 1)
    for (int i = 0; i < N; i++)
      dp[i][i] = A[i];

  for (int i = 0; i < N; i++) {
  	for (int j = 0; j < N; j++)
  		cout << dp[i][j] << " ";
  	cout << endl;
  }

  for (int l = 2; l <= N; l++)
    for (int i = 0; i < N; i++)
    {
      int j = (i + l - 1) % N;
      // lが区間距離
      // iが左側でjが右側
      if (l % 2 == N % 2)
      // JOIのターン
        dp[i][j] = max(A[i] + dp[(i + 1) % N][j], A[j] + dp[i][(j + N - 1) % N]);
      else
      {
        // IOIのターン
        if (A[i] > A[j])
          dp[i][j] = dp[(i + 1) % N][j];
        else
          dp[i][j] = dp[i][(j + N - 1) % N];
      }
    }
  int ans = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cout << dp[i][j] << " ";
    cout << endl;
  }
  for (int i = 0; i < N; i++)
    ans = max(ans, dp[i][(i + N - 1) % N]);
  cout << ans << endl;

  return 0;
}