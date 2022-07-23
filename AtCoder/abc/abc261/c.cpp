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





int main(){
  int n; cin >> n;
  vector<string>S(n);
  for (int i = 0; i < n; i++)
  {
    cin >> S[i];
  }

  map<string,int>mp;
  for (int i = 0; i < n; i++)
  {
    string tem = S[i];
    auto itr = mp.find(tem);
    if(itr != mp.end()){
      mp[tem] ++;
      cout << tem + "(" + to_string(mp[tem]) + ")" << endl;
    }else{
      mp[tem] = 0;
      cout << tem << endl;
    }
  }
  
  
  return 0;
}