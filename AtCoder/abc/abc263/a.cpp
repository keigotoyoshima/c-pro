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





int main(){
  map<int,int> mp;

  for(int i = 0; i < 5; i++){
    int tem; cin >> tem;
    mp[tem]++;
  }
  bool flag1 = false;
  bool flag2 = false;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    if(itr->second == 2){
      if(flag2) {
        cout << "Yes" << endl;
        return 0;
      }
      flag1 = true;
    }else if(itr->second == 3){
      if(flag1){
        cout << "Yes" << endl;
        return 0;
      }
      flag2 = true;
    }else{
      cout << "No" << endl;
      return 0;
    }
  }
  return 0;
}