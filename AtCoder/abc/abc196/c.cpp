#include <stdio.h>
#include <stdint.h>
#include<vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

long long f(long long x){
  string s = to_string(x);
  return stoll(s+s);
}

int main(){
  long long n;
  cin >> n;
  long long x = 1;
  while (f(x) <= n)
  {
    x++;
  }
  long long ans = x - 1;

  cout << ans << endl;
  

  return 0;
}