#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int>a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  
  int res = 1<<30;
  for (int bit = 0; bit < (1<<(n-1)); bit++)
  {
    int ored = 0;
    int xored = 0;
    for (int i = 0; i < n; i++)
    {
      ored |= a[i];
      if(bit>>i & 1){
        xored ^= ored;
        ored  = 0;
      }
    }
    xored ^= ored;
    res = min(res, xored);
  }

  cout << res << endl;
  

  


  return 0;
}
