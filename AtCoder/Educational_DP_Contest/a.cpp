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

int main(){
  int n; cin >> n;
  vector<ll>h(n);
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }

  ll dp[100010];
  for (int i = 0; i < 100010; i++)
  {
    dp[i] = inf_ll;
  }
  
  dp[0] = 0;
  for (int i = 0; i < n; i++)
  {
    chmin(dp[i+1], dp[i] + abs(h[i+1] - h[i]));
    chmin(dp[i+2], dp[i] + abs(h[i+2] - h[i]));
  }


  cout << dp[n-1] << endl;
  return 0;
  
}