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

vector<int>a;
vector<int>b;
vector<int>c;
ll dp[100100][3];

void tran(int i){
  // pは前日に何を選んだか．
  // kはi日目に何を選んだか．
  for (int p = 0; p < 3; p++)
  {
    for (int k = 0; k < 3; k++)
    {
      if(p == k) continue;
      if(k==0){
        chmax(dp[i+1][k], dp[i][p] + a[i]);
      }else if(k==1){
        chmax(dp[i+1][k], dp[i][p] + b[i]);
      }else{
        chmax(dp[i+1][k], dp[i][p] + c[i]);
      }
      
    }
  }
  

  
 
}

int main(){
  int n; cin >> n;
  a.resize(n);
  b.resize(n);
  c.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i] >> c[i];
  }
  // dp[i][b]の定義
  // i-1日目にbを選んだ時の，幸福度
  
  for (int i = 0; i < n; i++)
  {
    tran(i);
    tran(i);
    tran(i);
  }


  ll ans = 0;
  
  for (int i = 0; i < 3; i++)
  {
    chmax(ans, dp[n][i]);
  }
  cout << ans << endl;

  return 0;
}