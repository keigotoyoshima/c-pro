#include <stdio.h>
#include <stdint.h>
#include<vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>  
using namespace std;
using ll = long long;

int main(){
  string s;
  cin >> s;
  int ans = 0;

  for (int num = 0; num < 10000; num++)
  {
    int x = num;
    vector<int>a(10);


    for (int j = 0; j < 4; j++)
    {
      int d = x%10;
      a[d] = 1;
      x /= 10;
    }
    

    bool ok = true;

    for (int j = 0; j < 10; j++)
    {
      if(s[j] == 'o' && a[j] != 1) ok = false;
      if(s[j] == 'x' && a[j] != 0) ok = false;
    }
    
    if(ok) ans++;


    
  }

  cout << ans << endl;
  
  
  
  

  return 0;
}