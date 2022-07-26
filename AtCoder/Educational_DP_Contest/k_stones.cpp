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




int dp[110000];
// dp[i] = 残りi個の石が残っているときに，先手が勝てるかどうか（1==勝ち,0==負け)
int main(){
  int n, k; cin >> n >> k;
  vector<ll>a(n);
  
  for(auto &v : a) cin >> v;

  for (int i = 1; i < k+1; i++)
  {
    dp[i] = 0;
    for (int j = 0; j < n; j++)
    {
      if(i-a[j] >= 0 && dp[i-a[j]]==0) dp[i] = 1;
    }
  }

  if(dp[k]){
    cout << "First" << endl;
  }else{
    cout << "Second" << endl;
  }
  

  return 0;
}