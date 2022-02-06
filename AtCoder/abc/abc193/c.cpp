#include <stdio.h>
#include <stdint.h>
#include<vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

const int Max = 200;

int main(){
  long long n;
  cin >> n;

  set<long long> st; 
      
  for (long long i = 2; i*i <= n; i++)
  {
    long long x = i*i;
    while (x<=n)
    {
      st.insert(x);
      x*=i;
    }

  }
  long long ans = n - st.size();
  cout << ans << endl;
  
  return 0;
}