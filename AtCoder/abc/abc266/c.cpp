#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
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
#include <functional>
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




// counter clock wise
// clock wise = 時計回り
// counter clock wise = 反時計回り
int main(){
  vector<pair<int,int>>V;
  for (int i = 0; i < 4; i++)
  {
    int x,y; cin >> x >> y;
    V.push_back(make_pair(x,y));
  }
  vector<pair<int, int>> A;
  pair<int,int> B;
  pair<int, int> C;
  for (int i = 0; i < 4; i++)
  {
    if(i == 0 || i == 2){
      A.push_back(V[i]);
    }if else if(i == 1){
      B = V[i];
    }else{
      C = V[i];
    }
  }
  // int a = A[0].second - A[2].second;
  int a = A[2].second - A[0].second;
  int b = A[2].first - A[0].first;
  
  
  
  
  return 0;
}