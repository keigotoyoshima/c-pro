#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INFL = 1LL << 60;
const int inf = 1e6;


int main(){
  double n; cin >> n;
  printf("%.3f", n/100);
  return 0;
}