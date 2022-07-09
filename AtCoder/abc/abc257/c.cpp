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
  int n; cin >> n;
  string s; cin >> s;
  vector<ll>w(n);   
  for (int i = 0; i < n; i++)
  {
    cin >> w[i];
  }
  set<ll>everyone;
  vector<ll>child;
  vector<ll>adult;
  for (int i = 0; i < n; i++)
  {
    ll weight = w[i];
    char j = s[i];
    everyone.insert(weight);
    if(j == '0'){
      child.push_back(weight);
    }else{
      adult.push_back(weight);
    }
  }
  everyone.insert(INF);
  sort(child.begin(), child.end());
  sort(adult.begin(), adult.end());
  int sum = 0;
  for (auto v: everyone)
  {
    int ok_child = lower_bound(child.begin(), child.end(), v) - child.begin();
    int ok_adult = lower_bound(adult.begin(), adult.end(), v) - adult.begin();
    ok_adult = adult.size() - ok_adult;
    // cout << "ok_adult " << ok_adult << endl;
    // cout << "ok_child " << ok_child << endl;
    int tem = ok_adult + ok_child;
    chmax(sum, tem);
  }

  cout << sum << endl;
  
  return 0;
}