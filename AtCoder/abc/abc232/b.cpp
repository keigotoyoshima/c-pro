#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INFL = 1LL << 60;
const int inf = 1e6;

int main(){
  string s; cin >> s;
  string t; cin >> t;
  int a = s[0];
  int b = t[0];
  int k = a - b;
  if(k < 0) k = s[0] + 26 - t[0];

  for (int i = 1; i < s.size(); i++)
  {
   int tem = s[i] - t[i];
   
   if(tem < 0) tem = s[i] + 26 - t[i];

   if(k != tem) {
     cout << "No" << endl;
     return 0;
   }
  }
  cout << "Yes" << endl;
  return 0;
  // string s = "abz";
  // int a = s[0];
  // int b = s[1];
  // int c = s[2];
  // cout << a << " " << b << " " << c << endl;
  
  return 0;
}