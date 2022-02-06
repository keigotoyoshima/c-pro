#include <algorithm>
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int main(){
  vector<int>v = {1,3,5,9,8,6,4,0};
  for (auto x: v)  cout << x << " ";
  cout << endl;
  // [&]はキャプチャ記法
  sort(v.begin(), v.end(), [&](int x, int y) { return ( x < y );});
  // xを&xとすると参照変数となり、書き換え可能。
  for (auto x: v)  cout << x << " ";
  cout << endl;
  return 0;
}