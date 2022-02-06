#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>   
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INFL = 1LL << 60;
const int inf = 1e6;


int main(){
  int n; cin >> n;
  map<string, int> mp; 
  for (int i = 0; i < n; i++)
  {
    string s; cin >> s;
    if( mp.find(s) != mp.end() ) {
      mp[s] = mp[s] + 1;
      
    } else {
      mp[s] = 1;
    }
  }
  int res = 0;
  string ans = "";
  for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
    int tem = res;
    res = max(res, itr->second);
    if(res != tem){
      ans = itr->first;
    }
  }
  // cout << endl;
  // for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
  //   std::cout << "key = " << itr->first           // キーを表示
  //                       << ", val = " << itr->second << "\n";    // 値を表示
  // }



  cout << ans << endl;
  return 0;
}