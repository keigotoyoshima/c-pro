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


int main(){
  int n ; cin  >> n;
  vector<vector<int>>A(n);
  for (int i = 0; i < n; i++)
  {
    string input; cin >> input;
    for (int j = 0; j < input.size(); j++)
    {
      A[i].push_back(input[j]-'0');
    }
  }

  int maxValue = 0;
  int currentX;
  int currentY;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int temMax = maxValue;
      chmax(maxValue,A[i][j]);
      if(temMax != maxValue){
        currentX = i;
        currentY = j;
      }
    }
  }

  int next_current_x = currentX;
  int next_current_y = currentY;
  int next_x;
  int next_y;
  int pre_x;
  int pre_y;

  vector<int>ans;
  ans.push_back(maxValue);
  for (int i = 0; i < n-1; i++)
  {
    maxValue = 0;
    currentX = next_current_x;
    currentY = next_current_y;
  
    for (int j = 0; j < 8; j++)
    {
      next_x = (currentX + dx8[j] + n)%n;
      next_y = (currentY + dy8[j] + n)%n;
      if(next_x == pre_x && next_y == pre_y){
        continue;
      } 
      int temMax = maxValue;
      chmax(maxValue, A[next_x][next_y]);
      if(temMax != maxValue){
        next_current_x = next_x;
        next_current_y = next_y;
      }
     
    }
    pre_x = currentX;
    pre_y = currentY;
    ans.push_back(maxValue);
    
  }

  for(auto v: ans){
    cout << v;
  }
  cout << endl;
  
  return 0;
}