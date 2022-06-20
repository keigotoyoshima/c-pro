#include <algorithm>
#include <iostream>
#include<vector>
#include <numeric>
#include <iostream>
#include <array>
using namespace std;

vector<int> a = {1, 3, 3, 2};
vector<int> b = {100, 105, 103, 104};

int main(){
  vector<int> v(a.size());
  // iotaで連番作成，第3引数は、v[0]の値．
  iota(v.begin(), v.end(), 0);


  // 二つの配列をもとにしてsortしたい場合
  // a配列で昇順sort，同一値の時は，b配列で昇順sort
  sort(v.begin(), v.end(), [&](auto l, auto r) {
    if(a[l] == a[r]){
      return b[l] < b[r];
    }else{
      return a[l] < a[r];
    }
  });

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
  // 0 3 2 1

  return 0;
}