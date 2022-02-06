#include <stdio.h>
#include <stdint.h>
#include<vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>  
#include <math.h>
using namespace std;	
using ll = long long;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s; 
  int q;
  cin >> q;
  int fl = 0;
  int n2 = 2*n;

  for (int i = 0; i < q; i++)
  {
    int t, a, b;
    cin >> t >> a >> b;
    --a;
    --b;
    // 反転されている場合
    if(t == 1){
      if(fl == 1) a = (a + n)%n2;
      if(fl == 1) b = (b + n)%n2;
      swap(s[a], s[b]);
    }else{
      //  一方のオペランドのビットが0で、もう一方のオペランドのビットが1の場合、対応する結果のビットは1に設定される。 それ以外の場合は、対応する結果ビットが 0 に設定される。
      fl ^= 1;  
    }
  }

  if(fl == 1){
    // １つめの引数の「開始位置」から２つめの引数の「長さ」で文字を返す。
    string s1 = s.substr(0, n);
    // １つめの引数の開始位置から最後までの文字を返す。
    string s2 = s.substr(n);

    s = s2 + s1;
  }
  
  cout << s << endl;
  

	return 0;
}
