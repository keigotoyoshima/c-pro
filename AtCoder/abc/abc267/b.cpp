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





int main(){
  string S; cin >> S;
  vector<bool>col(7,false);
  bool n0 = false;
  if (S[0] == '0') n0 = true;
  if (S[6] == '0') 
    col[0] = true;
  if (S[3] == '0') 
    col[1] = true;
  if (S[7] == '0' && S[1] == '0')
    col[2] = true;
  if (S[4] == '0' && S[0] == '0')
    col[3] = true;
  if (S[8] == '0' && S[2] == '0')
    col[4] = true;
  if (S[5] == '0')
    col[5] = true;
  if (S[9] == '0')
    col[6] = true;
  

  // 1 or true = 倒れている, 0 or false = 立っている
  vector<int> data(3,-1);
  if(n0){
    for(int i = 0; i < 7; i++){
      bool current = col[i];
      if(data[0] == 0 && data[1] == 1 && current == false){
        cout << "Yes" << endl;
        return 0;
      }else if (data[0] == 0 && current == true)
      {
        data[1] = 1;
      }else if (data[0] == -1 && current == false){
        data[0] = 0;
      }
    }
  }else{
    cout << "No" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}