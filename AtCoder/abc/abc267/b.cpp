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

  if(n0){
    int true_k = 0;
    int false_k = 0;
    bool pre_bool;
    for(int i = 0; i < 7; i++){
      bool c = col[i];
      if(true_k == 1 && false_k == 1 && c == false){
        cout << "Yes" << endl;
        return 0;
      }else if (false_k == 0 && c == false)
      {
        false_k ++;
      }else if(false_k == 1 && c == true){
        true_k ++;
      }
      
    }
  }else{
    cout << "No" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}