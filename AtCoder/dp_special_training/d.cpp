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
using mpair = pair<int,int>;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

ll dp[110][100100];

int main(){
  ll n, w; cin >> n >> w;
  vector<int>wei(n);
  vector<int>val(n);
  for (int i = 0; i < n; i++)
  {
    cin >> wei[i] >> val[i];
  }
  // dp[i+1][w] = i番目にwを越えないようにval[i]を選んだ際の価値の総和
  

  for (int i = 0; i < n; i++)
  {
    for (int j = 0 ; j <=  w; j++)
    {
      chmax(dp[i+1][j], dp[i][j]);
      if(j-wei[i]>=0){
       chmax(dp[i+1][j], dp[i][j - wei[i]] + val[i]);
      }

    }
  }
  cout << dp[n][w] << endl;
  
  return 0;
}

