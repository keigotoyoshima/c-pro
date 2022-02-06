#include <iostream>
#include <vector>
#include <queue>
#include <deque>  
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool solve(string s){
  vector<int>v(10);
  for(auto c: s) v[c - '0']++;
  if(s.size() == 1){
    if(stoi(s) == 8) return 1;
  }else if(s.size() == 2){
    swap(s[0],s[1]);
    if(stoi(s)%8 == 0){
      return 1;
    } else if(stoi(s)%8 == 0){
      return 1;
    }
  }else{
    for (int i = 104; i < 1000; i+=8)
    {
      auto k = v;
      for(auto c : to_string(i)) k[c - '0']--;
      if(all_of( k.begin(), k.end(), [](int x){return x >= 0;} )) return 1;
    }
    return 0;
  }
  return 0;
}


int main() {
  string s;
  cin >> s;
  string ans;
  ans = (solve(s) ? "Yes" : "No");
  cout << ans << endl;
  return 0;
}