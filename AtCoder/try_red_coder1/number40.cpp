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
  int n, k; cin >> n >> k;
  vector<int>p(n,{0,1,2});
  for (int i = 0; i < k; i++)
  {
    int a,b; cin >> a >> b;
    p[a-1] = {b-1};
  }

  ll dp[101][4][4];

  
  // dp[0][0][0] = 1;
  for(auto v: p){
    dp[1][v][3] = 1;
  }
  
  

  for (int i = 0; i < n; i++)
  {
    for (int a = 0; a < 3; a++)
    {
      for (int b = 0; b < 3; b++)
      {
        // i日目のパスタの候補
        vector<int>ct={0,1,2};
        if(p[i] >= 0) ct ={p[i]};
        for(auto c: ct){
          // i日目に選ぶパスタの種類c
          if(a == b && b == c) continue;
          dp[i+1][b][c] += dp[i][a][b];

          
          
          dp[i+1][b][c] %= 10000;
        }
      }
      
    }
    
  }
  ll ans = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      ans = (ans+dp[n][i][j]) % 10000;
    }
    
  }
  cout <<  ans << endl;
  return 0;
}