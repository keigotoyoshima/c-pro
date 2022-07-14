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
#include <math.h>
#include <string>
#include <assert.h>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};




// abbaac
// abbbbaaaaac
// abbbc
// abc
int main(){
  string S,T; cin >> S >> T;
  bool flag = true;
  int s_index = 0;
  int originl_size = S.size();
  if(S.size() < T.size()){
    int len = T.size()-S.size();
    for (int i = 0; i < len; i++)
    {
      S += 'S';
    }
    
  }
  // cout << "S " << S << endl; 
  for (int i = 0; i < T.size(); i++)
  {
    // cout << "s_index " << s_index << endl;
    if(s_index >= S.size()){
      flag = false;
      break;
    }
    char s = S[s_index];
    char t = T[i];
    if(s != t){
      
      if(t == T[i-1]){
        if (S[s_index - 2] != t || S[s_index - 1] != t)
        {
          // cout << "s_index false " << s_index << endl;
          flag = false;
          break;
        }
        s_index--;
      }else{
        flag = false;
        break;
      }

    }
    s_index++;
  }
  if(s_index <= originl_size-1){
    flag = false;
  }
  if(flag){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}