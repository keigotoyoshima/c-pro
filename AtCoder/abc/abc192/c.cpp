#include <stdio.h>
#include <stdint.h>
#include<vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int g1(int x){
  string s = to_string(x);
  sort(s.begin(), s.end());

  return stoi(s);
}

int g2(int x){
  string s = to_string(x);
  sort(s.rbegin(), s.rend());

  return stoi(s);
}

int f(int x){
  return g1(x) - g2(x);
}

int main(){
  int n, k;
  cin >> n >> k;  
  while (k)
  {
    n = f(n);
    k--;
  }

  cout << n << endl;
  

  return 0;
}