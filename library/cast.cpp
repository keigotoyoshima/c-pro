#include <stdio.h>
#include <stdint.h>
#include<vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>  
using namespace std;


int main(){
  int a = 1e6, b = 1e6;
  cout << a * b << endl;
  // -727379968
  long long c = a * b;
  cout << c << endl;
  // -727379968

  int p = 6, q = 4, k = 7;
  double d = (double)p / (double)q;
  cout << d << endl;
  // 1.5
  double e = (double)p / q;
  cout << e << endl;
  // 1.5
  double f = (double)(p / q);
  cout << f << endl;
  // 1


  double i = (double)p * (double)q / (double)k;
  cout << i << endl;
  // 3.42857

  double g = (double)p*q/k;
  cout << g << endl;
 // 3.42857

  double h = (double)(p*q/k);
  cout << h << endl;
  // 3





  return 0;
}