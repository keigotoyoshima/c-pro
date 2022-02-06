#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INFL = 1LL << 60;
const int inf = 1e6;

int n;
vector<int>memo;

int f(int x){
  if(x == 0) return 0;
  if(memo[x]) return memo[x];
  int res = inf;

  // 1の遷移
  chmin(res, f(x-1) + 1);

  int p = 6;
  // 6の遷移  
  while (x - p >= 0)
  {
    chmin(res, f(x-p) + 1);
    p *= 6;
  }

  p = 9;
  // 9の遷移
  while (x - p >= 0)
  {
    chmin(res, f(x-p) + 1);
    p *= 9;
  }


  return memo[x] = res;
}


int main(){

  cin >> n;
  memo.resize(n+1);
  cout << f(n) << endl;
  return 0;
}